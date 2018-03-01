void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  verstuurWaardesMetChecksum("28;-15;6", 8);
}

char genereerChecksum(char waardes[], int nWaardes) {
  char sum;
  for (int i = 0; i < nWaardes; i++) {
    sum = (sum + waardes[i]) % 128;
  }
  return sum;
}

void verstuurWaardesMetChecksum(char waardes[], int nWaardes) {
  for (int i = 0; i < nWaardes; i++) {
    Serial.write(waardes[i]);
  }
  Serial.write(",");
  Serial.write(genereerChecksum(waardes, nWaardes));
  Serial.write('\n');
}

