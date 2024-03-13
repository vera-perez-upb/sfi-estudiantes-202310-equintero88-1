1) Es necesario declarar rxData como static para que los valores se mantengan entre cada llamada a task1. En caso de que no se hiciera, estos datos se perderían y afectaría el funcionamiento del programa, por ejemplo, en la línea rxData[dataCounter] = Serial.read() se perderían los datos del array.

2) Es necesario declararlo porque, al ser la variable que cuenta el número de datos, si no se hiciese, se perdería este conte entre cada llamada de datos. No se inicializa en 0 cada vez que se ingresa a loop, esto es solo en la primera llamada. Al ser static, mantiene su valor.

3) Convierte los valores hexadecimales a decimales. 