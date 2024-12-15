#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define TEMP_SENSOR_SLAVE_ADDRESS 0x01
#define TURBIDITY_SENSOR_SLAVE_ADDRESS 0x02
#define BUZZER_SLAVE_ADDRESS 0x03
#define TURBIDITY_THRESHOLD 500
#define EEPROM_TEMPERATURE_ADDR 0 // EEPROM address for storing temperature
#define EEPROM_TURBIDITY_ADDR 2   // EEPROM address for storing turbidity

