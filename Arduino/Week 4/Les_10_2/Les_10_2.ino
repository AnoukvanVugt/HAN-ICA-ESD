unsigned long previousMillis;
int totalCyclusTime; //milliseconden
float dutyCycleRed;
float dutyCycleBlue;
float dutyCycleGreen;
int offTimeRed;
int offTimeBlue;
int offTimeGreen;
boolean redBlinked = false;
boolean blueBlinked = false;
boolean greenBlinked = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ledControlSetup();
  previousMillis = millis();
  setCyclusTimJes();
  greenBlinked = true;
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
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
  dutyCycleRed = 0.2;
  offTimeRed = totalCyclusTime - (totalCyclusTime * dutyCycleRed);
  dutyCycleBlue = 0.5;
  offTimeBlue = totalCyclusTime - (totalCyclusTime * dutyCycleBlue);
  dutyCycleGreen = 0.8;
  offTimeGreen = totalCyclusTime - (totalCyclusTime * dutyCycleGreen);
}

