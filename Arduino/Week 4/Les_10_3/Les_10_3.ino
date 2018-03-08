unsigned long previousMillis;
int totalCyclusTime; //milliseconden
int offTimeRed;
int offTimeBlue;
int offTimeGreen;
boolean redBlinked = false;
boolean blueBlinked = false;
boolean greenBlinked = false;
int amountOfSerialReads = 0;
float dutyCycleRed;
float dutyCycleBlue;
float dutyCycleGreen;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ledControlSetup();
  previousMillis = millis();
  greenBlinked = true;
  dutyCycleRed = 0.1;
  dutyCycleBlue = 0.1;
  dutyCycleGreen = 0.1;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  setCyclusTimes();
  if (greenBlinked) {
    setLedRed(currentMillis);
  } else if (redBlinked) {
    setLedBlue(currentMillis);
  } else if (blueBlinked) {
    setLedGreen(currentMillis);
  }
}

void setLedRed(unsigned long currentMillis) {
  if (currentMillis - previousMillis >= offTimeRed) {
    ledControlSetLedOn(0);
  }
  if (currentMillis - previousMillis >= totalCyclusTime) {
    previousMillis = currentMillis;
    ledControlSetLedOff(0);
    greenBlinked = false;
    redBlinked = true;
  }
}

void setLedBlue(unsigned long currentMillis) {
  if (currentMillis - previousMillis >= offTimeBlue) {
    ledControlSetLedOn(1);
  }
  if (currentMillis - previousMillis >= totalCyclusTime) {
    previousMillis = currentMillis;
    ledControlSetLedOff(1);
    redBlinked = false;
    blueBlinked = true;
  }
}

void setLedGreen(unsigned long currentMillis) {
  if (currentMillis - previousMillis >= offTimeGreen) {
    ledControlSetLedOn(2);
  }
  if (currentMillis - previousMillis >= totalCyclusTime) {
    previousMillis = currentMillis;
    ledControlSetLedOff(2);
    blueBlinked = false;
    greenBlinked = true;
  }
}

void setCyclusTimes() {
  totalCyclusTime = 20; //milliseconden
  setDutyCycle();
  offTimeRed = totalCyclusTime - (totalCyclusTime * dutyCycleRed);
  offTimeBlue = totalCyclusTime - (totalCyclusTime * dutyCycleBlue);
  offTimeGreen = totalCyclusTime - (totalCyclusTime * dutyCycleGreen);
}

int determineSerialInput() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();
    Serial.print("De input is: ");
    Serial.println(input);
    return (input / 10);
  }
}

void setDutyCycle() {
  //Serial.println("Ik kom hier");
  if (amountOfSerialReads == 0) {
    dutyCycleGreen = determineSerialInput();
    amountOfSerialReads++;
  } else if (amountOfSerialReads == 1) {
    dutyCycleBlue = determineSerialInput();
    amountOfSerialReads++;
  } else if (amountOfSerialReads == 2) {
    dutyCycleRed = determineSerialInput();
    amountOfSerialReads++;
    Serial.println("Ik kom hier");
  }
  if(amountOfSerialReads > 2) {
    amountOfSerialReads = 0;
  }
  Serial.print("dutyCycleRed: ");
  Serial.println(dutyCycleRed);
}


