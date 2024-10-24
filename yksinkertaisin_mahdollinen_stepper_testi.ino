// Pin Definitions
#define dirPin 2    // Direction pin for stepper motor
#define stepPin 3   // Step pin for stepper motor
  
void setup() {
  // Set pin modes
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.begin(9600);

  // Set direction (HIGH for one direction)
  digitalWrite(dirPin, HIGH);
}

void loop() {
  // Continuously spin the motor
  Serial.println("loop");
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(1000);  // Step delay (adjust for speed)
  digitalWrite(stepPin, LOW);
  delayMicroseconds(1000);  // Step delay
}
