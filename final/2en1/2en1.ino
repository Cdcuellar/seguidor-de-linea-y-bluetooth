
#include "MiBiblioteca.h"

// Definición de pines para el motor y sensores
const int PinIN1 = 10;
const int PinIN2 = 9;
const int PinIN3 = 12;
const int PinIN4 = 13;
const int Pin_sensor1 = 7;
const int Pin_sensor2 = 8;

// Instancia de la biblioteca
MiBiblioteca miCarrito(PinIN1, PinIN2, PinIN3, PinIN4, Pin_sensor1, Pin_sensor2);

void setup() {
  miCarrito.setup();
}

void loop() {
  miCarrito.loop();
}
