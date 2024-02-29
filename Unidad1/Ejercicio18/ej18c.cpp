#include <Arduino.h>

void task1()
{
    enum class Task1States
    {
    INIT, 
    WAIT_DATA
    };

static Task1States task1state = Task1States::INIT;
static uint8_t rxData[32];
static uint8_t dataCounter = 0;

switch (task1state)
{
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1state = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
        if (Serial.available()>0)
        {
            rxData[dataCounter] = Serial.read();
            dataCounter++;
            Serial.print("Número de datos: \n");
            Serial.println(dataCounter);
            
            //if(dataCounter >= 32)
            //{
              //  dataCounter = 0;
            //}
        
        }
    }
}

}

void setup()
{
    task1();
}

void loop()
{
    task1();
}