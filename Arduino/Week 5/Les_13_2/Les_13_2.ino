boolean SerialReceived = false

void setup() {
  // put your setup code here, to run once:
  light_setup();
  serial_setup();
  sm_lights_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  sm_lights_loop();
}
