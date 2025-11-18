/*
Toggle a LED by sending a string through a serial connection.

If the sent string is "ON\n", then toggle on a LED on pin 10.
If the sent string is "OFF\n", then toggle off the LED.

The circuit configuration is the one indicated here: https://www.tinkercad.com/things/dmWpGz5E9dw-led
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
