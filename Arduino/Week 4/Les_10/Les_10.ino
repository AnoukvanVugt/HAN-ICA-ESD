unsigned long previousMillis;
int totaalCyclusTijd = 1000; //milliseconden
float dutyCycle;
float aanTijd;

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
  setCycleTimes(input);
  if (currentMillis - previousMillis >= aanTijd) {
    if (aanTijd < 10) {
      ledControlSetLedOff(0);
      //Serial.println("Ik ben uit.");
    }
  }
  if (currentMillis - previousMillis >= totaalCyclusTijd) {
    previousMillis = currentMillis;
    if (aanTijd > 0) {
      ledControlSetLedOn(0);
      //Serial.println("Ik ben aan.");
    }
  }
}

int bepaalSerialInput() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();
    Serial.print("De input is: ");
    Serial.println(input);
    return input;
  }
}

void setCycleTimes(int input) {
  for (float i = 0; i <= 10; i++) {
    if (input == i) {
      dutyCycle = i / 10;
    }
  }
  aanTijd = totaalCyclusTijd * dutyCycle;
  //Serial.println("De aanTijd is: ");
  //Serial.println(aanTijd);
}

