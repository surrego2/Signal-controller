#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include <Arduino.h>
#include <Sensor/analog_sensor.h>

class PressureSensor : public AnalogSensor {
    public:
        PressureSensor(uint8_t id, uint8_t pin):AnalogSensor(id,pin,0.72) {
        };
};

#endif