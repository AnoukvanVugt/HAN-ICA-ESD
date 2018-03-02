const int MEETPIN = A0;
long waarde;
unsigned long previousMillis = 0;
int vertraging; //miliseconden
boolean ledsZijnAan[] = {false, true};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MEETPIN, INPUT);
  ledControlSetup();
  waarde = analogRead(MEETPIN);
  ledControlSetLedOff(0);
  ledControlSetLedOn(1);
}

void loop() {
  unsigned long currentMillis = millis();
  bepaalVertraging();
  if (currentMillis - previousMillis >= vertraging) {
    previousMillis = currentMillis;
    if (ledsZijnAan[0] && !ledsZijnAan[1]) {
      ledControlSetLedOff(0);
      ledControlSetLedOn(1);
    } else if (ledsZijnAan[1] && !ledsZijnAan[0]) {
      ledControlSetLedOn(0);
      ledControlSetLedOff(1);
    }
  }
}

int mapfunctie(long input, long inputVan, long inputTot, long outputVan, long outputTot) {
  long deltaInput = inputTot - inputVan;
  long deltaOutput = outputTot - outputVan;

  float deltaInputFloat = deltaInput;
  float deltaOutputFloat = deltaOutput;

  float positieInput = (input - inputVan) / deltaInputFloat;
  float returnWaarde = (positieInput * deltaOutputFloat) + outputVan;
  Serial.println(returnWaarde);
  return returnWaarde;
}

void voerMapfunctieUit(long outputVan, long outputTot) {
  long tweedeWaarde = analogRead(MEETPIN);
  //Serial.println(tweedeWaarde);
  if (tweedeWaarde != waarde) {
    mapfunctie(waarde, 0, 1023, outputVan, outputTot);
    waarde = tweedeWaarde;
  }
}

void bepaalVertraging() {
  vertraging = mapfunctie(waarde, 0, 1023, 50, 1000);
}

