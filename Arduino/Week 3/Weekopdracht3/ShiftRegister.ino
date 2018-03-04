const int DATAPIN = 8;
const int STORAGEPIN = 9;
const int CLOCKPIN = 10;

const int NBITS = 8;

void setupShiftRegister() {
  pinMode(DATAPIN, OUTPUT);
  pinMode(STORAGEPIN, OUTPUT);
  pinMode(CLOCKPIN, OUTPUT);
}

void clearShiftRegister() {
  digitalWrite(STORAGEPIN, LOW);
  for (int i = 0; i < NBITS; i++) {
    digitalWrite(CLOCKPIN, LOW);
    digitalWrite(DATAPIN, LOW);
    digitalWrite(CLOCKPIN, HIGH);
  }
  digitalWrite(STORAGEPIN, HIGH);
  digitalWrite(STORAGEPIN, LOW);
}

void allOnShiftRegister() {
  digitalWrite(STORAGEPIN, LOW);
  for (int i = 0; i < NBITS; i++) {
    digitalWrite(CLOCKPIN, LOW);
    digitalWrite(DATAPIN, HIGH);
    digitalWrite(CLOCKPIN, HIGH);
  }
  digitalWrite(STORAGEPIN, HIGH);
  digitalWrite(STORAGEPIN, LOW);
}

void setShiftRegister(byte pattern) {
  byte compareByte = B00000001;
  digitalWrite(STORAGEPIN, LOW);
  for (int i = 0; i < NBITS; i++) {
    if ((pattern & compareByte) != 0) {
      digitalWrite(CLOCKPIN, LOW);
      digitalWrite(DATAPIN, HIGH);
      digitalWrite(CLOCKPIN, HIGH);
    } else {
      digitalWrite(CLOCKPIN, LOW);
      digitalWrite(DATAPIN, LOW);
      digitalWrite(CLOCKPIN, HIGH);
    }
    compareByte = compareByte << 1;
  }
  digitalWrite(STORAGEPIN, HIGH);
  digitalWrite(STORAGEPIN, LOW);
}




