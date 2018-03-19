const int LIGHT_STATE_OFF = 0;
const int LIGHT_STATE_GREEN = 1;
const int LIGHT_STATE_BOTH = 2;
const int LIGHT_STATE_RED = 3;

int led_state;

void sm_light_setup() {
  led_state = LIGHT_STATE_OFF;
  led_off_entry();
}

void light_loop() {
  switch (led_state) {
    case LIGHT_STATE_OFF:
      led_off_do();
      if (serial_received() == "green") {
        led_off_exit();
        led_state = LIGHT_STATE_GREEN;
        light_green_entry();
      }
      break;
      case LIGHT_STATE_GREEN:
      light_green_do();
      if(serial_received() == "both") {
        light_green_exit();
        led_state = LIGHT_STATE_BOTH;
        light_both_entry();
      }
      break;
      case LIGHT_STATE_BOTH:
      light_both_do();
      if(serial_received() == "red") {
        light_both_exit();
        led_state = LIGHT_STATE_RED;
        light_red_entry();
      }
      case LIGHT_STATE_RED:
      light_red_do();
      if(serial_received() == "quit") {
        light_red_exit();
        led_state = LIGHT_STATE_OFF;
        light_off_entry();
      }
      break;
  }
}

void light_off_entry() {
  light_off(12);
  light_off(13);
}

void light_off_do() {
  
}

void light_off_exit() {
  
}

void light_green_entry() {
  light_on(12);
}

void light_green_do() {
  
}

void light_green_exit() {

}

void light_both_entry() {
  light_on(13);
}

void light_both_do() {
  
}

void light_both_exit() {
  light_off(12);
}

void light_red_entry() {

}

void light_red_do() {
  
}

void light_red_exit() {
  
}

