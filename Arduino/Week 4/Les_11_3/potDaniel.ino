const int MAPFUNCTIONPORT = A1;
const int MAPMAXINPUT = 180;
const int MAPMININPUT = 0;

long valueMapfunction;

int getValueMapfunction(int mapMinInput, int mapMaxInput) {
  return mapfunction(valueMapfunction, 0, 1023, mapMinInput, mapMaxInput);
}

void mapfunctionSetup() {
  pinMode(MAPFUNCTIONPORT, INPUT);
  valueMapfunction = analogRead(MAPFUNCTIONPORT);
}

void executeMapfunction() {
  long otherValue = analogRead(MAPFUNCTIONPORT);
  if (otherValue != valueMapfunction) {
    mapfunction(valueMapfunction, 0, 1023, MAPMININPUT, MAPMAXINPUT);
    valueMapfunction = otherValue;
  }
}


//int mapfunction(long input, long inputFrom, long inputTot, long outputFrom, long outputTot) {
//  long deltaInput = inputTot - inputFrom;
//  long deltaOutput = outputTot - outputFrom;
//
//  float deltaInputFloat = deltaInput;
//  float deltaOutputFloat = deltaOutput;
//
//  float relativePosition = (input - inputFrom) / deltaInputFloat;
//  float positionInput = (relativePosition * deltaOutputFloat) + outputFrom;
//  return positionInput;
//}
