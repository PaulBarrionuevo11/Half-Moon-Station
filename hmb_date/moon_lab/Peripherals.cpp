#include "Peripherals.h"

<<<<<<< Updated upstream:hmb_date/moon_lab/Peripherals.cpp
Pheripherals::Peripherals() :
    led(led_pin);
    sensor_ht(sensor_hum_temp_pin);
{

=======
Pheripherals::Peripherals() 
{
>>>>>>> Stashed changes:HMB.v.1.1/moon_lab/Peripherals.cpp
    init();
}

void Pheripherals::init()
{

    led->write_pin(PIN_STATE_LOW);  // Ensure LED starts off
    toggle_led();

}
// Toggle LED state
void Peripherals::toggle_led()
{
    uint8 state = led->read_pin();
    
    for(uint32_t i=0; i<5; i++)
    {
        led->write_pin(PIN_STATE_HIGH)
        for (uint32_t j = 0; j < 100000; j++);

        led->write_pin(PIN_STATE_LOW)
        for (uint32_t j = 0; j < 100000; j++);
    }
    led->write_pin(PIN_STATE_LOW);
}

// Example: set sensor pin high manually
void Peripherals::set_sensor_pin_high()
{
    sensor_hum_temp_pin.write_pin(PIN_STATE_HIGH);
}

// Example: read a pin
uint8_t Peripherals::read_sensor_pin()
{
    return sensor_hum_temp_pin.read_pin();
}
