#ifndef ACTUATORS_H
#define ACTUATORS_H

#include <Arduino.h>
#include <entities/value.h>

template<class T>
class ActuatorABC {
    public:
        ActuatorABC(uint8_t id);
        void setValue(ValueABC<T> value);
        ValueABC<T> getValue();
        uint8_t getId();
        void excecute();
    private:
        bool hasToChange;
        ValueABC<T> value;
        uint8_t id;
        virtual void write(ValueABC<T> value);
};

template<class T>
ActuatorABC<T>::ActuatorABC(uint8_t id) {
    this->id = id;
};


template<class T>
void ActuatorABC<T>::setValue(ValueABC<T> value) {
    
    this->value = value;
    this->hasToChange = true;
};

template<class T>
uint8_t ActuatorABC<T>::getId() {
    return this->id;
};

template<class T>
void ActuatorABC<T>::excecute() {
    if (this->hasToChange) {
        this->write(this->value);
        this->hasToChange = false;
    }
};

template<class T>
ValueABC<T> ActuatorABC<T>::getValue() {
    return this->value;
};

#endif