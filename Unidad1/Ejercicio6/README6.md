1) ¿Cómo se ejecuta este programa?
Este programa crea un método task1() que es llamado a ejecutarse en el setup() para definir los estados iniciales y en el loop() para que itere infinitamente. Task1() tiene dos estados: INIT y WAIT_TIMEOUT, y en un switch se "recorre" cada uno de estos. Inicia en INIT por defecto, porque es el valor que se le otorga al inicializarse y luego pasa a WAIT_TIEMOUT infinitamente.

2) El mensaje no puede verse y esto sucede debido a que no llega a ejecutarse por el flujo del código. La indicación para que el mensaje se imprima está justo debajo de la que le dice al programa que cambie su estado a WAIT_TIMEOUT, caso del cual no saldrá por no tener alguna instrucción para esto.

3) Solo una vez, al iniciar el programa.