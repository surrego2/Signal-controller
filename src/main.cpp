#include <Arduino.h>
#include <settings.h>
#include <Processors/circular_buffer.h>
#include <Processors/transformer.h>
#include <Sensors/sensors.h>
#include <Sensors/analog_sensor.h>

#define VERSION "0.0.0"

void setup() {
  // put your setup code here, to run once:
  Settings::initSettings();
}

void loop() {
  // put your main code here, to run repeatedly:
}