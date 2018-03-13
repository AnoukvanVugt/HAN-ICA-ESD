#include <Servo.h>
const int SERVOPIN = 9;
Servo servo;
int valuesPotMeter[] = new int [1023];
unsigned long previousMillis;
int interval = 20; //milliseconden

void setup() {
  servo.attach(SERVOPIN);
  potControlSetup();
  previousMillis = millis();
}

void loop() {
  unsigned long currentMillis = millis();
  for(int currentPlaceInArray = 0; currentPlaceInArray < 1023; currentPlaceInArray++) {
    if(currentPlaceInArray = getPotValue()) {
    int valuePotMeter = mapfunction(getPotValue(), 0, 1023, 0, 180);
    valuesPotMeter[currentPlaceInArray] = valuePotMeter;
    }
  }
  if(currenMillis-previousMillis >= interval) {
    for(int currentPlaceInArray = 0; currentPlaceInArray < 1023; currentPlaceInArray++) {
      servo.write(valuesPotMeter[currentPlaceInArray]);
    }
  }
}

int mapfunction(long input, long inputVan, long inputTot, long outputVan, long outputTot) {
  long deltaInput = inputTot - inputVan;
  long deltaOutput = outputTot - outputVan;

  float deltaInputFloat = deltaInput;
  float deltaOutputFloat = deltaOutput;

  float positieInput = (input - inputVan) / deltaInputFloat;
  float returnWaarde = (positieInput * deltaOutputFloat) + outputVan;
  //Serial.println(returnWaarde);
  return returnWaarde;
}
