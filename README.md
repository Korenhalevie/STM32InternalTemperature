# 🛠️ STM32InternalTemperature

This project is an example and library to read the **internal temperature sensor** of STM32 microcontrollers using the **Arduino Framework**. The code is written in C++ and uses an object-oriented approach for better reusability and scalability.

---

## 🌟 Overview

STM32 microcontrollers have a built-in temperature sensor that allows you to measure the internal temperature of the chip. This project:
- Reads the internal temperature.
- Calculates the temperature in **Celsius (°C)** and **Fahrenheit (°F)**.
- Displays the results via the **Serial Monitor**.

---

## ✨ Features

- Reads the STM32's **internal temperature sensor**.
- Displays temperature in **Celsius** and **Fahrenheit**.
- Object-Oriented Design for cleaner and reusable code.
- Compatible with **Arduino IDE** and **PlatformIO**.

---

## ✅ Compatibility

- **STM32 Microcontrollers**: Tested on **STM32F4 series** (e.g., STM32F401CCU6), but should work with any STM32 that has an internal temperature sensor.
- **Development Environments**:
  - **Arduino IDE**
  - **PlatformIO**

---

## 🧰 Getting Started

### 📝 Prerequisites

To use this project, you will need:
1. **STM32 microcontroller** (e.g., STM32F401, STM32F103).
2. **STLink programmer** for uploading and debugging.
3. **Arduino IDE** or **PlatformIO** (whichever you prefer).
4. **STM32duino** library (if using the Arduino IDE).

---

### ⚙️ Setting Up in PlatformIO

If you're using **PlatformIO**, add the following configuration to your `platformio.ini` file to enable uploading via STLink and Serial communication:

```ini
upload_protocol = stlink
build_flags = -D PIO_FRAMEWORK_ARDUINO_ENABLE_CDC
