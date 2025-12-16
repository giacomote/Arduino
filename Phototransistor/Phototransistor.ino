/*
Detect the presence of infrared light using a phototransistor.

The used phototransistor is the BPY62.
An infrared LED is required to illuminate the phototransistor.

NOTE: The LED and phototransistor must be perfectly aligned.
*/

const int phototransistor = 2;
int lightDetected;

void setup() {
  pinMode(phototransistor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ready to be illuminated!");
}

void loop() {
  lightDetected = digitalRead(phototransistor);

  if (lightDetected == 1) {
    Serial.println("Light Detected!");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else digitalWrite(LED_BUILTIN, LOW);

  delay(200);
}