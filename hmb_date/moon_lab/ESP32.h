#ifndef ESP32_H_
#define ESP32_H_

#include "Peripherals.h"

class ESP32: public Pheripherals
{
private:
    /* data */
public:
    ESP32(/* args */);
    ~ESP32();

};

ESP32::ESP32(/* args */)
{
    Pheripherals gpio;
}

ESP32::~ESP32()
{
}



#endif 