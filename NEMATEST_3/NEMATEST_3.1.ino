// Määritellään pinssit
#define STEP_PIN1  2   // moottori 1 step
#define DIR_PIN1   5   // moottori 1 direction
#define STEP_PIN2  3   // moottori 2 step
#define DIR_PIN2   6   // moottori 2 direction

// Määritetään täyden kierroksen askelmäärä
const int stepsPerRevolution = 200;
const int DEFAULT_SPEED = 750;

int position[2] = {0,0};

// Yleinen funktio moottoreiden pyörittämiseen tietyssä suunnassa ja nopeudella
void rotatemotors(int steps, bool dir1, bool dir2, int speed) {
  digitalWrite(DIR_PIN1, dir1);
  digitalWrite(DIR_PIN2, dir2);
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

// Molemmat moottorit myötäpäivään
void goRight(int steps, int speed) {
  rotatemotors(steps, HIGH, HIGH, speed);
  position[0] = position[0] + steps;
}

// Molemmat moottorit vastapäivään
void goLeft(int steps, int speed) {
  rotatemotors(steps, LOW, LOW, speed);
  position[0] = position[0] - steps;
}

// Moottori 1 vastapäivään ja moottori 2 myötäpäivään
void goDown(int steps, int speed) {
  rotatemotors(steps, LOW, HIGH, speed);
  position[1] = position[1] + steps;
}

// Moottori 1 myötäpäivään ja moottori 2 vastapäivään
void goUp(int steps, int speed) {
  rotatemotors(steps, HIGH, LOW, speed);
  position[1] = position[1] - steps;
}

void goToPos(int x, int y) {
  int deltaX = x - position[0];
  int deltaY = y - position[1];
  int stepsX = abs(deltaX);
  int stepsY = abs(deltaY);

  if (deltaX < 0) goLeft(stepsX, DEFAULT_SPEED);
  else goRight(stepsX, DEFAULT_SPEED);

  delay(10);

  if (deltaY < 0) goUp(stepsY, DEFAULT_SPEED);
  else goDown(stepsY, DEFAULT_SPEED);
}

void setup() {
  // Asetetaan pinssit ulostuloiksi
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(STEP_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  pinMode(STEP_PIN2, OUTPUT);

  Serial.begin(9600);

  goToPos(100, 100);

  Serial.println(position[0]);
  Serial.println(position[1]);
  Serial.println();
}

void loop() {
  
}
