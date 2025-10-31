#include "GPIO.h"

static volatile GPIO_IO_REG* const GPIO_IN_REG  = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_IN_REG_ADDR);
static volatile GPIO_IO_REG* const GPIO_SET_REG = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_OUT_W1TS_ADDR);
static volatile GPIO_IO_REG* const GPIO_CLR_REG = reinterpret_cast<volatile GPIO_IO_REG*>(GPIO_OUT_W1TC_ADDR);

GPIO::GPIO(uint8_t pin_number) : pin(pin_number) {}

void GPIO::write_pin(uint8_t state)
{
    switch (pin)
    {
        case 0: if (state) GPIO_SET_REG->pin_0 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_0 = PIN_STATE_LOW; break;
        case 1: if (state) GPIO_SET_REG->pin_1 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_1 = PIN_STATE_LOW; break;
        case 2: if (state) GPIO_SET_REG->pin_2 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_2 = PIN_STATE_LOW; break;
        case 3: if (state) GPIO_SET_REG->pin_3 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_3 = PIN_STATE_LOW; break;
        case 4: if (state) GPIO_SET_REG->pin_4 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_4 = PIN_STATE_LOW; break;
        case 5: if (state) GPIO_SET_REG->pin_5 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_5 = PIN_STATE_LOW; break;
        case 6: if (state) GPIO_SET_REG->pin_6 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_6 = PIN_STATE_LOW; break;
        case 7: if (state) GPIO_SET_REG->pin_7 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_7 = PIN_STATE_LOW; break;
        case 8: if (state) GPIO_SET_REG->pin_8 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_8 = PIN_STATE_LOW; break;
        case 9: if (state) GPIO_SET_REG->pin_9 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_9 = PIN_STATE_LOW; break;
        case 10: if (state) GPIO_SET_REG->pin_10 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_10 = PIN_STATE_LOW; break;
        case 11: if (state) GPIO_SET_REG->pin_11 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_11 = PIN_STATE_LOW; break;
        case 12: if (state) GPIO_SET_REG->pin_12 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_12 = PIN_STATE_LOW; break;
        case 13: if (state) GPIO_SET_REG->pin_13 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_13 = PIN_STATE_LOW; break;
        case 14: if (state) GPIO_SET_REG->pin_14 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_14 = PIN_STATE_LOW; break;
        case 15: if (state) GPIO_SET_REG->pin_15 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_15 = PIN_STATE_LOW; break;
        case 16: if (state) GPIO_SET_REG->pin_16 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_16 = PIN_STATE_LOW; break;
        case 17: if (state) GPIO_SET_REG->pin_17 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_17 = PIN_STATE_LOW; break;
        case 18: if (state) GPIO_SET_REG->pin_18 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_18 = PIN_STATE_LOW; break;
        case 19: if (state) GPIO_SET_REG->pin_19 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_19 = PIN_STATE_LOW; break;
        case 20: if (state) GPIO_SET_REG->pin_20 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_20 = PIN_STATE_LOW; break;
        case 21: if (state) GPIO_SET_REG->pin_21 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_21 = PIN_STATE_LOW; break;
        case 22: if (state) GPIO_SET_REG->pin_22 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_22 = PIN_STATE_LOW; break;
        case 23: if (state) GPIO_SET_REG->pin_23 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_23 = PIN_STATE_LOW; break;
        case 24: if (state) GPIO_SET_REG->pin_24 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_24 = PIN_STATE_LOW; break;
        case 25: if (state) GPIO_SET_REG->pin_25 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_25 = PIN_STATE_LOW; break;
        case 26: if (state) GPIO_SET_REG->pin_26 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_26 = PIN_STATE_LOW; break;
        case 27: if (state) GPIO_SET_REG->pin_27 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_27 = PIN_STATE_LOW; break;
        case 28: if (state) GPIO_SET_REG->pin_28 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_28 = PIN_STATE_LOW; break;
        case 29: if (state) GPIO_SET_REG->pin_29 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_29 = PIN_STATE_LOW; break;
        case 30: if (state) GPIO_SET_REG->pin_30 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_30 = PIN_STATE_LOW; break;
        case 31: if (state) GPIO_SET_REG->pin_31 = PIN_STATE_HIGH; else GPIO_CLR_REG->pin_31 = PIN_STATE_LOW; break;
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
