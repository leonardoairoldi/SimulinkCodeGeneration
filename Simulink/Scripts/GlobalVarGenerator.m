function GlobalVarGenerator(BusType, Name)

mySig = Simulink.Signal;
mySig.DataType = strcat('Bus: ', BusType);
mySig.Dimensions = 1;
mySig.Complexity = 'real';

assignin("base",Name,mySig);

clear mySig;