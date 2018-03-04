import processing.serial.*;

Serial serielePoort;
final int BAUDRATE = 9600;
final int VOLGNUMMER = 1;

void setup() {
  String portName = Serial.list()[VOLGNUMMER];
  serielePoort = new Serial(this, portName, BAUDRATE);
}

void draw() {
  if (serielePoort.available() > 0) {
    String gelezenWaarden = serielePoort.readStringUntil(127);
    char[] deData = new char[3];
    if (gelezenWaarden != null) {
      deData[0] = gelezenWaarden.charAt(1);
      deData[1] = gelezenWaarden.charAt(2);
      deData[2] = gelezenWaarden.charAt(3);
      if (gelezenWaarden.charAt(4) == genereerChecksum(deData, 3)) {
        println(gelezenWaarden);
      } else {
       println("Checksum komst niet overeen"); 
      }
    }
  }
}


int genereerChecksum(char waardes[], int nWaardes) {
  int sum = 0;
  for (int i = 0; i < nWaardes; i++) {
    sum = (sum + waardes[i]) % 127;
  }
  return sum;
}