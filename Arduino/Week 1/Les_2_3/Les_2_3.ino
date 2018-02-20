void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  ledControlSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  int NUMBEROFLEDS = getNUMBEROFLEDS();
  heenEnWeerAan(NUMBEROFLEDS);
  heenEnWeerUit(NUMBEROFLEDS);
  //  ledControlSetLedOn(5);
  //  delay(500);
  //  ledControlSetLedOff(5);
  //  delay(500);
  //  ledControlAllLedsOn();
  //  delay(500);
  //  ledControlAllLedsOff();
  //  delay(500);
}

void heenEnWeerAan(int numberofleds) {
  ledControlAllLedsOff();
  delay(500);
  for (int i = 0; i < numberofleds - 1; i++) {
    ledControlSetLedOn(i);
    delay(150);
    ledControlSetLedOff(i);
  }
  for (int i = numberofleds - 1 ; i >= 1; i--) {
    ledControlSetLedOn(i);
    delay(150);
    ledControlSetLedOff(i);
  }
}

void heenEnWeerUit(int numberofleds) {
  ledControlAllLedsOn();
  delay(500);
  for (int i = 0; i < numberofleds - 1; i++) {
    ledControlSetLedOff(i);
    delay(150);
    ledControlSetLedOn(i);
  }
  for (int i = numberofleds - 1 ; i >= 1; i--) {
    ledControlSetLedOff(i);
    delay(150);
    ledControlSetLedOn(i);
  }
}

void knipperRij() {
  int NUMBEROFLEDS = getNUMBEROFLEDS();
  for (int i = 0; i < NUMBEROFLEDS; i++) {
    ledControlSetLedOn(i);
    delay(500);
    ledControlSetLedOff(i);
  }
}

