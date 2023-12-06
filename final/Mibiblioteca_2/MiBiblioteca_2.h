// MiBibliotecaSimultanea.h

#ifndef MiBibliotecaSimultanea_h
#define MiBibliotecaSimultanea_h

#include "Arduino.h"

class MiBibliotecaSimultanea {
public:
  MiBibliotecaSimultanea(int pinIN1, int pinIN2, int pinIN3, int pinIN4, int pinSensor1, int pinSensor2);
  void setup();
  void loop();

private:
  int PinIN1, PinIN2, PinIN3, PinIN4, Pin_sensor1, Pin_sensor2;
  bool modoBluetooth;
  unsigned long tiempoUltimaRecepcionBluetooth;
  unsigned long tiempoEsperaCambioModo;

  void cambiarModo(String modo);
  void MotorAdelante();
  void MotorIzquierda();
  void MotorDerecha();
  void MotorStop();
  void MotorAtras();
};

#endif
