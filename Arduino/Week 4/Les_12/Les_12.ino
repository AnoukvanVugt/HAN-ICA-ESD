#include <EEPROM.h>
unsigned long previousMillis;
const int INTERVAL = 5000; //milliseconden
const int ADDRESS_FOR_POTVALUE_PART_ONE = 0;
const int ADDRESS_FOR_POTVALUE_PART_TWO = 1;
int potValue;
int maxOpslagWaarde = 255;

void setup() {
  // put your setup code here, to run once:
  previousMillis = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = getPotValue();
  printPotValue();
  printEEPROMValueOnInterval();
  if (Serial.available() > 0) {
    int value = Serial.read();
    if (value == 's') {
      writePotValueToEEPROM();
    }
  }
}

void printPotValue() {
  Serial.print("Potvalue; ");
  Serial.println(potValue);
}

void printEEPROMValueOnInterval() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    Serial.println("EEPROM: ");
    EEPROM.read(ADDRESS_FOR_POTVALUE);
  }
}

void writePotValueToEEPROM() {
  if (potValue <= maxOpslagWaarde) {
    EEPROM.write(ADDRESS_FOR_POTVALUE_PART_ONE, potValue);
  } else {
    EEPROM.write(ADDRESS_FOR_POTVALUE_PART_ONE, maxOpslagWaarde);
    EEPROM.write(ADDRESS_FOR_POTVALUE_PART_TWO, (potValue - maxOpslagWaarde));
  }
  Serial.println("De huidige potvalue is opgeslagen");
}

