proj = matlab.project.rootProject;

hArray = ["ELECTRICAL_typedef.h"; "FSM_typedef.h"];
hStruct = "GLOBAL_typedef.h";

includes = proj.RootFolder + '/Keil/Custom_Code/C_typedef/' + hArray;
mainStruct = proj.RootFolder + '/Keil/Custom_Code/C_typedef/' + hStruct;

Simulink.importExternalCTypes(mainStruct, 'IncludeDirs', includes, 'OutputDir', 'Simulink/Generated_Defines', 'Overwrite', 'on', 'Verbose', 'on');
% Può anche definire delle define con 'Defines' con cui discriminare quale
% codice importare (Importante per la CAN LIBRARY)

GlobalVarGenerator('GLOBAL_t', 'SMKACADEMY');

clear includes mainStruct hStruct hArray proj;
