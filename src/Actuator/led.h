#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <Actuator/actuator.h>
#include <entities/signal.h>

class Led : public ActuatorABC<float> {
    public:
        Led(uint8_t id, uint8_t pin):ActuatorABC<float>(id){
            this->pin=pin;
        }
    private:
        uint8_t pin;
        void write(ValueABC<float> value);
};

void Led::write(ValueABC<float> value) {
    uint8_t discrete_value = value.getValue();
    Serial.print("Output led: ");
    Serial.println(discrete_value);
    analogWrite(this->pin, discrete_value);
}

#endif