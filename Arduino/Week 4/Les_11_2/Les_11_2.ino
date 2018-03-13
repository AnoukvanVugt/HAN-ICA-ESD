#include <Servo.h>
const int SERVOPIN = 9;
Servo servo;

void setup() {
  servo.attach(SERVOPIN);
  potControlSetup();
}

void loop() {
  int valuePotMeter = mapfunction(getPotValue(), 0, 1023, 0, 180);
  servo.write(valuePotMeter);
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
