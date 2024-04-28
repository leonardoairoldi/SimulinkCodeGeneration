%% Generate Code
clc;
open_system SMKCODEACADEMY.slx
save_system SMKCODEACADEMY.slx
slbuild("SMKCODEACADEMY", 'StandaloneCoderTarget', 'GenerateCodeOnly', true);

%% Pack Code
packNGo("SMKCODEACADEMY_ert_rtw\buildInfo.mat", 'fileName', 'TOOLCHAINv2.zip', 'packType', 'hierarchical', ...
    'minimalHeaders', true, 'nestedZipFiles', false);


%% Export Code
proj = matlab.project.rootProject;
unzip("TOOLCHAINv2.zip", "TOOLCHAINv2\");

%% Copy external libraries file
rootdir = proj.RootFolder + "\TOOLCHAINv2\R2023b\";
filelist = dir(fullfile(rootdir, '**\*.*'));
filelist = filelist(~[filelist.isdir]); % Get all files in the directory
filelist = filelist(~contains({filelist.name}, 'rt_main.c')); % Remove rt_main.c

w = mkdir(proj.RootFolder + "\Keil\Simulink_Code\External");
for i = 1:length(filelist)
    filepath = filelist(i).folder;
    name = filelist(i).name;
    copyfile(filepath + "\" + name, proj.RootFolder + "\Keil\Simulink_Code\External");
end

%% Copy model files
topfoldername = "SimulinkCodeGeneration";
rootdir = proj.RootFolder + "\TOOLCHAINv2\" + topfoldername + "\slprj\ert\";
% Create directories for every model
dirlist = dir(rootdir);
dirlist = dirlist(~contains({dirlist.name}, "."));

for i = 1:length(dirlist)
    w = mkdir(proj.RootFolder + "\Keil\Simulink_Code\Models\" + dirlist(i).name);
end

% Copy all files in the directories
for i = 1:length(dirlist)
    foldername = dirlist(i).name;
    filelist = dir(fullfile(rootdir + foldername, '**\*.*'));
    filelist = filelist(~[filelist.isdir]); % Get all files in the directory

    for j = 1:length(filelist)
        filepath = filelist(j).folder;
        name = filelist(j).name;
        copyfile(filepath + "\" + name, proj.RootFolder + "\Keil\Simulink_Code\Models\" + foldername);
    end
end


%% Copy Main Model Files
rootdir = proj.RootFolder + "\TOOLCHAINv2\" + topfoldername + "\SMKCODEACADEMY_ert_rtw\";
filelist = dir(fullfile(rootdir, '**\*.*'));
filelist = filelist(~[filelist.isdir]); % Get all files in the directory
filelist = filelist(~contains({filelist.name}, 'ert_main.c')); % Remove ert_main.c

w = mkdir(proj.RootFolder + "\Keil\Simulink_Code\SMKCODEACADEMY");
for i = 1:length(filelist)
    filepath = filelist(i).folder;
    name = filelist(i).name;
    copyfile(filepath + "\" + name, proj.RootFolder + "\Keil\Simulink_Code\SMKCODEACADEMY");
end

%% Delete the Zip folder
rmdir("TOOLCHAINv2", 's');
delete("TOOLCHAINv2.zip");

%% Clear Variables
clear rootdir filelist w i j filepath name topfoldername foldername dirlist proj
