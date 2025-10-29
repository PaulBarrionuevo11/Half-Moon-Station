#include "Peripherals.h"

Pheripherals::Peripherals() : GPIO()
{
    led(led_pin);
    sensor_ht(sensor_hum_temp_pin);
    init();
}

void Pheripherals::init()
{
    // Turn LED on and off in GREEN
    uint8 state = led->read_pin()

    if(state == PIN_STATE_LOW)
    {
        for(uint32_t i=0; i<2; i++)
        {
            led->write_pin(PIN_STATE_HIGH)
            for (uint32_t i = 0; i < TIME_DELAY; i++);

            led->write_pin(PIN_STATE_LOW)
            for (uint32_t i = 0; i < TIME_DELAY; i++);
        }
    }

}
