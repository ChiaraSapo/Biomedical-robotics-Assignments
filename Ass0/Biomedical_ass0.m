%% Biomedical robotics --- Assignment 0
    % Aurora Bertino S4399133
    % Chiara Saporetti S4798994
    % Gabriele Reverberi S3665543
    % Sara Romano S4802844


close all
clear all
clc

%% Given data

% Load data
Data1 = load('data1.mat');
Data2 = load('data2.mat');
Data3 = load('data3.mat');

% Given frequences
Freq1=2000;
Freq2=166;
Freq3=250;

%% Computations for Data1
x1=(1:length(Data1))/Freq1;

%% Computations for Data2
x2=(1:length(Data2))/Freq2;

%% Computations for Data3
x3=(1:length(Data3))/Freq3;

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

figure(1),title(['EMG signals']),xlabel('Time [s]'),ylabel('EMG [μV]') %HP
hold on
plot(x1,Data1.data1)

%% Plots for data2

% We think this data represents movement data. At a first glance we thought
% it could represent the movement of two different arm positions, for
% example, but then we realized it could be two differentplanar
% coordinates. By plottting them we obtained the second plot, which clearly
% resembles a simple planar trajectory that a person or manipulator could
% perform.

% Plot the data
figure(2),subplot(1,2,1),title(['Movement signals']),xlabel('Time [s]'),ylabel('Movement [mm]')
hold on
plot(x2,Data2.data2(1,:))
hold on
plot(x2,Data2.data2(2,:))
legend('x','y')

% Plot the movement
figure(2),subplot(1,2,2),title(['Movement along X and Y axes']),xlabel('X [mm]'),ylabel('Y [mm]')
hold on
plot(Data2.data2(1,:),Data2.data2(2,:))

%% Plots for data3

% We think this data represents EEG signals of a single brain wave.
% A typical adult human EEG signal is about 1/2 up to 40/50 Hz
% We interpreted the unit of measure as nV for this reason, since values 
% stay approximately in the interval [-19200,-18500].

figure(3),title(['EEG signals']),xlabel('Time [s]'),ylabel('EEG [μV]')
hold on
plot(x3,Data3.data3)
