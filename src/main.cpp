#include <Arduino.h>
#include <settings.h>
#include <Processors/circular_buffer.h>
#include <Processors/transformer.h>
#include <Sensor/Light_sensor/light_sensor.h>
#include <Serializers/output.h>
#include <Actuator/led.h>
#include <entities/signal.h>

#define VERSION "0.0.0"

CircularBuffer<int> circular = CircularBuffer<int>(10);

//PressureSensor sensor = PressureSensor(0x7e, A0);
LIGHT light = LIGHT(0x7a, A0);
Led led = Led(0xAB, 3);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(CONFIG::SENSOR_INPUT, INPUT);
    //pinMode(3, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    light.excecute();

    if (light.hasChanged()){      
      ValueABC<float> value = light.getValue();

      led.setValue(value);

      Serial.print("Intensidad luminica: ");
      Serial.println(value.getValue()); 

      led.excecute();
    }
    delay(1000);
}