unsigned long lastInputTime = 0; // Variable para almacenar el tiempo del último ingreso de caracteres

bool typedCode() {
    const unsigned long inputTimeout = 40000; 
    const int codeLength = 4; 
    char inputCode[codeLength + 1];
    int index = 0;
    
 while (Serial.available() > 0 && index < codeLength) {
        char inputChar = Serial.read();

        // Verificar si el caracter ingresado es un dígito
        if (isdigit(inputChar)) {
            inputCode[index++] = inputChar; // Almacenar el dígito en el array
        }
        lastInputTime = millis();
    }
    //Caracter nulo al final del array para convertirlo en una cadena de caracteres válida
    inputCode[index] = '\0';

 if (index == codeLength) {
        int enteredCode = atoi(inputCode);
        if (enteredCode == 1234) {
            return true;
        } else {
            Serial.println("Contraseña incorrecta");
        }
    }

    return false; 
}

void task1() {
    enum class Task1States {
        INIT,
        CONFIG,
        WAIT_DATA
    };

    static Task1States task1state = Task1States::INIT;
    static uint32_t timeCounter = 5;

    switch (task1state) {
        case Task1States::INIT: {
            delay(3000); //Tiempo para que salgan los mensajes en consola
            Serial.println("Ingresa S para aumentar el tiempo");
            Serial.println("Ingresa B para reducir el tiempo");
            Serial.println("Ingresa L cuando estés listo");
            timeCounter = 5; // Reiniciar el contador de tiempo
            task1state = Task1States::CONFIG;
            break;
        }

        case Task1States::CONFIG: {
            if (Serial.available() > 0) {
                char key = Serial.read();
                if (key == 'S' && timeCounter < 40) {
                    timeCounter++;
                    Serial.print("Tiempo establecido: ");
                    Serial.println(timeCounter);
                }
                if (key == 'B' && timeCounter > 0) {
                    timeCounter--;
                    Serial.print("Tiempo establecido: ");
                    Serial.println(timeCounter);
                }
                if (key == 'L') {
                    task1state = Task1States::WAIT_DATA;
                }
            }
            break;
        }

        case Task1States::WAIT_DATA: {
            Serial.print("Tiempo restante: ");
            Serial.println(timeCounter);
            
                if (typedCode()) 
                {
                Serial.println("¡SALVASTE EL MUNDO!");
                task1state = Task1States::INIT;
                }


           
            if (timeCounter == 0) {
                Serial.println("RADIACIÓN NUCLEAR ACTIVA");
                task1state = Task1States::INIT;
            }

            delay(1000); 
            timeCounter--; 

            break;
        }
    }
}

void setup() {
    Serial.begin(9600);
}

void loop() {
    task1();
}


