port = "COM11";  baud = 9600;
s    = serialport(port, baud);
flush(s);

SYNC  = uint8(0xAA);
FRAME = 39;

sampleRate = 10;

% tiny hidden figure just to get KeyPsressFcn callbacks
hFig = figure( ...
    'MenuBar','none','ToolBar','none','NumberTitle','off', ...
    'Visible','on', ...
    'KeyPressFcn',@(src,evt)setappdata(src,'key',evt.Key));
title("Collecting data... press 's' to stop and save results")
setappdata(hFig,'key','');      % initialise with empty key

% ---------- pre-allocate storage --------------------------------------
chunk      = 5e3;               % grow in blocks of 5 000 frames
frames     = zeros(FRAME,chunk,'uint8');
frameCount = 0;

while true
    if read(s,1,"uint8") ~= SYNC, continue; end           % wait for sync
    pl  = read(s, FRAME-1, "uint8");                      % 32-byte payload

    raw = [SYNC pl];     % -------- full 33-byte frame --------

    % ----------- store it ------------------------------------------
    frameCount = frameCount + 1;
    if frameCount > size(frames,2)                   % need more space?
        frames(:,end+1:end+chunk) = 0;               % grow matrix
    end
    frames(:,frameCount) = raw;

    roll = typecast(raw(2:5),'single');
    pitch = typecast(raw(6:9),'single');
    trq = typecast(raw(38:39),'int16');

    % ------------- print raw bytes in HEX ---------------------
    fprintf('Cnt: %d, Trq: %d, Roll: %.2f, Pitch: %.2f, RAW: %s\n', frameCount, trq, roll, pitch, sprintf('%02X ', raw));

    % ----------- check keyboard ------------------------------------
    drawnow;

    key = getappdata(hFig,'key');
    if strcmp(key,'s')                               % user pressed “s”
        break
    end
    % clear key so next loop iteration doesn’t see the same key again
    if ~isempty(key);  setappdata(hFig,'key','');  end
end

% ---------- shutdown & save ------------------------------------------
filename = sprintf('serial_%s.mat', datetime('today'));
capturedFrames = frames(:,1:frameCount);             %# trim unused cols
save(filename,'capturedFrames', 'sampleRate');
fprintf('Saved %d frames to %s\n', frameCount, filename);

clear s                                           % closes the port
delete(hFig)

%% Plot data and visually inspect for a good starting point
clc
clear
raw_data_dir = 'passive_runs/June07_passive_8.mat';
load(raw_data_dir)
% load('serial_23-May-2025.mat')

sampleTime = 1/sampleRate;

numFrames = size(capturedFrames,2);
t = linspace(0,(numFrames-1)*sampleTime,numFrames);

eulerAngles = zeros(numFrames,3);
bodyRates = zeros(numFrames,3);
stepperPos = zeros(numFrames,2);
wheel_vel = zeros(numFrames,1);
wheel_trq = zeros(numFrames,1);


% unpacking data...
for i = 1:numFrames % <---  REMEMBER TO INCLUDE/NOT INCLUDE RW WHEEL DATA HERE!!
    currentFrame = capturedFrames(:,i)';
    
    roll = typecast(currentFrame(2:5),'single');
    pitch = typecast(currentFrame(6:9),'single');
    yaw = typecast(currentFrame(10:13),'single');
    
    omega_x = typecast(currentFrame(14:17),'single');
    omega_y = typecast(currentFrame(18:21),'single');
    omega_z = typecast(currentFrame(22:25),'single');
    
    pos_x = typecast(currentFrame(26:29),'int32');
    pos_y = typecast(currentFrame(30:33),'int32');

    wheel_vel(i) = typecast(currentFrame(34:37),'int32');
    wheel_trq(i) = typecast(currentFrame(38:39),'int16');

    eulerAngles(i,:) = [roll pitch yaw];
    bodyRates(i,:) = [omega_x omega_y omega_z];
    stepperPos(i,:) = [pos_x pos_y];
end

figure

subplot(4,1,1)
plot(t,eulerAngles(:,1:2),'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Euler Angles [deg]")
legend("Roll","Pitch")

subplot(4,1,2)
plot(t,bodyRates(:,1:3),'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Body Rates [deg/s]")
legend("\omega_z")

subplot(4,1,3)
plot(t,stepperPos,'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Stepper Positions")
legend("Stepper X","Stepper Y")

subplot(4,1,4)
plot(t,wheel_vel,'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Reaction Wheel speed")


%% export data in simulink-compatible format (saves in export_for_simulink)

clc

% MAKE SURE TO SET THE CORRECT FILE IN SIMULINK AS WELL
name = 'placeholder';
t_start = 0; % <------ set a proper cutoff point
start_index = find(t > t_start,1,'first');

t_new = t(start_index:end) - t(start_index);
t_final = t_new(end);
n = size(t_new,2);

output = zeros(n,9);

output(:,1) = t_new;

format long g
output(:,2:4) = eulerAngles(start_index:end,:);
output(:,5:7) = bodyRates(start_index:end,:);
output(:,8:9) = stepperPos(start_index:end,:);

output = output';

save(strcat('export_for_simulink/',name),'output')

%% 4-state UKF used in the second phase of the hybrid balancing scheme for balancing the r z component.


data_path = 'export_for_simulink/May_27_UKF_4.mat';
load(data_path)
data_path = fullfile(pwd,data_path);
set_param('SADS_UKF/From File', 'FileName', data_path);  
t_final = size(output,1)*10;

% EKF Hyperparameters
n = 8;
alpha   = 1e-3;         % small, positive
kappa   = 0;            % usually 0
beta    = 2;            % optimal for Gaussian
lambda  = alpha^2*(n+kappa) - n;


% Test-bed characteristics 
m_s = 28.542; % [kg]
J = [1.301  0 0;
      0  1.023  0;
       0  0 1.253];
% r_0 = [0.1*10^-3, 0.1*10^-3 ,-1*10^-3]';
r_0 = [-0.003 0.006 -0.005]';
g_N = [0 0 -9.81];

% for simulating plant ("truth")
process_variance = 1e-5; % variance of disturbance torques
% "sample time" for process noise, must be much shorter than the timescale of
% the system dynamics
T_s = 0.01; 
process_PSD = (process_variance^2)*T_s;

% for simulating IMU
noise_power = 5.235988e-5; % [rad/s/sqrt(Hz)] provided on sensor datasheet
sensor_PSD = noise_power^2; % IMU power spectral density
sample_rate = 10; % IMU sample rate
sample_time = 1/sample_rate; % IMU sample period


% Filter matrices
R = diag([0.005 0.005 0.003].^2);      % measurement-noise covariance
H = [eye(3)  zeros(3,5)];             % measurement matrix

% [omega, q, r_z]
Q  = diag([5e-5 5e-5 5e-5 4e-11 4e-11 4e-11 4e-11 4e-13]);

% setting initial conditions for the filter
omega_0 = output(5:7,1);
EA_0 = deg2rad(output(2:4,1));

% transformations are inertial to body
% XYZ rotation order must be explicitly specified
q_0 = eul2quat(EA_0',"XYZ")'; 
x_0 = [omega_0; q_0; -0.001];

n = size(x_0,1);
P_0 = diag([1e-6 1e-6 1e-6 1e-6 1e-6 1e-6 1e-6 1e-6]);

out = sim('SADS_UKF.slx');

disp(squeeze(out.r_z_est.signals.values(end)))

figure
subplot(2,1,1)
yline(0)
hold on
plot(out.r_z_est.time,squeeze(out.r_z_est.signals.values),'LineWidth',1.5)
grid on
xlabel('Time [s]')
title('r_z Estimate')

subplot(2,1,2)
yline(0)
hold on
plot(out.sigma_r_z.time,squeeze(out.sigma_r_z.signals.values),'LineWidth',1.5)
grid on
xlabel('Time [s]')
title('r_z Covariance')

ball_screw_wt = 0.177;
plate_wt = 0.236;

vertical_mass = ball_screw_wt + 2*plate_wt;
num_rot = r_to_rotations(0.0001,vertical_mass,num_sliders,m_s)';


function num_rot = r_to_rotations(r_z,sliderWeight,total_mass)
    screw_pitch = 0.010;      % mm / rev   (== 0.010 mm per rev)

    % How far the slider itself must move
    delta_z = (r_z * total_mass) / sliderWeight;

    % Revolutions required
    num_rot = delta_z / screw_pitch;
end