// Librairie OneWire pour AVR
// (c) 2012 Val
#include "OneWire.h"

// -> Fonctions bas niveau
void OneWireReset() // Envoie un reset
{
    ONEWIRE_LOW;
    _delay_us(480);
    ONEWIRE_HIGH;
    _delay_us(600);
}

void OneWireWrite(uint8_t bit) // Envoie un bit
{
    ONEWIRE_LOW;
    _delay_us(2);
    if(bit)
        ONEWIRE_HIGH;
    _delay_us(58);
    ONEWIRE_HIGH;
}

uint8_t OneWireRead() // Lit un bit
{
    uint8_t bit = 0;

    ONEWIRE_LOW; // Signal de lecture
    _delay_us(2);
    ONEWIRE_HIGH;
    _delay_us(15);
    if(ONEWIRE_PIN & _BV(ONEWIRE)) bit = 1;
    _delay_us(60);
    return bit;
}

// -> Fonctions haut niveau
void OneWireWrite8(uint8_t byte) // Envoie un byte
{
    uint8_t n;
    for(n = 0; n < 8; n++)
    {
        OneWireWrite(byte & 0b00000001); // Envoie le LSB
        byte = byte >> 1;
        _delay_us(2);
    }
}

uint8_t OneWireRead8() // Lit un byte
{
    uint8_t data = 0, n;
    for(n = 0; n < 8; n++)
    {
        data |= OneWireRead() << n;
    }
    return data;
}
