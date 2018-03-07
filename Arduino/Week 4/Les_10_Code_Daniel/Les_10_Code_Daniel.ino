const int TOTAALTIJD = 500;
const int AANTIJD = 250;

unsigned long previousMillis = 0;
boolean roodAan;
boolean groenAan;
boolean blauwAan;

void setup() {
  // put your setup code here, to run once:
  ledControlSetup();
  previousMillis = millis();
  setAllLedsOn();
}

void loop() {
  // put your main code here, to run repeatedly:
  ledDelay();
}

void ledDelay() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= TOTAALTIJD) {
    previousMillis = currentMillis;
    if (roodAan) {
      ledUit(0);
      ledAan(1);
      roodAan = false;
      groenAan = true;
    } else if (groenAan) {
      ledUit(1);
      ledAan(2);
      groenAan = false;
      blauwAan = true;
    } else if (blauwAan) {
      ledUit(2);
      ledAan(0);
      roodAan = true;
      blauwAan = false;
    }
  }
}
