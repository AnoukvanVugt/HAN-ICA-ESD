void serial_setup() {
  Serial.begin(9600);
}

boolean serial_received() {
  if(Serial.available() > 0) {
    SerialReceived = true;
  } else {
    SerialReceived = false;
  }
}

