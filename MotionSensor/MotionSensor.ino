/*
Sense motion using a radar (Doppler) motion sensor.

The used sensor is an RCWL-0516.
An active buzzer is also used to let you know if a motion is detected.
*/

#define SENSOR_PIN 2
#define BUZZER_PIN 3

int motionDetected;

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  Serial.println("Move, if you're brave enough!");
}

void loop() {
  motionDetected = digitalRead(SENSOR_PIN);

  if (motionDetected == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(200);
}