clc
clear

raw_data_dir = 'RW_spinup_140s';
load(raw_data_dir)

sampleRate = 10;
sampleTime = 1/sampleRate;

numFrames = size(capturedFrames,2);
t = linspace(0,(numFrames-1)*sampleTime,numFrames);

eulerAngles = zeros(numFrames,3);
bodyRates = zeros(numFrames,3);
stepperPos = zeros(numFrames,2);

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

    eulerAngles(i,:) = [roll pitch yaw];
    bodyRates(i,:) = [omega_x omega_y omega_z];
    stepperPos(i,:) = [pos_x pos_y];
end

% shift t = 0 to RW startup, cutoff data at RW poweroff
test_length = 139.425;
t_start = 33.6;
t_end = t_start + test_length;

start_index = find(t > t_start,1,'first');
end_index = find(t > t_end, 1, 'first');
t = t(start_index:end_index) - t(start_index);

eulerAngles = eulerAngles(start_index:end_index,:);
bodyRates = bodyRates(start_index:end_index,:);




subplot(3,1,1)
plot(t,eulerAngles(:,1:2),'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Euler Angles [deg]")
legend("Roll","Pitch")

subplot(3,1,2)
plot(t,bodyRates(:,3),'LineWidth',1.5)
grid on
xlabel("Time [s]")
ylabel("Body Rates [deg/s]")
legend("\omega_z")

