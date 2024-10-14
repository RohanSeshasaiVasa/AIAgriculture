#include "DHT.h"

#define DPIN 4 // Pin connected to DHT sensor (GPIO number)
#define DTYPE DHT11 // Define DHT11 or DHT22 sensor type

DHT dht(DPIN, DTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  float tc = dht.readTemperature(false); // Read temperature in Celsius
  float tf = dht.readTemperature(true); // Read temperature in Fahrenheit
  float hu = dht.readHumidity();       // Read humidity

  Serial.print("Temp:");
  Serial.print(tc);
  Serial.print(" C, ");
  Serial.print(tf);
  Serial.print(" F, Hum: ");
  Serial.print(hu);
  Serial.println("%");
}