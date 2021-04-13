#include <Arduino.h>
#include <settings.h>
#include <Processors/circular_buffer.h>
#include <Processors/transformer.h>
#include <Sensor/sensor.h>
#include <Sensor/analog_sensor.h>

#include <Sensor/Temperature_sensor/lm35.h>
#include <Sensor/Light_sensor/light_sensor.h>
#include <Serializers/output.h>

#define VERSION "0.0.0"

CircularBuffer<int> circular = CircularBuffer<int>(10);

//PressureSensor sensor = PressureSensor(0x7e, A0);
LIGHT light = LIGHT(0x7a, A0);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(CONFIG::SENSOR_INPUNT, INPUT);
    pinMode(3, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    light.excecute();

    if (light.hasChanged()){      
      ValueABC<float> luz_voltaje = light.getValue();

      Serial.println("Hola");
      //valuePrinter(Serial, luz_voltaje.getValue(), "Intensidad luminica");
      Serial.println(luz_voltaje.getValue());    
    }

    delay(1000);
}