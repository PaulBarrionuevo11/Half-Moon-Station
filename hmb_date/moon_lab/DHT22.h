#ifndef DHT22_H_
#define DHT22_H_

#include<stdint.h>

class DHT22
{
public:
    DHT22();

    float getHumidity();
    float getTemperature();

    void setTemperature(uint32_t _hum);
    void setHumidity(uint32_t _temp);
    void resetSensor();

private:
    uint32_t temp;
    uint32_t hum;

};

#endif

