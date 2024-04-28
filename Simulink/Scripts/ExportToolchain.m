%% Generate Code
clc;
open_system SMKCODEACADEMY.slx
save_system SMKCODEACADEMY.slx
slbuild("SMKCODEACADEMY", 'StandaloneCoderTarget', 'GenerateCodeOnly', true);

%% Export Code
% Load model names
proj = matlab.project.rootProject;
[~,modNames,~] = fileparts(string(ls(proj.RootFolder + '\Simulink\Models\*.slx')));
% Destination Folder
destination = proj.RootFolder + '\Keil\Simulink_Code\';

% Export Model Files .c/.h
for l = 1 : 1 : size(modNames, 1)
    if (isfolder(proj.RootFolder + '\slprj\ert\' + modNames(l) + '\'))
        [status, msg, msgID] = mkdir(destination,modNames(l));
        
        [~,sharedSource,~] = fileparts(string(ls(proj.RootFolder + '\slprj\ert\' + modNames(l) + '\*.c')));
        [~,sharedHeader,~] = fileparts(string(ls(proj.RootFolder + '\slprj\ert\' + modNames(l) + '\*.h')));

        for j = 1 : 1 : size(sharedHeader, 1)
            headerName = fullfile(proj.RootFolder + '\slprj\ert\' + modNames(l) + '\' + sharedHeader(j) + '.h');
            finaldestination = destination + modNames(l) + '\';
            copyfile(headerName,finaldestination, 'f')
        end
        for j = 1 : 1 : size(sharedSource, 1)
            sourceName = fullfile(proj.RootFolder + '\slprj\ert\' + modNames(l) + '\' + sharedSource(j) + '.c');
            finaldestination = destination + modNames(l) + '\';
            copyfile(sourceName,finaldestination, 'f')
        end
    end
end

% Shared Libraries Export
[~,sharedSource,~] = fileparts(string(ls(proj.RootFolder + '\slprj\ert\_sharedutils\*.c')));
[~,sharedHeader,~] = fileparts(string(ls(proj.RootFolder + '\slprj\ert\_sharedutils\*.h')));

[status, msg, msgID] = mkdir(destination,'Shared');


for l = 1 : 1 : size(sharedHeader, 1)
    headerName = fullfile(proj.RootFolder + '\slprj\ert\_sharedutils\' + sharedHeader(l) + '.h');
    finaldestination = destination + 'Shared\';
    copyfile(headerName,finaldestination, 'f')
end

if sharedSource ~= "" 
for l = 1 : 1 : size(sharedSource, 1)
    sourceName = fullfile(proj.RootFolder + '\slprj\ert\_sharedutils\' + sharedSource(l) + '.c');
    finaldestination = destination + 'Shared\';
    copyfile(sourceName,finaldestination, 'f')
end
else
    warning("No shared .c were generated");
end

% Export top model files
topModelName = "SMKCODEACADEMY";
topModelCodeFolder = "SMKCODEACADEMY_ert_rtw\";

[~,topModelHeader,~] = fileparts(string(ls(proj.RootFolder + '\SMKCODEACADEMY_ert_rtw\*.h')));
[~,topModelSource,~] = fileparts(string(ls(proj.RootFolder + '\SMKCODEACADEMY_ert_rtw\*.c')));

[status, msg, msgID] = mkdir(destination,topModelName);

for l = 1 : 1 : size(topModelHeader, 1)
    headerName = fullfile(proj.RootFolder + '\' + topModelCodeFolder + topModelHeader(l) + '.h');
    finaldestination = destination + topModelName;
    copyfile(headerName,finaldestination, 'f')
end
for l = 1 : 1 : size(topModelSource, 1)
    headerName = fullfile(proj.RootFolder + '\' +topModelCodeFolder + topModelSource(l) + '.c');
    finaldestination = destination + topModelName;
    copyfile(headerName,finaldestination, 'f')
end

%% External Libraries imports

% Array containing the names of external libraries needed by code
external_lib = ["nesl_rtw_rtp.h"; "nesl_rtw.h"];

[status, msg, msgID] = mkdir(proj.RootFolder + "\Keil\Simulink_Code\","External");
dest = proj.RootFolder + "\Keil\Simulink_Code\External\";
for i = 1 : 1: size(external_lib)
    try
        % Look at the floder, they are not always the same!
        % Look into C:\Program Files\MATLAB\R2023b\
        copyfile("C:\Program Files\MATLAB\R2023b\extern\physmod\win64\ssc_sli\include\" + external_lib(i), dest, 'f')
    catch
        copyfile("D:\Program Files\MATLAB\R2023b\extern\physmod\win64\ssc_sli\include\" + external_lib(i), dest + external_lib(i), 'f')
        %External library import failed. Try checking MATLAB path, external library path or filename
    end
end

% DA AGGIUNGERE
% rtwtypes.h
% tmwtypes.h


% Clear toolchain variables
clear ans finaldestination destination headerName j l modelName modNames msg msgID;
clear proj sharedSource sharedHeader sourceName status topModelCodeFolder;
clear topModelHeader topModelName topModelSource;
clear external_lib dest;