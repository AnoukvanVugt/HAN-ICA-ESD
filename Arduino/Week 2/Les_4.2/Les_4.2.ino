void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  byte invoer = 13;
  byte patroon = B1000000;

  for (int i = 0; i < 8; i++) {
    Serial.print(invoer | (patroon >> i), BIN);
    Serial.print(" ");
    Serial.print(invoer & (patroon >> i), BIN);
    Serial.print(" ");
    Serial.print(invoer ^ (patroon >> i), BIN);
    Serial.print(" ");
    Serial.print(invoer | ~(patroon >> i), BIN);
    Serial.print(" ");
    Serial.println(invoer & ~(patroon >> i), BIN);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

byte zetOpNul(byte input, int volgNummerVanafRechts) {
  byte matchPatroon = B00000001;
  matchPatroon = ~(matchPatroon << volgNummerVanafRechts);
  return(input & matchPatroon);
}

