#include "GPIO.h"

static volatile GPIO_IO_REG* const GPIO_IN_REG  = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_IN_REG_ADDR);
static volatile GPIO_IO_REG* const GPIO_SET_REG = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_OUT_W1TS_ADDR);
static volatile GPIO_IO_REG* const GPIO_CLR_REG = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_OUT_W1TC_ADDR);

GPIO::GPIO(uint8_t pin_number) : pin(pin_number) {}

void GPIO::write_pin(uint8_t state)
{
    switch (pin)
    {
        case 0: GPIO_SET_REG->pin_0 = PIN_STATE_HIGH; break;
        case 1: GPIO_SET_REG->pin_1 = PIN_STATE_HIGH; break;
        case 2: GPIO_SET_REG->pin_2 = PIN_STATE_HIGH; break;
        case 3: GPIO_SET_REG->pin_3 = PIN_STATE_HIGH; break;
        case 4: GPIO_SET_REG->pin_4 = PIN_STATE_HIGH; break;
        case 5: GPIO_SET_REG->pin_5 = PIN_STATE_HIGH; break;
        case 6: GPIO_SET_REG->pin_6 = PIN_STATE_HIGH; break;
        case 7: GPIO_SET_REG->pin_7 = PIN_STATE_HIGH; break;
        // case 8: if (state) GPIO_SET_REG->pin_8 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_8 = PIN_STATE_LOW; break;
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
        case 3: return GPIO_IN_REG->pin_3;
        case 4: return GPIO_IN_REG->pin_4;
        case 5: return GPIO_IN_REG->pin_5;
        case 6: return GPIO_IN_REG->pin_6;
        default: return 0;
    }
}
