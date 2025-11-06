#ifndef DHT22_H_
#define DHT22_H_

#include<stdint.h>
#include "GPIO.h"

class DHT22:
{
public:
    DHT22();
    float getHumidity() const { return temp; };
    float getTemperature() const { return hum; };

    void setTemperature(uint32_t _hum);
    void setHumidity(uint32_t _temp);
    void resetSensor(); //flip state of gpio pin

private:
    uint32_t temp;
    uint32_t hum;
    GPIO* gpio;


};

#endif

