%% 4-state UKF used in the second phase of the hybrid balancing scheme for balancing the r z component.
clc
clear




tf = 50;          % simulation length [s]
n  = 4;            % number of states
alpha   = 1e-3;         % small, positive
kappa   = 0;            % usually 0
beta    = 2;            % optimal for Gaussian
lambda  = alpha^2*(n+kappa) - n;


% Test-bed characteristics 
m_s = 29; % [kg]
J = [1.815  0 0;
      0  1.348  0;
       0  0 1.475];
% r_0 = [0.1*10^-3, 0.1*10^-3 ,-1*10^-3]';
r_0 = [-0.003 0.006 -0.010]';
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
sample_rate = 25; % IMU sample rate
sample_time = 1/sample_rate; % IMU sample period


% Filter matrices
R = diag([0.005 0.005 0.005].^2);      % measurement-noise covariance
H = [eye(3)  zeros(3,5)];             % measurement matrix

Q  = diag([5e-5 5e-5 5e-5 4e-12 4e-12 4e-12 4e-12 5e-6]);

omega_0 = [0 0.00 0.05]';
% omega_0 = [0.50 0.10 0.30]';

EA_0 = deg2rad([10 3 6]'); 

% transformations are inertial to body
% XYZ rotation order must be explicitly specified
q_0 = eul2quat(EA_0',"XYZ")'; 

x_0 = [omega_0; q_0; 0];
n = size(x_0,1);
P_0 = diag([1e-6 1e-6 1e-6 1e-6 1e-6 1e-6 1e-6 1e-6]);


