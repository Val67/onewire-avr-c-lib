// Librairie OneWire pour AVR
// (c) 2012 Val
#define F_CPU 8000000UL
#define ONEWIRE_DDR DDRD
#define ONEWIRE_PIN PIND
#define ONEWIRE PD6
#define ONEWIRE_HIGH ONEWIRE_DDR &= ~_BV(ONEWIRE);
#define ONEWIRE_LOW ONEWIRE_DDR |= _BV(ONEWIRE);
#include <avr/io.h>
#include <util/delay.h>

void OneWireReset();
void OneWireWrite(uint8_t bit);
uint8_t OneWireRead();
void OneWireWrite8(uint8_t byte);
uint8_t OneWireRead8();
