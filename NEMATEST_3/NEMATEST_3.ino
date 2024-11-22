// Määritellään pinssit
#define STEP_PIN1  2   // moottori 1 step
#define DIR_PIN1   5   // moottori 1 direction
#define STEP_PIN2  3   // moottori 2 step
#define DIR_PIN2   6   // moottori 2 direction

// Määritetään täyden kierroksen askelmäärä
const int stepsPerRevolution = 200;

// Moottorit molemmat myötäpäivään
void xhyh(int steps, int speed) {
  digitalWrite(DIR_PIN1, HIGH);
  digitalWrite(DIR_PIN2, HIGH);
  delay(10); // Lyhyt viive suuntamuutoksen rekisteröimiseen

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN1, HIGH);
    digitalWrite(STEP_PIN2, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEP_PIN1, LOW);
    digitalWrite(STEP_PIN2, LOW);
    delayMicroseconds(speed);
  }
}

// Moottorit molemmat vastapäivään
void xlyl(int steps, int speed) {
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, LOW);
  delay(10); // Lyhyt viive suuntamuutoksen rekisteröimiseen

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN1, HIGH);
    digitalWrite(STEP_PIN2, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEP_PIN1, LOW);
    digitalWrite(STEP_PIN2, LOW);
    delayMicroseconds(speed);
  }
}

// Moottori 1 vastapäivään ja moottori 2 myötäpäivään
void xlyh(int steps, int speed) {
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, HIGH);
  delay(10); // Lyhyt viive suuntamuutoksen rekisteröimiseen

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN1, HIGH);
    digitalWrite(STEP_PIN2, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEP_PIN1, LOW);
    digitalWrite(STEP_PIN2, LOW);
    delayMicroseconds(speed);
  }
}

// Moottori 1 myötäpäivään ja moottori 2 vastapäivään
void xhyl(int steps, int speed) {
  digitalWrite(DIR_PIN1, HIGH);
  digitalWrite(DIR_PIN2, LOW);
  delay(10); // Lyhyt viive suuntamuutoksen rekisteröimiseen

  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN1, HIGH);
    digitalWrite(STEP_PIN2, HIGH);
    delayMicroseconds(speed);
    digitalWrite(STEP_PIN1, LOW);
    digitalWrite(STEP_PIN2, LOW);
    delayMicroseconds(speed);
  }
}

void setup() {
  // Asetetaan pinssit ulostuloiksi
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(STEP_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  pinMode(STEP_PIN2, OUTPUT);
}

void loop() {
  // Molemmat moottorit myötäpäivään
  xhyh(2 * stepsPerRevolution, 500);
  delay(1000);

  // Molemmat moottorit vastapäivään
  xlyl(2 * stepsPerRevolution, 500);
  delay(1000);

  // Moottori 1 vastapäivään ja moottori 2 myötäpäivään
  xlyh(2 * stepsPerRevolution, 500);
  delay(1000);

  // Moottori 1 myötäpäivään ja moottori 2 vastapäivään
  xhyl(2 * stepsPerRevolution, 500);
  delay(1000);
}
