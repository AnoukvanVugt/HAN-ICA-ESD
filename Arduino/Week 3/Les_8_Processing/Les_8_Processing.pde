import processing.serial.*;

Serial serielePoort;
final int BAUDRATE = 9600;
final int VOLGNUMMER = 0;

void setup() {
 String portName = Serial.list()[VOLGNUMMER];
 serielePoort = new Serial(this, portName, BAUDRATE);
}

void draw() {
 if (serielePoort.available() > 0) {
 String gelezenWaarden = serielePoort.readStringUntil('\n');
 int sum;
 for (int i = 0; i < ; i++) {
    sum = (sum + gelezenWaarden.charAt(i)) % 128;
 }
 if(sum == int(list[list.length - 1])) {
 println(list[list.length -1]);
 }
 }
}