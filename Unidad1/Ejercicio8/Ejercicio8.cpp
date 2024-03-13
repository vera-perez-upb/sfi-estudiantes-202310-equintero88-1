void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States {
        INIT,
        SEC1,
        SEC2,
        SEC3
         };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan su valor entre llamadas a task1)
    static uint32_t lastTime = 0;
    // Constantes
    constexpr uint32_t INTERVAL = 1000;
    // MÁQUINA de ESTADOS
    switch (task1State)
    {
    case Task1States::INIT:
    
    {
        // Acciones:
        Serial.begin(115200);
        lastTime = millis();
        //Serial.print("/////\n");
        task1State = Task1States::SEC1;
        break;
    }
    case Task1States::SEC1:
    {
        
        uint32_t currentTime = millis();
        if ((currentTime - lastTime) >= INTERVAL) //Un segundo
        {
            
            Serial.print("--------\n");
            Serial.print("1");
            Serial.print('\n');
            lastTime = currentTime;
            task1State = Task1States::SEC2;
        }
        break;
    }

    case Task1States::SEC2:
    {
        uint32_t currentTime = millis();
        if ((currentTime - lastTime) >= INTERVAL) //Dos segundos
        {
            Serial.print("2");
            Serial.print('\n');
            lastTime = currentTime;
            task1State = Task1States::SEC3;
            
        }  
        break;  
    }

    case Task1States::SEC3:
    {
        uint32_t currentTime = millis();
        if ((currentTime - lastTime) >= INTERVAL) //Tres segundos
        {
            Serial.print("3");
            Serial.print('\n');
            lastTime = currentTime;
            task1State = Task1States::SEC1; 
        } 
        break;    
    }
   
   default:
    {
        Serial.println("Error");
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


