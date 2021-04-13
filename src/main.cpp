#include <Arduino.h>
#include <settings.h>
#include <Processors/circular_buffer.h>
#include <Processors/transformer.h>
#include <Sensor/sensor.h>
#include <Sensor/analog_sensor.h>
#include <Sensor/pressure_sensor.h>
#include <Sensor/Temperature_sensor/lm35.h>
#include <Serializers/output.h>

#define VERSION "0.0.0"

CircularBuffer<int> circular = CircularBuffer<int>(10);

//PressureSensor sensor = PressureSensor(0x7e, A0);
LM35 lm35 = LM35(0x7a, A0);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(CONFIG::SENSOR_INPUNT, INPUT);
    pinMode(0, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    lm35.excecute();

    ValueABC<float> raw_read = lm35.getValue();

    Serial.println(raw_read.getValue());
    Serial.println("Hola");

    delay(1000);


}