#include <Servo.h>
const int SERVOPIN = 9;
Servo servo;

void setup() {
  servo.attach(SERVOPIN);
}

void loop() {
  for (int i = 0; i < 180; i++) {
    servo.write(i);
    delay(10);
  }
}
