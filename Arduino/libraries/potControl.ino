const int POTPIN = A0;

void potControlSetup() {
  pinMode(POTPIN, INPUT);
}

long getPotValue() {
  long potValue = analogRead(POTPIN);
  return potValue;
}
