const int LIGHT_STATE_OFF = 0;
const int LIGHT_STATE_GREEN = 1;
const int LIGHT_STATE_RED = 2;

int led_state;

void sm_light_setup() {
  led_state = LIGHT_STATE_OFF;
  led_off_entry();
}

void light_loop() {
  switch (led_state) {
    case LIGHT_STATE_OFF:
      led_off_do();
      if (serial_received() == 'g') {
        led_off_exit();
        led_state = LIGHT_STATE_GREEN;
        light_green_entry();
      }
      break;
      case LIGHT_STATE_GREEN:
      light_green_do();
      if(serial_received() == 'r') {
        light_green_exit();
        led_state = LIGHT_STATE_RED;
        light_red_entry();
      }
      break;
      case LIGHT_STATE_RED:
      light_red_do();
      if(serial_received() == 'x') {
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
  light_off(12);
}

void light_red_entry() {
  light_on(13);
}

void light_red_do() {
  
}

void light_red_exit() {
  
}

