/*
Control an external motor (fan) using an N-MOS transistor and a PWM.

The program receives an input number, which can be in the [0, 100] range.
That number is the percentage of the maximum speed to run the motor (fan).

NOTE: Pay attention not to send newline or carriage return at the end.
*/

#define MOTOR_PIN 10

int duty;
int pwmValue;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);

  digitalWrite(MOTOR_PIN, LOW);
}

void loop() {
  if (Serial.available()) {
    duty = Serial.parseInt();
  }

  duty = constrain(duty, 0, 100);  // fix "duty" in a certain range
  pwmValue = map(duty, 0, 100, 0, 255);  // convert to percentage

  analogWrite(MOTOR_PIN, pwmValue);  // activate PWM (default 490 Hz frequency)
}
