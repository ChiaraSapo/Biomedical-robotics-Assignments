function [EMG] = Preprocessing(test, N, W, Fenv, Fnyq, dsFactor, Fs)

%Build Nth-order bandpass FIR filter 
[B,A] = fir1(N, W); 

% Remove offset
EMG.data = test - mean(test); 

%Filter EMG
EMG.filt = filtfilt(B, A, double(EMG.data));

% Rectify signal (rectify: invert negative portion of signal so that
% the entire signal has the same polarity.
EMG.rectified = abs(EMG.filt); 

%Envelope filter
[b, a] = butter(4, 1.116 * (Fenv/Fnyq), 'low'); 

%Smooth 
EMG.smooth = filtfilt(b, a, EMG.rectified); 

%Downsample
EMG.downsampled = downsample(EMG.smooth, dsFactor); 

% Parameter for plotting time
EMG.t   = (1:max(size(EMG.smooth)))/Fs;
end

