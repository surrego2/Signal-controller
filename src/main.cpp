#include <Arduino.h>
#include <settings.h>
#include <Processors/circular_buffer.h>
#include <Processors/transformer.h>
#include <Sensor/sensor.h>
#include <Sensor/analog_sensor.h>
#include <Sensor/pressure_sensor.h>
#include <Serializers/output.h>

#define VERSION "0.0.0"

CircularBuffer<int> circular = CircularBuffer<int>(10);

PressureSensor sensor = PressureSensor(0x7e, A0);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
    Settings::initSettings();
}