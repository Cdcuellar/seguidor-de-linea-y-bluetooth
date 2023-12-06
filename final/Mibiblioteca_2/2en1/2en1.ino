
// TuSketchPrincipal.ino

#include "MiBibliotecaSimultanea.h"

// Define los pines para el motor y los sensores
int pinIN1 = 10;
int pinIN2 = 9;
int pinIN3 = 12;
int pinIN4 = 13;
int pinSensor1 = 7;
int pinSensor2 = 8;

// Crea una instancia de la nueva librería
MiBibliotecaSimultanea miCarrito(pinIN1, pinIN2, pinIN3, pinIN4, pinSensor1, pinSensor2);

void setup() {
  // Inicia la comunicación serial
  Serial.begin(9600);

  // Inicia la configuración de la librería
  miCarrito.setup();
}

void loop() {
  // Ejecuta el bucle principal de la librería
  miCarrito.loop();
}
