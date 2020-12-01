%% Biomedical robotics --- Assignment 2
    % Aurora Bertino S4399133
    % Chiara Saporetti S4798994
    % Gabriele Reverberi S3665543
    % Sara Romano S4802844
    
clear all;
clc;
close all; 
addpath('Functions')
addpath('Data')


%% 1_point: Load EMG_data %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Data1 = load('EMG_data_VEEL.mat'); 
EMG.Event = double(Data1.EMG_data(1,:)); %1='Cue', 2='Go'. 
EMG.Right_Biceps = Data1.EMG_data(2,:); %EMG signal of Right Bicips
EMG.Triceps = Data1.EMG_data(3,:); %EMG signal of Triceps


%% 2_point %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Given data
Fs    = 1000; % Sampling Frequency 
Ts    = 1/Fs; % Sampling Interval 
Freq1 = 30;   % Passband Frequency, Hz (Lower)
Freq2 = 450;  % Passband Frequency, Hz (Upper)

% Our data
dFs   = 100;  % Down sampled Frequency (1/10 * Fs)
Fenv  = 5;    % Envelope Frequency
Fnyq  = Fs/2; % Nyquist Frequency
N = 10; % FIR filter order

% Computations on data
W = (1/Fnyq) * [Freq1, Freq2]; %Bandpass frequency
dsFactor = round(Fs / dFs); % Down sampling factor

% Preprocess the whole EMG data set 
[EMG_Bicep] = Preprocessing(EMG.Right_Biceps, N, W, Fenv, Fnyq, dsFactor, Fs);
[EMG_Tricep] = Preprocessing(EMG.Triceps, N, W, Fenv, Fnyq, dsFactor, Fs);


%% 3_Point: load kinem data %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Data2 = load('kinem_VEEL.mat'); 
Kinem.time = Data2.kinem_data(1,:)'; 
Kinem.event = Data2.kinem_data(2,:)'; 
Kinem.xcursor = Data2.kinem_data(3,:)'; 
Kinem.ycursor = Data2.kinem_data(4,:)'; 
Kinem.xtarget = Data2.kinem_data(5,:)'; 
Kinem.ytarget = Data2.kinem_data(6,:)';


%% 4_point : segmentation sets %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Cue indexes in EMG data
Indexes_EMG_cue = find(Data1.EMG_data(1,:) == 1); 

%% Segmentation of EMG data
%Biceps
set1EMG_Bicep.data = EMG_Bicep.data(:, 1:Indexes_EMG_cue(1,96)); 
set1EMG_Bicep.t = EMG_Bicep.t(:, 1:Indexes_EMG_cue(1,96));
set1EMG_Bicep.smooth = EMG_Bicep.smooth(:, 1:Indexes_EMG_cue(1,96));

%Tricep
set1EMG_Tricep.data = EMG_Tricep.data(:, 1:Indexes_EMG_cue(1,96)); 
set1EMG_Tricep.t = EMG_Tricep.t(:, 1:Indexes_EMG_cue(1,96));
set1EMG_Tricep.smooth = EMG_Tricep.smooth(:, 1:Indexes_EMG_cue(1,96));

%Bicep
set2EMG_Bicep.data = EMG_Bicep.data(:,Indexes_EMG_cue(1,481):Indexes_EMG_cue(1,576)); 
set2EMG_Bicep.t = EMG_Bicep.t(:,Indexes_EMG_cue(1,481):Indexes_EMG_cue(1,576));
set2EMG_Bicep.smooth = EMG_Bicep.smooth(:,Indexes_EMG_cue(1,481):Indexes_EMG_cue(1,576));

%Tricep
set2EMG_Tricep.data = EMG_Tricep.data(:,Indexes_EMG_cue(1,481):Indexes_EMG_cue(1,576)); 
set2EMG_Tricep.t = EMG_Tricep.t(:,Indexes_EMG_cue(1,481):Indexes_EMG_cue(1,576));
set2EMG_Tricep.smooth = EMG_Tricep.smooth(:,Indexes_EMG_cue(1,481):Indexes_EMG_cue(1,576));

%Bicep
set3EMG_Bicep.data = EMG_Bicep.data(:,Indexes_EMG_cue(1,865):Indexes_EMG_cue(1,960)); 
set3EMG_Bicep.t = EMG_Bicep.t(:,Indexes_EMG_cue(1,865):Indexes_EMG_cue(1,960));
set3EMG_Bicep.smooth = EMG_Bicep.smooth(:,Indexes_EMG_cue(1,865):Indexes_EMG_cue(1,960));

%Tricep
set3EMG_Tricep.data = EMG_Tricep.data(:,Indexes_EMG_cue(1,865):Indexes_EMG_cue(1,960)); 
set3EMG_Tricep.t = EMG_Tricep.t(:,Indexes_EMG_cue(1,865):Indexes_EMG_cue(1,960));
set3EMG_Tricep.smooth = EMG_Tricep.smooth(:,Indexes_EMG_cue(1,865):Indexes_EMG_cue(1,960));

%Bicep
set4EMG_Bicep.data = EMG_Bicep.data(:,Indexes_EMG_cue(1,961):Indexes_EMG_cue(1,1056)); 
set4EMG_Bicep.t = EMG_Bicep.t(:,Indexes_EMG_cue(1,961):Indexes_EMG_cue(1,1056));
set4EMG_Bicep.smooth = EMG_Bicep.smooth(:,Indexes_EMG_cue(1,961):Indexes_EMG_cue(1,1056));

%Tricep
set4EMG_Tricep.data = EMG_Tricep.data(:,Indexes_EMG_cue(1,961):Indexes_EMG_cue(1,1056)); 
set4EMG_Tricep.t = EMG_Tricep.t(:,Indexes_EMG_cue(1,961):Indexes_EMG_cue(1,1056));
set4EMG_Tricep.smooth = EMG_Tricep.smooth(:,Indexes_EMG_cue(1,961):Indexes_EMG_cue(1,1056));

%% Cue indexes in motion data
j=1;
for i=1:size(Data2.kinem_data,2)-1
    if Data2.kinem_data(2,i)-Data2.kinem_data(2,i+1)~=0
        Indexes_Kinem_cue(j)=i;
        j=j+1;
    end
end

%% Segmentation of Motion data
set1.kinem = Data2.kinem_data(:,(1:Indexes_Kinem_cue(1,96))); 
set2.kinem = Data2.kinem_data(:,Indexes_Kinem_cue(1,481):Indexes_Kinem_cue(1,576)); 
set3.kinem = Data2.kinem_data(:,Indexes_Kinem_cue(1,865):Indexes_Kinem_cue(1,960)); 
set4.kinem = Data2.kinem_data(:,Indexes_Kinem_cue(1,961):Indexes_Kinem_cue(1,1056)); 


%% Plot Set1
f = figure('units','normalized','outerposition',[0 0 1 1], 'visible', 'off');

subplot(2,2,1)
hold on; 
plot(set1EMG_Bicep.t, set1EMG_Bicep.data); % bicep
plot(set1EMG_Bicep.t, set1EMG_Bicep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Bicep EMG of subset 1');

subplot(2,2,2)
hold on; 
plot(set1EMG_Tricep.t, set1EMG_Tricep.data); %tricep
plot(set1EMG_Tricep.t, set1EMG_Tricep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Tricep EMG of subset 1');

subplot(2,2,3)
plot(set1.kinem(3,:), set1.kinem(4,:)) % x y
xlabel('x'); 
ylabel('y');
title('x,y subset 1');

subplot(2,2,4)
plot(Kinem.time(1:Indexes_Kinem_cue(1,96)), set1.kinem(3,:)) % x, y time
hold on
plot(Kinem.time(1:Indexes_Kinem_cue(1,96)), set1.kinem(4,:)) 
xlabel('Time (ms)'); 
ylabel('x,y');
legend('x', 'y');
title('x,y wrt time subset 1');

saveas(f, ['Results/' 'Subset1.jpg']);

%% Plot Set 2
f = figure('units','normalized','outerposition',[0 0 1 1], 'visible', 'off');

subplot(2,2,1)
hold on; 
plot(set2EMG_Bicep.t, set2EMG_Bicep.data); % bicep
plot(set2EMG_Bicep.t, set2EMG_Bicep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Bicep EMG of subset 2');

subplot(2,2,2)
hold on; 
plot(set2EMG_Tricep.t, set2EMG_Tricep.data); %tricep
plot(set2EMG_Tricep.t, set2EMG_Tricep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Tricep EMG of subset 2');

subplot(2,2,3)
plot(set2.kinem(3,:), set2.kinem(4,:)) % x y
xlabel('x'); 
ylabel('y');
title('x,y subset 2');

subplot(2,2,4)
plot(Kinem.time(Indexes_Kinem_cue(1,481):Indexes_Kinem_cue(1,576)), set2.kinem(3,:)) % x, y time
hold on
plot(Kinem.time(Indexes_Kinem_cue(1,481):Indexes_Kinem_cue(1,576)), set2.kinem(4,:)) 
xlabel('Time (ms)'); 
ylabel('x,y');
legend('x', 'y');
title('x,y wrt time subset 2');

saveas(f, ['Results/' 'Subset2.jpg']);

%% Plot Set 3
f = figure('units','normalized','outerposition',[0 0 1 1], 'visible', 'off');

subplot(2,2,1)
hold on; 
plot(set3EMG_Bicep.t, set3EMG_Bicep.data); % bicep
plot(set3EMG_Bicep.t, set3EMG_Bicep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Bicep EMG of subset 3');

subplot(2,2,2)
hold on; 
plot(set3EMG_Tricep.t, set3EMG_Tricep.data); %tricep
plot(set3EMG_Tricep.t, set3EMG_Tricep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Tricep EMG of subset 3');

subplot(2,2,3)
plot(set3.kinem(3,:), set3.kinem(4,:)) % x y
xlabel('x'); 
ylabel('y');
title('x,y subset 3');

subplot(2,2,4)
plot(Kinem.time(Indexes_Kinem_cue(1,865):Indexes_Kinem_cue(1,960)), set3.kinem(3,:)) % x, y time
hold on
plot(Kinem.time(Indexes_Kinem_cue(1,865):Indexes_Kinem_cue(1,960)), set3.kinem(4,:)) 
xlabel('Time (ms)'); 
ylabel('x,y');
legend('x', 'y');
title('x,y wrt time subset 3');

saveas(f, ['Results/' 'Subset3.jpg']);


%% Plot Set 4
f = figure('units','normalized','outerposition',[0 0 1 1], 'visible', 'off');

subplot(2,2,1)
hold on; 
plot(set4EMG_Bicep.t, set4EMG_Bicep.data); % bicep
plot(set4EMG_Bicep.t, set4EMG_Bicep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Bicep EMG of subset 4');

subplot(2,2,2)
hold on; 
plot(set4EMG_Tricep.t, set4EMG_Tricep.data); %tricep
plot(set4EMG_Tricep.t, set4EMG_Tricep.smooth);
hold off;
xlabel('Time (ms)'); 
ylabel('EMG (muV)');
legend('EMG signal', 'EMG smoothed');
title('Tricep EMG of subset 4');

subplot(2,2,3)
plot(set4.kinem(3,:), set4.kinem(4,:)) % x y
xlabel('x'); 
ylabel('y');
title('x,y subset 4');

subplot(2,2,4)
plot(Kinem.time(Indexes_Kinem_cue(1,961):Indexes_Kinem_cue(1,1056)), set4.kinem(3,:)) % x, y time
hold on
plot(Kinem.time(Indexes_Kinem_cue(1,961):Indexes_Kinem_cue(1,1056)), set4.kinem(4,:)) 
xlabel('Time (ms)'); 
ylabel('x,y');
legend('x', 'y');
title('x,y wrt time subset 4');

saveas(f, ['Results/' 'Subset4.jpg']);
    