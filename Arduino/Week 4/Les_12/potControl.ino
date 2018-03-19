const int POTPIN = A1;

void potControlSetup() {
  pinMode(POTPIN, INPUT);
}

long getPotValue() {
  long potValue = analogRead(POTPIN);
  return potValue;
}
