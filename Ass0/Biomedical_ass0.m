%% Biomedical robotics --- Assignment 0
    % Aurora Bertino S4399133
    % Chiara Saporetti S4798994
    % Gabriele Reverberi S3665543
    % Sara Romano S4802844


% close all
% clear all
% clc

%% Given data

% Load data
load('data1.mat');
load('data2.mat');
load('data3.mat');

% Given frequences
Freq1=2000;
Freq2=166;
Freq3=250;

%% Computations for Data1
x1=(1:length(data1))/Freq1;

%% Computations for Data2
x2=(1:length(data2))/Freq2;

%% Computations for Data3
x3=(1:length(data3))/Freq3;

%% Below are shown the plots of the given data.
%% Plots are in time domain and range from zero to the Sampling Period T 
%% calculated for each frequency.

%% Plots for data1

% We think this data represents EMG signals in which the muscle is repeatedly
% contracted and extended. 
% Measured EMG potentials range between less than 50 μV and up to 30 mV, 
% depending on the muscle under observation. We interpreted the unit of 
% measure as μV for this reason, since values stay approximately in the 
% interval [-400,+500].

figure
title('EMG signals')
xlabel('Time [s]'),ylabel('EMG [μV]')
hold on
plot(x1/60,data1)

%% Plots for data2

% We think this data represents movement data. At a first glance we thought
% it could represent the movement of two different arm positions, for
% example, but then we realized it could be two differentplanar
% coordinates. By plottting them we obtained the second plot, which clearly
% resembles a simple planar trajectory that a person or manipulator could
% perform.

% Plot the data
figure
subplot(1,2,1)
title('Movement signals')
xlabel('Time [s]'),ylabel('Movement [cm]')
hold on
plot(x2,data2(1,:))
plot(x2,data2(2,:))
legend('x','y')

% Plot the movement
subplot(1,2,2)
title('Movement along X and Y axes')
xlabel('X [cm]'),ylabel('Y [cm]')
plot(data2(1,:),data2(2,:))

%% Plots for data3

% We think this data represents EEG signals of a single brain wave.
% A typical adult human EEG signal is about 1/2 up to 40/50 Hz
% We interpreted the unit of measure as nV for this reason, since values 
% stay approximately in the interval [-19200,-18500].

figure
title('EEG signals')
xlabel('Time [s]'),ylabel('EEG [μV]')
scalingFactor=1/1000;
plot(x3,data3*scalingFactor)
