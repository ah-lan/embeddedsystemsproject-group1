#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define TEMP_SENSOR_SLAVE_ADDRESS 0x01
#define TURBIDITY_SENSOR_SLAVE_ADDRESS 0x02
#define BUZZER_SLAVE_ADDRESS 0x03
#define TURBIDITY_THRESHOLD 500
#define EEPROM_TEMPERATURE_ADDR 0 // EEPROM address for storing temperature
#define EEPROM_TURBIDITY_ADDR 2   // EEPROM address for storing turbidity
// LCD Pins
#define RS 12
#define EN 11
#define D4 4
#define D5 5
#define D6 3
#define D7 2

volatile uint16_t temperatureC = 0;
volatile uint16_t turbidity = 0;
unsigned long lastDisplayUpdate = 0;
const unsigned long displayInterval = 1000; // 1-second interval for LCD update

#define REG(addr) (*((volatile uint8_t *)(addr)))
#define SFR_BIT_SET(sfr, bit) (REG(sfr) |= (1 << (bit)))
#define SFR_BIT_CLEAR(sfr, bit) (REG(sfr) &= ~(1 << (bit)))
#define SFR_BIT_READ(sfr, bit) (REG(sfr) & (1 << (bit)))
#define SFR_WRITE(sfr, value) (REG(sfr) = (value))
#define SFR_READ(sfr) (REG(sfr))
