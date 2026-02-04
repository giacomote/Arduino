/*
Toggle a LED by sending a string through a serial connection.

If the sent string is "ON\n", then toggle on a LED on pin 10.
If the sent string is "OFF\n", then toggle off the LED.
*/

#define LED_PIN 10

String s;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  if (Serial.available()) {
    s = Serial.readStringUntil('\n');
  }

  if (s == "ON") digitalWrite(10, HIGH);
  else if (s == "OFF") digitalWrite(LED_PIN, LOW);
}
