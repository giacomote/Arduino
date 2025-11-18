/*
Measure acceleration using the onboard IMU sensor (on the Uno WiFi Rev2 board).

NOTE: The acceleration unit is m/s2.
NOTE: No external circuit is required, as the IMU sensor is already integrated onboard.
*/

#include <Arduino_LSM6DS3.h>

// Global variables
float x, y, z;

char accx[20];
char accy[20];
char accz[20];
char out[50];

void setup() {
  Serial.begin(9600);
  IMU.begin();
}

void loop() {
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    // g to m/s2 conversion
    x *= 9.81;
    y *= 9.81;
    z *= 9.81;

    dtostrf(x, 1, 2, accx);
    dtostrf(y, 1, 2, accy);
    dtostrf(z, 1, 2, accz);

    sprintf(out, "$%s %s %s;", accx, accy, accz);
    Serial.println(out);
  }
}
