#ifndef STM32_TEMPERATURE_SENSOR_H
#define STM32_TEMPERATURE_SENSOR_H

#include <Arduino.h>

class STM32TemperatureSensor {
private:
  static constexpr uint32_t TS_CAL1_ADDR = 0x1FFF7A2C; // Temp calibration @ 30°C
  static constexpr uint32_t TS_CAL2_ADDR = 0x1FFF7A2E; // Temp calibration @ 110°C
  static constexpr float TEMP30_CAL_TEMP = 30.0f;
  static constexpr float TEMP110_CAL_TEMP = 110.0f;

  void enableTemperatureSensor();      // Enable temp sensor and ADC
  uint16_t readRawTemperature();       // Read raw ADC value
  float convertTemperature(uint16_t);  // Convert raw value to Celsius

public:
  STM32TemperatureSensor();            // Constructor
  float getTemperature();              // Public method to read temperature in Celsius
  float getTemperatureF();             // Public method to read temperature in Fahrenheit 
};

#endif
