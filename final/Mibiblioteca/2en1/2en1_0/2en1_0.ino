
// Sketch.ino

#include "MiBiblioteca.h"

// Define los pines que estás utilizando para el control del motor y los sensores de línea
const int PinIN1 = 10;
const int PinIN2 = 9;
const int PinIN3 = 12;
const int PinIN4 = 13;
const int Pin_sensor1 = 7;
const int Pin_sensor2 = 8;

// Crea una instancia de la biblioteca con los pines especificados
MiBiblioteca miCarrito(PinIN1, PinIN2, PinIN3, PinIN4, Pin_sensor1, Pin_sensor2);

void setup() {
  // Inicializa la biblioteca en el setup
  miCarrito.setup();
  // Inicializa la comunicación serial para Bluetooth
  Serial.begin(9600);
}

void loop() {
  // Llama al loop de la biblioteca en el loop principal
  miCarrito.loop();

  // Verifica si hay datos disponibles en el puerto serie (Bluetooth)
  while (Serial.available() > 0) {
    char val = Serial.read();
    Serial.println(val);

    // Maneja los datos de Bluetooth y llama a la función correspondiente de la biblioteca
    if (val == 'F') {
      miCarrito.MotorAdelante();
    } else if (val == 'B') {
      miCarrito.MotorAtras();
    } else if (val == 'L') {
      miCarrito.MotorIzquierda();
    } else if (val == 'R') {
      miCarrito.MotorDerecha();
    } else if (val == 'S') {
      miCarrito.MotorStop();
    }

    // Actualiza el tiempo de la última recepción Bluetooth en la biblioteca
    miCarrito.tiempoUltimaRecepcionBluetooth = millis();
    // Cambia al modo Bluetooth en la biblioteca
    miCarrito.cambiarModo("bluetooth");
  }
}
