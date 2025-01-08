#include "STM32TemperatureSensor.h"

// Constructor
STM32TemperatureSensor::STM32TemperatureSensor() {
  enableTemperatureSensor();
}

// Enable temperature sensor and ADC
void STM32TemperatureSensor::enableTemperatureSensor() {
  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;  // Enable ADC1 clock
  ADC->CCR |= ADC_CCR_TSVREFE;         // Enable temp sensor and VREFINT
  ADC1->CR2 |= ADC_CR2_ADON;           // Enable ADC
  delay(1);                            // Wait for stabilization
}

// Read raw temperature data from ADC
uint16_t STM32TemperatureSensor::readRawTemperature() {
  ADC1->SQR3 = 16;                  // Select channel 16 for temp sensor
  ADC1->CR2 |= ADC_CR2_SWSTART;     // Start ADC conversion
  while (!(ADC1->SR & ADC_SR_EOC)); // Wait for conversion to complete
  return ADC1->DR;                  // Return the raw ADC value
}

// Convert raw ADC value to temperature in °C
float STM32TemperatureSensor::convertTemperature(uint16_t rawValue) {
  uint16_t TS_CAL1 = *((uint16_t*) TS_CAL1_ADDR); // Read calibration value @ 30°C
  uint16_t TS_CAL2 = *((uint16_t*) TS_CAL2_ADDR); // Read calibration value @ 110°C

  return ((rawValue - TS_CAL1) * (TEMP110_CAL_TEMP - TEMP30_CAL_TEMP)) /
         (TS_CAL2 - TS_CAL1) + TEMP30_CAL_TEMP;
}

// Public method to get the current temperature
float STM32TemperatureSensor::getTemperature() {
  uint16_t rawValue = readRawTemperature();
  return convertTemperature(rawValue);
}

float STM32TemperatureSensor::getTemperatureF() {
  float temperatureC = getTemperature();
  return (temperatureC * 9.0 / 5.0) + 32.0;
}