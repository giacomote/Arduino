/*
Measure weight using a load cell.

Connect the Arduino and it will start measuring weight (in grams).
*/

#include <Adafruit_HX711.h>

#define DATA_PIN 2
#define CLK_PIN 3

// HX711 configuration
Adafruit_HX711 loadCell(DATA_PIN, CLK_PIN);

// Global variables
float calibration = 415.34;
double weight;

char weightStr[15];
char out[20];

// Business logic
void setup() {
  Serial.begin(9600);
  loadCell.begin();

  Serial.println("Tareing ...");
  loadCell.tareA(loadCell.readChannelRaw(CHAN_A_GAIN_128));
}

void loop() {
  weight = loadCell.readChannelBlocking(CHAN_A_GAIN_128) / calibration;

  dtostrf(weight, 1, 2, weightStr);
  sprintf(out, "$%s;", weightStr);
  Serial.println(out);

  delay(200);
}
