int ledpin = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);

  knipperLamp(2, 0, 1);
  knipperLamp(2, 2, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  //zonder for, while of methode
  //  digitalWrite(ledpin, HIGH);
  //  delay(500);
  //  digitalWrite(ledpin, LOW);
  //  delay(500);
  //  digitalWrite(ledpin, HIGH);
  //  delay(500);
  //  digitalWrite(ledpin, LOW);
  //  delay(500);
  //  digitalWrite(ledpin, HIGH);
  //  delay(250);
  //  digitalWrite(ledpin, LOW);
  //  delay(250);
  //  digitalWrite(ledpin, HIGH);
  //  delay(250);
  //  digitalWrite(ledpin, LOW);
  //  delay(250);
  //  digitalWrite(ledpin, HIGH);
  //  delay(250);
  //  digitalWrite(ledpin, LOW);
  //  delay(250);
  //  digitalWrite(ledpin, HIGH);
  //  delay(250);
  //  digitalWrite(ledpin, LOW);
  //  delay(250);

  //met while-loop
  //  int vertraging = 500;
  //  int vertraging2 = 250;
  //  int totaleVertraging = 500;
  //  digitalWrite(ledpin, HIGH);
  //  delay(vertraging);
  //  while ((totaleVertraging > 500 && totaleVertraging <= 1000) || (totaleVertraging > 1500 && totaleVertraging <= 2000) || (totaleVertraging > 2250 && totaleVertraging <= 2500) || (totaleVertraging > 2750 && totaleVertraging <= 3000) || (totaleVertraging > 3250 && totaleVertraging <= 3500)) {
  //    digitalWrite(ledpin, LOW);
  //    if (totaleVertraging <= 2000) {
  //      delay(vertraging);
  //      totaleVertraging = totaleVertraging + vertraging;
  //    } else {
  //      delay(vertraging2);
  //      totaleVertraging = totaleVertraging + vertraging2;
  //    }
  //  }
  //  while ((totaleVertraging > 1000 && totaleVertraging <= 1500) || (totaleVertraging > 2000 && totaleVertraging <= 2250) || (totaleVertraging > 2500 && totaleVertraging <= 2750) || (totaleVertraging > 3000 && totaleVertraging <= 3250) || (totaleVertraging > 3500 && totaleVertraging <= 3750)) {
  //    digitalWrite(ledpin, HIGH);
  //    if (totaleVertraging <= 2000) {
  //      delay(vertraging);
  //      totaleVertraging = totaleVertraging + vertraging;
  //    } else {
  //      delay(vertraging2);
  //      totaleVertraging = totaleVertraging + vertraging2;
  //    }
  //  }

  //met for-loop
  //  for(int i = 0; i <= 4000 ; i = i + 250) {
  //    if(i == 500 || i == 1500) {
  //      digitalWrite(ledpin, HIGH);
  //      delay(500);
  //    }else if (i == 0 || i == 1000 || i == 2000) {
  //      digitalWrite(ledpin, LOW);
  //      delay(500);
  //    }
  //    if(i == 2250 || i == 2750 || i == 3250 || i == 3750) {
  //      digitalWrite(ledpin, HIGH);
  //      delay(250);
  //    } else if (i == 2500 || i == 3000 || i == 3500 || i == 4000) {
  //      digitalWrite(ledpin, LOW);
  //      delay(250);
  //    }
  //  }
}

//met Functie
void knipperLamp (int duur, int vorigeDuur, int frequentie) {
  //frequentie is hoe vaak hij helemaal rond gaat (aan en uit) per seconde
  //duur is het aantal seconden dat hij op dit tempo aan en uit moet gaan
  // 1000 / frequentie / 2 is hoe lang hij aan en hoe lang hij uit moet
  int vertraging = (1000 / frequentie) / 2;
  for (int i = 0 + vorigeDuur; i < duur + vorigeDuur; i++) {
    digitalWrite(ledpin, HIGH);
    delay(vertraging);
    digitalWrite(ledpin, LOW);
    delay(vertraging);
  }
}
