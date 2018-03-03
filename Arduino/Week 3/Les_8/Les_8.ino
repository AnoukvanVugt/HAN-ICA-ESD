unsigned long previousMillis1; //previousMillis for the tracking of the passing of one second for generating the illumination
unsigned long previousMillis10; //previousMillis for the tracking of the passing of ten seconds for generating the illumination
unsigned long previousMillis5; //previousMillis for the tracking of the passing of five seconds for generating the values for sending

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  previousMillis1 = millis();
  previousMillis10 = millis();
  previousMillis5 = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis5 >= 5000) { //5 seconden
    previousMillis5 = currentMillis;
    int temperature = generateRandomNumber(0, 30);
    int illumination = generateIllumination();
    char winddirection = generateWinddirection();
    char values[] = {temperature, illumination, winddirection};
    sendValuesUsingChecksum(values, 3);
  }
}

int generateRandomNumber(int minimum, int maximum) {
  return random(minimum, maximum);
}

char generateWinddirection() {
  char winddirections[] = {'N', 'E', 'S', 'W'};
  return winddirections[random(0, 4)];
}

int generateIllumination() {
  unsigned long currentMillis = millis();
  int value = 0;
  int returnValue = 0;
  if (currentMillis - previousMillis1 >= 1000) { //1 seconde
    previousMillis1 = currentMillis;
    value += generateRandomNumber(0, 126);
  }
  if (currentMillis - previousMillis10 >= 10000) { //10 seconden
    previousMillis10 = currentMillis;
    returnValue = value / 10;
    value = 0;
  }
  return returnValue;
}

char generateChecksum(char values[], int nValues) {
  char sum;
  for (int i = 0; i < nValues; i++) {
    sum = (sum + values[i]) % 127;
  }
  return sum;
}

void sendValuesUsingChecksum(char values[], int nValues) {
  Serial.write("^");
  for (int i = 0; i < nValues; i++) {
    Serial.write(values[i]);
  }
  Serial.write(generateChecksum(values, nValues));
  Serial.write(127);
}

