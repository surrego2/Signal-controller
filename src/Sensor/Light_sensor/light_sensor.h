#ifndef LIGHT_SENSOR
#define LIGHT_SENSOR

#include <Arduino.h>
#include <Sensor/sensor.h>
#include <Sensor/analog_sensor.h>


class LIGHT: public SensorABC<float> {
    public:
        LIGHT(uint8_t id, uint8_t pin):SensorABC<float>(id) {
            this->pin = pin;
        };
    private:
        uint8_t pin;
        float read();
};


float LIGHT::read() {
    float luz_voltaje = map(analogRead(this->pin),900, 640, 0, 255);
    return luz_voltaje;
}

#endif