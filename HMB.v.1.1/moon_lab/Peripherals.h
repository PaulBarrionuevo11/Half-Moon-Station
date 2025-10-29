#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

#include "GPIO.h"
#include <stdint.h>

#define LED_PIN                 (8)
#define SENSOR_HUM_TEMP_PIN     (9)

class Pheripherals: public GPIO()
{
    public:
        Pheripherals();
        void init();

    private:
        GPIO* led;
        GPIO* sensor_hum_temp;
        uint8_t led_pin = 8;
        uint8_t sensor_hum_temp_pin = 9;


};

#endif // PERIPHERALS_H_