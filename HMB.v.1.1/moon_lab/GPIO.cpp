#include "GPIO.h"

static volatile GPIO_IO_REG* const GPIO_IN_REG  = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_IN_REG_ADDR);
static volatile GPIO_IO_REG* const GPIO_SET_REG = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_OUT_W1TS_ADDR);
static volatile GPIO_IO_REG* const GPIO_CLR_REG = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_OUT_W1TC_ADDR);

GPIO::GPIO(uint8_t pin_number) : pin(pin_number) {}

void GPIO::write_pin(uint8_t state)
{
    switch (pin)
    {
        case 0: if (state) GPIO_SET_REG->pin_0 = 1; else GPIO_CLR_REG->pin_0 = 1; break;
        case 1: if (state) GPIO_SET_REG->pin_1 = 1; else GPIO_CLR_REG->pin_1 = 1; break;
        case 2: if (state) GPIO_SET_REG->pin_2 = 1; else GPIO_CLR_REG->pin_2 = 1; break;
        // ... add other pins as needed
        default: break;
    }
}

uint8_t GPIO::read_pin()
{
    switch (pin)
    {
        case 0: return GPIO_IN_REG->pin_0;
        case 1: return GPIO_IN_REG->pin_1;
        case 2: return GPIO_IN_REG->pin_2;
        // ... add other pins as needed
        default: return 0;
    }
}
