
#include "hw262.h"

uint16_t number = 0;
uint64_t currentTime;
uint64_t elapsedTime = 0;
uint64_t intervalTime = 100;

void setup()
{
    Serial.begin(115200);
    HW262.begin();
    HW262.clearDisplay();
}


void loop()
{
    currentTime = millis();
    uint32_t temperature = HW262.tempSensor.measureCentigrads();
    Serial.println(String(temperature)+" °C");
    while(elapsedTime<intervalTime)
    {   
        elapsedTime = millis()-currentTime;
        HW262.writeNumber(temperature);
    }
    elapsedTime = 0;
}

