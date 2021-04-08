#ifndef ANALOG_SENSOR_H
#define ANALOG_SENSOR_H

#include <Arduino.h>
#include <Sensor/sensor.h>

class AnalogSensor : public SensorABC<float> {
    public:
        AnalogSensor(uint8_t id, uint8_t pin, float scale=1):SensorABC<float>(id) {
            this->pin = pin;
            this->scale = scale;
        };
    private:
        uint8_t pin;
        float read();
        float scale;
};


float AnalogSensor::read() {
    return analogRead(this->pin);
}

#endif