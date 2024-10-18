// Example sketch to control a stepper motor with A4988 stepper motor driver 
// and Arduino without a library. 
// More info: https://www.makerguides.com

// Define stepper motor connections and steps per revolution:
#define dirPin 33
#define stepPin 32
#define stepsPerRevolution 200

void setup() {
  // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);
  Serial.println("dir: high");

  // Spin the stepper motor 1 revolution slowly:
for (int i = 0; i < stepsPerRevolution; i++) {
  digitalWrite(stepPin, HIGH);  // Send a HIGH signal to the step pin, initiating a step
  delayMicroseconds(2000);      // Wait for 2 milliseconds
  digitalWrite(stepPin, LOW);   // Send a LOW signal to the step pin, completing the step
  delayMicroseconds(2000);      // Wait for 2 milliseconds before the next step
}
delay(2000);  // 2000 milliseconds = 2 seconds

}
