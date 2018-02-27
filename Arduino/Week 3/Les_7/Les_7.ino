const int MEETPIN = A0;
long waarde;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MEETPIN, INPUT);
  waarde = analogRead(MEETPIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  long tweedeWaarde = analogRead(MEETPIN);
  //Serial.println(tweedeWaarde);
  if (tweedeWaarde != waarde) {
    mapfunctie(waarde, 0, 1023, 0, 10);
    waarde = tweedeWaarde;
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

