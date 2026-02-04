/*
Control an external motor (fan) using an N-MOS transistor.

The program receives an input string, which can be either "ON\n" or "OFF\n".
If the string is "ON\n", the motor (fan) is switched on.
If the string is "OFF\n", the motor (fan) is switched off.
*/

#define MOTOR_PIN 10

String s;

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);

  digitalWrite(MOTOR_PIN, LOW);
}

void loop() {
  if (Serial.available()) {
    s = Serial.readStringUntil('\n');
  }

  if (s == "ON") digitalWrite(MOTOR_PIN, HIGH);
  else if (s == "OFF") digitalWrite(MOTOR_PIN, LOW);
}
