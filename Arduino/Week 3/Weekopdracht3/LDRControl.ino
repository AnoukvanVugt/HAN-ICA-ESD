const int LDRPIN = A1;

void LDRControlSetup() {
  pinMode(LDRPIN, INPUT);
}

int getLDRValue() {
  int LDRValue = analogRead(LDRPIN);
  return LDRValue;
}
