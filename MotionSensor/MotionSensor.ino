/*
Sense motion using a radar (Doppler) motion sensor.

The used sensor is an RCWL-0516.
An active buzzer is also used to let you know if a motion is detected.

The circuit configuration is the one indicated here: https://www.tinkercad.com/things/if7ZBTEpc1Q-motionsensor
*/

const int sensorPin = 2;
const int buzzerPin = 3;
int motionDetected;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  Serial.println("Move, if you're brave enough!");
}

void loop() {
  motionDetected = digitalRead(sensorPin);

  if (motionDetected == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(200);
}