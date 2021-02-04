function varargout = Body_cursor_GUI(varargin)
% BODY_CURSOR_GUI MATLAB code for Body_cursor_GUI.fig
%      BODY_CURSOR_GUI, by itself, creates a new BODY_CURSOR_GUI or raises the existing
%      singleton*.
%
%      H = BODY_CURSOR_GUI returns the handle to a new BODY_CURSOR_GUI or the handle to
%      the existing singleton*.
%
%      BODY_CURSOR_GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BODY_CURSOR_GUI.M with the given input arguments.
%
%      BODY_CURSOR_GUI('Property','Value',...) creates a new BODY_CURSOR_GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before Body_cursor_GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to Body_cursor_GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help Body_cursor_GUI

% Last Modified by GUIDE v2.5 30-Dec-2020 11:48:36

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Body_cursor_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @Body_cursor_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Body_cursor_GUI is made visible.
function Body_cursor_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to Body_cursor_GUI (see VARARGIN)

% Choose default command line output for Body_cursor_GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes Body_cursor_GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = Body_cursor_GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

open_system('Wrist')
set_param('Wrist','SimulationMode','external')
set_param('Wrist','simulationCommand','connect')
set_param('Wrist','simulationCommand','start')


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
open_system('Torso')
set_param('Torso','SimulationMode','external')
set_param('Torso','simulationCommand','connect')
set_param('Torso','simulationCommand','start')

