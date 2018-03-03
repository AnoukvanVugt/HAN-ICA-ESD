const int MEETPIN = A0;
long waarde;
unsigned long previousMillis = 0;
unsigned long vertraging; //miliseconden
boolean ledsZijnAan[] = {false, true};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MEETPIN, INPUT);
  ledControlSetup();
  waarde = analogRead(MEETPIN);
  ledControlSetLedOff(0);
  ledControlSetLedOn(1);
  bepaalVertraging();
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= vertraging) {
    previousMillis = currentMillis;
    bepaalVertraging();
    if (ledsZijnAan[0] && (ledsZijnAan[1] == false)) {
      ledControlSetLedOff(0);
      ledControlSetLedOn(1);
      ledsZijnAan[0] = false;
      ledsZijnAan[1] = true;
    } else if (ledsZijnAan[1] && (ledsZijnAan[0]== false)) {
      ledControlSetLedOn(0);
      ledControlSetLedOff(1);
      ledsZijnAan[0] = true;
      ledsZijnAan[1] = false;
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

