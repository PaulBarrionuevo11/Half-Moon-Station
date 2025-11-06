#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

#include "GPIO.h"
#include <stdint.h>

#define LED_PIN                 (8)
#define SENSOR_HUM_TEMP_PIN     (9)

<<<<<<< Updated upstream:hmb_date/moon_lab/Peripherals.h
class Pheripherals
=======
class Pheripherals:
>>>>>>> Stashed changes:HMB.v.1.1/moon_lab/Peripherals.h
{
    public:
        Pheripherals();
        void init();
        void toggle_led();
        // void set_sensor_pin_high();
        // uint8_t read_sensor_pin();

    private:
        GPIO led(LED_PIN);
        GPIO sensor(SENSOR_HUM_TEMP_PIN);
};

#endif // PERIPHERALS_H_