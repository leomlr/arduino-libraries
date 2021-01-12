#include "seeed_bme680.h"

#define BME_IIC_ADDR  uint8_t(0x76)
Seeed_BME680 bme680(BME_IIC_ADDR);

void bme680_measure() {
  if (bme680.read_sensor_data()) {
    Serial.println("Failed to perform reading");
    return;
  }
}

float get_bme680_temperature() {
  bme680_measure();
  return bme680.sensor_result_value.temperature;
}

float get_bme680_pressure() {
  bme680_measure();
  return bme680.sensor_result_value.pressure;
}

float get_bme680_humidity() {
  bme680_measure();
  return bme680.sensor_result_value.humidity;
}

float get_bme680_gas() {
  bme680_measure();
  return bme680.sensor_result_value.gas;
}


void setup() {
  Serial.begin(9600);
  while(!Serial)
    Serial.println("En attente de l'ouverture du port série...");
  while (!bme680.init()) {
    Serial.println("En attente du capteur BME680...");
    delay(1000);
  }
}

void loop() {
  Serial.println((String("  Temp = ") + String(get_bme680_temperature()) + String(" °C ") + String(" P =  ") + String(get_bme680_pressure()) + String(" Pa") + String("  H = ") + String(get_bme680_humidity()) + String(" %") + String("  G =  ") + String(get_bme680_gas()) + String(" Ohm")));
  delay(1000);
}
