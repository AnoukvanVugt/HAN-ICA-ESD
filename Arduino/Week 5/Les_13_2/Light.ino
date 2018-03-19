const int PINARRAY [] = {12, 13};
const int NUMBEROFLEDS = 2;

void light_setup() {
  pinMode(PINARRAY[0], OUTPUT);
  pinMode(PINARRAY[1], OUTPUT);
}

void light_on(int nummer) {
  digitalWrite(PINARRAY[nummer], HIGH);
}

void light_off(int nummer) {
  digitalWrite(PINARRAY[nummer], LOW);
}

