unsigned long previousMillis;
int totaalCyclusTijd = 20; //milliseconden
float dutyCycle;
int aanTijd = totaalCyclusTijd * dutyCycle;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ledControlSetup();
  previousMillis = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  int input = bepaalSerialInput();
  setDutyCycle(input);
  if (currentMillis - previousMillis >= aanTijd) {
    ledControlSetLedOff(0);
  }
  if (currentMillis - previousMillis >= totaalCyclusTijd) {
    previousMillis = currentMillis;
    ledControlSetLedOn(0);
  }
}

int bepaalSerialInput() {
  if (Serial.available() > 0) {
    int input = Serial.read();
    Serial.print("De input is: ");
    Serial.println(input, DEC);
    return input;
  }
}

void setDutyCycle(int input) {
  for (int i = 1; i <= 10; i++) {
    if (input == i) {
      dutyCycle = i / 10;
    }
  }
}

