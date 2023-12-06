// MiBibliotecaSimultanea.cpp

#include "MiBibliotecaSimultanea.h"

MiBibliotecaSimultanea::MiBibliotecaSimultanea(int pinIN1, int pinIN2, int pinIN3, int pinIN4, int pinSensor1, int pinSensor2) {
  PinIN1 = pinIN1;
  PinIN2 = pinIN2;
  PinIN3 = pinIN3;
  PinIN4 = pinIN4;
  Pin_sensor1 = pinSensor1;
  Pin_sensor2 = pinSensor2;
  tiempoUltimaRecepcionBluetooth = 0;
  modoBluetooth = true;  // Inicia en modo Bluetooth
  tiempoEsperaCambioModo = 5000; // Establece el tiempo de espera para cambiar al modo línea (en milisegundos)
}

void MiBibliotecaSimultanea::setup() {
  Serial.begin(9600);
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode(Pin_sensor1, INPUT);
  pinMode(Pin_sensor2, INPUT);
}

void MiBibliotecaSimultanea::loop() {
  // Implementar la lógica de seguimiento de línea
  int value1 = digitalRead(Pin_sensor1);
  int value2 = digitalRead(Pin_sensor2);

  if (value1 == LOW && value2 == LOW) {
    Serial.println("adelante");
    MotorAdelante();
  } else if (value1 == HIGH && value2 == HIGH) {
    Serial.println("detenido");
    MotorStop();
  } else if (value1 == HIGH && value2 == LOW) {
    Serial.println("izquierda");
    MotorIzquierda();
  } else if (value2 == HIGH && value1 == LOW) {
    Serial.println("derecha");
    MotorDerecha();
  }

  // Verificar si hay señal de Bluetooth
  while (Serial.available() > 0) {
    char val = Serial.read();
    Serial.println(val);

    if (val == 'F') {
      MotorAdelante();
      cambiarModo("bluetooth");
    } else if (val == 'B') {
      MotorAtras();
      cambiarModo("bluetooth");
    } else if (val == 'L') {
      MotorIzquierda();
      cambiarModo("bluetooth");
    } else if (val == 'R') {
      MotorDerecha();
      cambiarModo("bluetooth");
    } else if (val == 'S') {
      MotorStop();
      cambiarModo("bluetooth");
    }

    // Actualizar el tiempo de la última recepción Bluetooth
    tiempoUltimaRecepcionBluetooth = millis();
  }

  // Verificar si ha pasado suficiente tiempo sin recibir señal Bluetooth
  if (!modoBluetooth && millis() - tiempoUltimaRecepcionBluetooth > tiempoEsperaCambioModo) {
    cambiarModo("linea");
  }

  delay(20);
}

void MiBibliotecaSimultanea::cambiarModo(String modo) {
  if (modo == "bluetooth") {
    modoBluetooth = true;
    // Implementa la lógica de Bluetooth aquí
  } else if (modo == "linea") {
    modoBluetooth = false;
    // Implementa la lógica de seguimiento de línea aquí
  }
}

void MiBibliotecaSimultanea::MotorAdelante() {
  // Implementa la lógica para mover el carrito hacia adelante
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);
  digitalWrite(PinIN3, HIGH);
  digitalWrite(PinIN4, LOW);
}

void MiBibliotecaSimultanea::MotorIzquierda() {
  // Implementa la lógica para mover el carrito a la izquierda
  digitalWrite(PinIN1, HIGH);
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, HIGH);
  digitalWrite(PinIN4, LOW);
}

void MiBibliotecaSimultanea::MotorDerecha() {
  // Implementa la lógica para mover el carrito a la derecha
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}

void MiBibliotecaSimultanea::MotorStop() {
  // Implementa la lógica para detener el carrito
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, LOW);
}

void MiBibliotecaSimultanea::MotorAtras() {
  // Implementa la lógica para mover el carrito hacia atrás
  digitalWrite(PinIN1, HIGH);
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}
