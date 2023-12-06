// MiBiblioteca.h
#ifndef MiBiblioteca_h
#define MiBiblioteca_h

#include "Arduino.h"

class MiBiblioteca {
private:
  int PinIN1, PinIN2, PinIN3, PinIN4, Pin_sensor1, Pin_sensor2;
  unsigned long tiempoUltimaRecepcionBluetooth;
  const unsigned long tiempoEsperaCambioModo = 20000;  // Tiempo en milisegundos (5 segundos)
  bool modoBluetooth;

public:
  MiBiblioteca(int pinIN1, int pinIN2, int pinIN3, int pinIN4, int pinSensor1, int pinSensor2);
  void setup();
  void loop();
  void cambiarModo(String modo);
  void MotorAdelante();
  void MotorIzquierda();
  void MotorDerecha();
  void MotorStop();
  void MotorAtras();
};

#endif

