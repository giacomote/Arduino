/*
Use a DHT22 sensor to read temperature and relative humidity.

To correctly test this code, connect the DHT sensor to digital pin 10 and open the serial port plotter.
NOTE: The used serial port plotter is the one here: https://github.com/CieNTi/serial_port_plotter.
*/

#include <DHT.h>

// DHT sensor configuration
#define DHTPIN 10
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Global variables
char tempStr[10];
char humStr[10];
char out[30];

// Business logic
void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  dtostrf(temp, 0, 2, tempStr);
  dtostrf(hum, 0, 2, humStr);

  sprintf(out, "$%s %s;", tempStr, humStr);
  Serial.println(out);

  delay(200);
}
