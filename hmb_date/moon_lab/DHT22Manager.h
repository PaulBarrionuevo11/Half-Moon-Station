#pragma once

#include <stdint.h>
#include "driver/gpio.h"
#include "esp_timer.h"


class DHT22Manager:
{
    public:
        DHT22Manager(int pin);
        
        bool begin();                  // Configure GPIO
        bool readSensor();             // Read 40-bit frame
        
        float readTemperature();       // Last reading
        float readHumidity();          // Last reading

        float convertCtoF(float);
        float convertFtoC(float);
    
    private:
        uint32_t _pin;
        float _temperature;
        float _humidity;

        enum class PinMode { INPUT, OUTPUT };
        void setPinMode(PinMode mode);
        void setPinMode(PinMode mode);
        void delayUs(uint32_t us);
        bool readBit(bool &bit);
};



