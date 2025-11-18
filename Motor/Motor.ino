/*
Control an external motor (fan) using an N-MOS transistor.

The program receives an input string, which can be either "ON\n" or "OFF\n".
If the string is "ON\n", the motor (fan) is switched on.
If the string is "OFF\n", the motor (fan) is switched off.

The circuit used is the one shown here: https://www.tinkercad.com/things/9lSNsUSi3QE-motor
*/

String s;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);

  digitalWrite(10, LOW);
}

void loop() {
  if (Serial.available()) {
    s = Serial.readStringUntil('\n');
  }

  if (s == "ON") digitalWrite(10, HIGH);
  else if (s == "OFF") digitalWrite(10, LOW);
}
