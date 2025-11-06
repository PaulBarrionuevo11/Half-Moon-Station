#include "DHT22.h"

DHT22::DHT22() {
    Peripherals peripherals;
}

float DHT22::getHumidity()
{
    hum = peripherals.read_sensor_pin();
    return _hum;
}
float DHT22::getTemperature()
{

}
void DHT22::setTemperature(uint32_t _hum)
{

}
void DHT22::setHumidity(uint32_t _temp)
{

}
void DHT22::resetSensor()
{
    
}

