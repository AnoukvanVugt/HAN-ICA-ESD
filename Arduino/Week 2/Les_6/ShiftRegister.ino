const int DATAPIN = 8;
const int STORAGEPIN = 9;
const int CLOCKPIN = 10;

void setupShiftRegister() {
  pinMode(DATAPIN, OUTPUT);
  pinMode(STORAGEPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
}

void clearShiftRegister() {
  digitalWrite(STORAGEPIN, LOW);
  for (int i = 0; i < 8; i++) {
    digitalWrite(CLOCKPIN, LOW);
    digitalWrite(DATAPIN, LOW);
    digitalWrite(CLOCKPIN, HIGH);
  }
  digitalWrite(STORAGEPIN, HIGH);
  digitalWrite(STORAGEPIN, LOW);
}

void allOnShiftRegister() {
  digitalWrite(STORAGEPIN, LOW);
  for (int i = 0; i < 8; i++) {
    digitalWrite(CLOCKPIN, LOW);
    digitalWrite(DATAPIN, HIGH);
    digitalWrite(CLOCKPIN, HIGH);
  }
  digitalWrite(STORAGEPIN, HIGH);
  digitalWrite(STORAGEPIN, LOW);
}

void setShiftRegister(byte pattern) {
  byte vergelijkByte = B00000001;
  
}

