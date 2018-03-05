const int NUMBEROFLEDS = 1;
const int PINARRAY[] = {5};

int getNUMBEROFLEDS() {
  return NUMBEROFLEDS;
}

void ledControlSetup() {
  for (int ledNumber = 0; ledNumber < NUMBEROFLEDS; ledNumber++) {
    pinMode(PINARRAY[ledNumber], OUTPUT);
  }
}

void ledControlSetLedOn(int ledNumber) {
  digitalWrite(PINARRAY[ledNumber], HIGH);
}

void ledControlSetLedOff(int ledNumber) {
  digitalWrite(PINARRAY[ledNumber], LOW);
}

void ledControlAllLedsOn() {
  for(int ledNumber = 0; ledNumber < NUMBEROFLEDS; ledNumber++) {
    digitalWrite(PINARRAY[ledNumber], HIGH);
  }
}

void ledControlAllLedsOff() {
  for(int ledNumber = 0; ledNumber < NUMBEROFLEDS; ledNumber++) {
    digitalWrite(PINARRAY[ledNumber], LOW);
  }
}

