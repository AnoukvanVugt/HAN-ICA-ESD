void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 128; i++) {
    Serial.write(i);
    Serial.print('-');
    Serial.print(i, BIN);
    Serial.print('-');
    Serial.print(i, OCT);
    Serial.print('-');
    Serial.print(i, DEC);
    Serial.print('-');
    Serial.println(i, HEX);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
