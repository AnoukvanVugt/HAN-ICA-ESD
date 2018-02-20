void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ledControlSetup();
}

void loop() {
  int huidigeVertraging = getVertraging();
  if (Serial.available() > 0) {
    int input = Serial.read();
    switch (input) {
      case 'H':
        patroonH();
        Serial.println("Patroon H");
        break;
      case 'S':
        patroonS();
        Serial.println("Patroon S");
        break;
      case 's':
        patroons();
        Serial.println("Patroon s");
        break;
      case 'R':
        patroonR();
        Serial.println("Patroon R");
        break;
      case 'L':
        patroonL();
        Serial.println("Patroon L");
        break;
      case 'E':
        patroonE();
        Serial.println("Patroon E");
        break;
      case '+':
        patroonPlus();
        Serial.println("Patroon +, de vertraging is nu: " + huidigeVertraging);
        break;
      case '-':
        patroonMinus();
        Serial.println("Patroon -, de vertraging is nu: " + huidigeVertraging);
        break;
    }
  }
}
