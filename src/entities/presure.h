#ifndef PRESSURE_H
#define PRESSURE_H

#include <Arduino.h>
#include <entities/value.h>

class Pressure : public ValueABC<float> {
    public:
        Pressure():ValueABC(){};
        Pressure(float value, uint8_t source):ValueABC(value, source){};
};

#endif