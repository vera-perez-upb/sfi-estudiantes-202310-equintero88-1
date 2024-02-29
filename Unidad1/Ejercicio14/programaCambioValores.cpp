static void changeVar(uint32_t *p1, uint32_t *p2) //Función con dos punteros como parámetros
{
    uint32_t temp = *p1; //Variable temporal para almacenar al primer valor 
    *p1 = *p2;  
    *p2 = temp; //Segundo valor al almacenado previamente

}

static void printVar(uint32_t value)
{
    Serial.print("var content: ");
    Serial.print(value);
    Serial.print('\n');
}

void task1()
{
    enum class Task1States    
    {

        INIT,
        WAIT_DATA
    };
    static Task1States task1State = Task1States::INIT;

    switch (task1State)
    {
    case Task1States::INIT:
    {
        Serial.begin(115200);
        task1State = Task1States::WAIT_DATA;
        break;
    }

    case Task1States::WAIT_DATA:
    {
    
            
            if (Serial.available() > 0)
            {
            
            Serial.read();
            uint32_t var1 = 0; //Primer valor
            uint32_t var2 = 2; //Segundo valor
            uint32_t *pvar1 = &var1; //Declaración e inicialización del 1er puntero para el 1er valor
            uint32_t *pvar2 = &var2; //Declaración e inicialización del 2do puntero para el 2do valor
            //Almacenan la dirección de las variables
            printVar(*pvar1); //Imprime los primeros valores
            printVar(*pvar2);
            changeVar(pvar1, pvar2); //Llamada a la función, los punteros como parámetros
            printVar(var1); //Imprime el cambio de valores
            printVar(var2);
    
            }
            
        break;
    }

    default:
    {
        break;
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