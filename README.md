# I2C Multi-Board Water Quality & Temperature Monitoring System

This project implements a **multi-board sensor monitoring system** using **I2C communication** between a master board and multiple slave boards.  
It monitors **water turbidity** and **temperature**, displays readings on an LCD, and activates a buzzer when unsafe conditions are detected.

---

## 📌 Project Overview

### **Master Board**
- Requests data from all slave boards via I2C  
- Displays readings on the I2C LCD  
- Triggers alert LED and buzzer  
- Writes alert status into EEPROM  
- Controls the logic of the entire system  

---

### **Slave Board 1 – Water Turbidity Sensor**
- Reads turbidity sensor using ADC  
- Sends water status to master:
  - `0` → water clean  
  - `1` → water dirty  
- No actuator control—only senses and responds to master requests  

---

### **Slave Board 2 – Temperature Sensor (LM35)**
- Reads LM35 analog temperature  
- Sends the measured temperature (in °C) to the master  
- Master triggers alert if temperature exceeds threshold  
  - Default: **25°C**

---

### **Slave Board 3 – Buzzer Controller**
- Receives a single byte from the master  
  - `1` → buzzer ON  
  - `0` → buzzer OFF  
- Written using low-level **AVR register programming**  
- Controls only the buzzer—no sensing operations  

---

## 🔧 Hardware Requirements

- 1 × Master Arduino/ATmega board  
- 3 × Slave Arduino/ATmega boards  
- LM35 temperature sensor  
- Turbidity sensor  
- I2C LCD display  
- Buzzer  
- 4.7kΩ resistors for I2C pull-ups  
- Jumper wires  

---

## 🔌 System Logic

1. **Master polls Slave 1**  
   - Dirty water → alert ON  

2. **Master polls Slave 2**  
   - Temperature > threshold → alert ON  

3. **Master sends command to Slave 3**  
   - `1` to activate buzzer  
   - `0` to deactivate buzzer  

4. **LCD displays:**  
   - Temperature  
   - Water status  
   - “ALERT” messages  

---

## 🛠 Changing the Temperature Threshold

Find this line in the master code:

```cpp
const float TEMP_THRESHOLD = 25.0;
