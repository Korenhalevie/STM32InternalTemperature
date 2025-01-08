#include "STM32TemperatureSensor.h"

STM32TemperatureSensor tempSensor;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("Reading STM32 Internal Temperature...");
}

void loop()
{
  float temperatureC = tempSensor.getTemperature();
  float temperatureF = tempSensor.getTemperatureF();

  Serial.print("Internal Temperature: ");
  Serial.print(temperatureC);
  Serial.print("°C ");
  Serial.print(temperatureF);
  Serial.println("°F");

  delay(1000);
}
