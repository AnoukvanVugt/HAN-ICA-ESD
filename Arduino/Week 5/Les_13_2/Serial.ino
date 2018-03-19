void serial_setup() {
  Serial.begin(9600);
}

String serial_received() {
  int input = Serial.read();
  if (Serial.available() > 0) {
    if (input == 'g') {
      return green;
    }
    if (input == 'b') {
      return both;
    }
    if (input == 'r') {
      return red;
    }
    if (input == 'x') {
      return quit;
    }
  }
  return empty;
}

