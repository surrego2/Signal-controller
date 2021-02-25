#ifndef SETTINGS_H
#define SETTINGS_H

namespace Settings {
    const String VERSION = "0.0.0";
    const int LED = 13;
    const int POTENCIOMETRO = 0;

     void initSettings() {   
        pinMode(LED, OUTPUT);
        pinMode(POTENCIOMETRO, INPUT);
     }
}

#endif