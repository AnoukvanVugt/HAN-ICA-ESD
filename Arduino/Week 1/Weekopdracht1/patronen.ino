const int NUMBEROFLEDSP = getNUMBEROFLEDS();
int vertraging = 500;
int patroonlengte;

int getVertraging() {
  return vertraging;
}

void patroonH() {
  patroonlengte = 8;
  int LEDsequence [patroonlengte][NUMBEROFLEDSP] = {
    {1, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1}
  };
  for (int patroonnummer = 0; patroonnummer < patroonlengte; patroonnummer++) {
    for (int lednummer = 0; lednummer < NUMBEROFLEDSP; lednummer++) {
      if (LEDsequence[patroonnummer][lednummer] == 1) {
        ledControlSetLedOn(lednummer);
      } else {
        ledControlSetLedOff(lednummer);
      }
    }
    delay(vertraging);
  }
  ledControlAllLedsOff();
}

void patroonS() {
  patroonlengte = 4;
  int LEDsequence [patroonlengte][NUMBEROFLEDSP] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0}
  };
  for (int patroonnummer = 0; patroonnummer < patroonlengte; patroonnummer++) {
    for (int lednummer = 0; lednummer < NUMBEROFLEDSP; lednummer++) {
      if (LEDsequence[patroonnummer][lednummer] == 1) {
        ledControlSetLedOn(lednummer);
      } else {
        ledControlSetLedOff(lednummer);
      }
    }
    delay(vertraging);
  }
  ledControlAllLedsOff();
}

void patroons() {
  patroonlengte = 4;
  int LEDsequence [patroonlengte][NUMBEROFLEDSP] = {
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
  };
  for (int patroonnummer = 0; patroonnummer < patroonlengte; patroonnummer++) {
    for (int lednummer = 0; lednummer < NUMBEROFLEDSP; lednummer++) {
      if (LEDsequence[patroonnummer][lednummer] == 1) {
        ledControlSetLedOn(lednummer);
      } else {
        ledControlSetLedOff(lednummer);
      }
    }
    delay(vertraging);
  }
  ledControlAllLedsOff();
}

void patroonR() {
  patroonlengte = 8;
  int LEDsequence [patroonlengte][NUMBEROFLEDSP] = {
    {1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 1}
  };
  for (int patroonnummer = 0; patroonnummer < patroonlengte; patroonnummer++) {
    for (int lednummer = 0; lednummer < NUMBEROFLEDSP; lednummer++) {
      if (LEDsequence[patroonnummer][lednummer] == 1) {
        ledControlSetLedOn(lednummer);
      } else {
        ledControlSetLedOff(lednummer);
      }
    }
    delay(vertraging);
  }
  ledControlAllLedsOff();
}

void patroonL() {
  patroonlengte = 8;
  int LEDsequence [patroonlengte][NUMBEROFLEDSP] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 1, 1, 1, 1},
    {0, 0, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
  };
  for (int patroonnummer = 0; patroonnummer < patroonlengte; patroonnummer++) {
    for (int lednummer = 0; lednummer < NUMBEROFLEDSP; lednummer++) {
      if (LEDsequence[patroonnummer][lednummer] == 1) {
        ledControlSetLedOn(lednummer);
      } else {
        ledControlSetLedOff(lednummer);
      }
    }
    delay(vertraging);
  }
  ledControlAllLedsOff();
}

void patroonE() {
  ledControlAllLedsOff();
}

void patroonPlus() {
  if (vertraging < 1000) {
    vertraging = vertraging + 50;
  } 
}

void patroonMinus() {
  if (vertraging > 50) {
    vertraging = vertraging - 50;
  }
}

