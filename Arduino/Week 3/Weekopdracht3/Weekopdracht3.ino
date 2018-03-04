//Naam: Anouk van Vugt
//Datum: 04-03-'18
//Opdracht: Weekopdracht 3 - Weerstation

#include <OneWire.h>

unsigned long previousMillis5; //previousMillis for the tracking of the passing of five seconds for generating the values for sending

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  LDRControlSetup();
  NTCControlSetup();
  setupShiftRegister();
  potControlSetup();
  previousMillis5 = millis();
  clearShiftRegister();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis5 >= 5000) { //5 seconden
    previousMillis5 = currentMillis;
    int temperature = generateTemperature();
    int illumination = generateIllumination();
    char winddirection = generateWinddirection();
    char values[] = {temperature, illumination, winddirection};
    sendValuesUsingChecksum(values, 3);
  }
}

int generateTemperature() {
  initGetTemperature();
  int temperature = actualGetTemperature();
  return temperature;
}

char generateWinddirection() {
  int potValue = mapfunctie(getPotValue(), 0, 1023, 0, 360);
  char winddirections [] = {'N', 'O', 'Z', 'W'};
  char winddirection;
  if(potValue >= 45 && potValue << 135) {
    winddirection = winddirections[1];
    setShiftRegister(B11111100);
  } else if(potValue >= 135 && potValue << 255) {
    winddirection = winddirections[2];
    setShiftRegister(B11011010);
  } else if(potValue >= 255 && potValue << 315) {
    winddirection = winddirections[3];
    setShiftRegister(B01111100);
  } else {
    winddirection = winddirections[0];
    setShiftRegister(B11101100);
  }
  return winddirection;
}

int generateIllumination() {
  int illumination = getLDRValue();
  return illumination;
}

char generateChecksum(char values[], int nValues) {
  char sum;
  for (int i = 0; i < nValues; i++) {
    sum = (sum + values[i]) % 127;
  }
  return sum;
}

void sendValuesUsingChecksum(char values[], int nValues) {
  Serial.write("^");
  for (int i = 0; i < nValues; i++) {
    Serial.write(values[i]);
  }
  Serial.write(generateChecksum(values, nValues));
  Serial.write(127);
}

int mapfunctie(long input, long inputVan, long inputTot, long outputVan, long outputTot) {
  long deltaInput = inputTot - inputVan;
  long deltaOutput = outputTot - outputVan;

  float deltaInputFloat = deltaInput;
  float deltaOutputFloat = deltaOutput;

  float positieInput = (input - inputVan) / deltaInputFloat;
  float returnWaarde = (positieInput * deltaOutputFloat) + outputVan;
  //Serial.println(returnWaarde);
  return returnWaarde;
}

