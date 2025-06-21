clc
clear

% Test-bed characteristics 
m_s = 28.542; % [kg]
J = [1.301  0 0;
      0  1.023  0;
       0  0 1.253];

raw_data_dir = 'verification_runs/hybrid_verification4.mat';
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
for i = 1:numFrames
    currentFrame = capturedFrames(:,i)';
    
    roll = typecast(currentFrame(2:5),'single');
    pitch = typecast(currentFrame(6:9),'single');
    yaw = typecast(currentFrame(10:13),'single');
    
    omega_x = typecast(currentFrame(14:17),'single');
    omega_y = typecast(currentFrame(18:21),'single');
    omega_z = typecast(currentFrame(22:25),'single');
    
    pos_x = typecast(currentFrame(26:29),'int32');
    pos_y = typecast(currentFrame(30:33),'int32');

    % wheel_vel(i) = typecast(currentFrame(34:37),'int32');
    % wheel_trq(i) = typecast(currentFrame(38:39),'int16');

    eulerAngles(i,:) = [roll pitch yaw];
    bodyRates(i,:) = [omega_x omega_y omega_z];
    stepperPos(i,:) = [pos_x pos_y];
end


figure
plot(t,eulerAngles(:,1:2)) % optionally plot raw data
t_start = 15; % <------ set a proper cutoff point
start_index = find(t > t_start,1,'first');

t_end = 88; % <--------
end_index = find(t > t_end,1,'first');

t = t(start_index:end_index) - t(start_index);

eulerAngles = eulerAngles(start_index:end_index,:);
bodyRates = bodyRates(start_index:end_index,:);

ang_accel = zeros(length(t),3);
vel_x = bodyRates(:,1);

% Design a FIR filter to differentiate --------------------------------
figure
pwelch(vel_x,[],[],[],sampleRate)
Fpass = 0.05;
Fstop = 0.3;
Fs = sampleRate;

d = designfilt('differentiatorfir', ...
    'PassbandFrequency', Fpass, ...
    'StopbandFrequency', Fstop, ...
    'FilterOrder',100, ... 
    'SampleRate', Fs);


% zerophase(d,[],Fs)

accel_x = filter(d,vel_x)/sampleTime;
delay = mean(grpdelay(d));

t_d = t(1:end-delay);

accel_x_d = accel_x;
accel_x_d(1:delay) = [];

t_d(1:delay) = [];
accel_x_d(1:delay) = [];


figure
subplot(2,1,1)
plot(t,vel_x)
xlabel('Time (s)')
ylabel('Angular Velocity [rad/s]')
xlim([t_d(1) t_d(end)])
grid

subplot(2,1,2)
plot(t_d,accel_x_d)
xlabel('Time (s)')
ylabel('Angular Acceleration [rad/s]')
yline(0)
xlim([t_d(1) t_d(end)])
grid


%%
ang_accel(:,1) = gradient(bodyRates(:,1),sampleTime);
ang_accel(:,2) = gradient(bodyRates(:,2),sampleTime);
ang_accel(:,3) = gradient(bodyRates(:,3),sampleTime);

torque = zeros(length(t),3);
torque_norm = zeros(length(t),1);
for i = 1:length(t)
    omega = bodyRates(i,:)';
    omegaDot = ang_accel(i,:)';
    % torque(i,:) = J*omegaDot + cross(omega,J*omega);
    torque(i,:) = J*omegaDot;
    torque_norm(i) = norm(torque(i,:));
end

figure
subplot(4,1,1)
plot(t,eulerAngles(:,1:2),'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Euler Angles [deg]")
legend("Roll","Pitch")

subplot(4,1,2)
plot(t,bodyRates(:,:),'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Body Rates [rad/s]")
legend("\omega_x", "\omega_y", "\omega_z")

subplot(4,1,3)
plot(t,ang_accel,'LineWidth',1.3)
xlabel("Time [s]")
ylabel("Torque")
legend("T")
grid on

subplot(4,1,4)
plot(t,torque,'LineWidth',1.3)
xlabel("Time [s]")
ylabel("Torque")
legend("T_x","T_y","T_z")
grid on
