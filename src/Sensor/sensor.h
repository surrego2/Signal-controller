#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <entities/value.h>

template<class T>
class SensorABC {
    public:
        SensorABC(uint8_t id);
        bool hasChanged();
        ValueABC<T> getValue();
        uint8_t getId();
        void excecute();
    private:
        bool changed;
        T raw_value;
        ValueABC<T> value;
        uint8_t id;
        virtual T read();
};

template<class T>
SensorABC<T>::SensorABC(uint8_t id){
    this->id = id;
}

template<class T>
ValueABC<T> SensorABC<T>::getValue(){
    this->changed = false;
    return this->value;
}

template<class T>
uint8_t SensorABC<T>::getId(){
    return this->value;
}

template<class T>
bool SensorABC<T>::hasChanged(){
    return this->changed;
}

template<class T>
void SensorABC<T>::excecute(){
    T new_value = this->read();
    if(new_value != this->raw_value){
        this->changed = true;
        this->raw_value = new_value;
        this->value = ValueABC<T>(new_value, this->id);
    }
}

#endif