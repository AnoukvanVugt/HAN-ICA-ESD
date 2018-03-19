#include <Servo.h>
const int SERVOPIN = 9;
Servo servo;
unsigned long previousMillis;
const int INTERVAL = 20; //milliseconden
boolean turning = true;
int currentPosition = 0;
int target = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVOPIN);
  potControlSetup();
  previousMillis = millis();
}

void loop() {
  target = mapfunction(getPotValue(), 0, 1023, 0, 180);
  unsigned long currentMillis = millis();
  if(turning) {
    if(currentMillis - previousMillis >= INTERVAL) {
      if(target > currentPosition) {
        currentPosition++;
      } else {
        currentPosition--;
      }
      servo.write(currentPosition);
      previousMillis = currentMillis;
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
