1) El Serial.available() verifica si hay datos disponibles para ser leídos, antes de intentar leerlos.

2) Serial.read() lee el dato que está en el búfer de entrada serial, y lo devuelve como un entero. 

3) Devuelve un valor -1.

4) Serial.read() solo puede leer un byte.

5) La función debe ser llamada múltiples veces.

6) Los datos estarán disponibles pero serán leídos y, por lo tanto, devueltos.