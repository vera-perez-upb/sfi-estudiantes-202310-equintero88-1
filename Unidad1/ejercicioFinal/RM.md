FLUJO DE TRABAJO PARA EL EJERCICIO FINAL DE LA UNIDAD 1

En primer lugar, diagramé lo que había entendido del enunciado, las principales acciones que debían ejecutarse. A partir de allí pensé en qué variables podía necesitar, por ejemplo las dos que usé para controlar el tiempo (timeCounter y countdownTimer). En el diagrama realicé también los estados que tendría el programa y opté por dos en primer lugar CONFIG (para realizar las configuraiones de tiempo) y WAIT_DATA(donde se ingresa o no el código de acceso), finalmente añadí también INIT (en la cual se imprimían en consola los mensajes guía y se reiniciaba la variable de tiempo).

Ya a la hora de programar, realicé primero el control de tiempo, su aumento y decremento según las teclas ingresadas por el monitor serial.
Luego, seguí con la parte de la clave de "parar la bomba". Para esto creé un método de tipo booleano "typedCode()" en el que está implementada toda la lógica del acceso del código por el monitor serial, y que finalmente devuelve un valor falso o verdadero según lo que se haya ingresado

¿QUÉ INCONVENIENTES TUVE?

Con el contador de tiempo tuve un problema principalmente. Este lo había implementado con un ciclo do-while y funcionana bien hasta que el valor que contaba el tiempo llegaba a cero. En este momento su valor se desbordaba hasta 4294967295, máximo valor de uint_32. No pude averigüar por qué sucedía esto, pero terminé solucionándolo al prescindir del ciclo y agregar unos condicionales, que además hacían el código más sencillo y legible.
Cuando quité el do-while solucioné otro problema en el cual al ingresar el código correcto salía el mensaje "SALVASTE EL MUNDO" pero el tiempo seguía corriendo; con los ifs podía tener un mayor control del tiempo y los problemas que surgían en el código.