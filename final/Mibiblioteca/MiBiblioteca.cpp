// MiBiblioteca.cpp
#include "MiBiblioteca.h"

MiBiblioteca::MiBiblioteca(int pinIN1, int pinIN2, int pinIN3, int pinIN4, int pinSensor1, int pinSensor2) {
  PinIN1 = pinIN1;
  PinIN2 = pinIN2;
  PinIN3 = pinIN3;
  PinIN4 = pinIN4;
  Pin_sensor1 = pinSensor1;
  Pin_sensor2 = pinSensor2;
  tiempoUltimaRecepcionBluetooth = 0;
  modoBluetooth = true;  // Inicia en modo Bluetooth
}

void MiBiblioteca::setup() {
  Serial.begin(9600);
  pinMode(PinIN1, OUTPUT);
  pinMode(PinIN2, OUTPUT);
  pinMode(PinIN3, OUTPUT);
  pinMode(PinIN4, OUTPUT);
  pinMode(Pin_sensor1, INPUT);
  pinMode(Pin_sensor2, INPUT);
}

void MiBiblioteca::loop() {
  // Verificar si hay señal de Bluetooth
  if (Serial.available() > 0) {
    tiempoUltimaRecepcionBluetooth = millis();
    cambiarModo("bluetooth");
  }

  // Verificar si ha pasado suficiente tiempo sin recibir señal Bluetooth
  if (millis() - tiempoUltimaRecepcionBluetooth > tiempoEsperaCambioModo && modoBluetooth) {
    cambiarModo("linea");
  }

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

  delay(20);
}

void MiBiblioteca::cambiarModo(String modo) {
  if (modo == "bluetooth") {
    modoBluetooth = true;
    // Implementa la lógica de Bluetooth aquí

    while (Serial.available() > 0) {
      char val = Serial.read();
      Serial.println(val);

      if (val == 'F') {
        MotorAdelante();
      } else if (val == 'B') {
        MotorAtras();
      } else if (val == 'L') {
        MotorIzquierda();
      } else if (val == 'R') {
        MotorDerecha();
      } else if (val == 'S') {
        MotorStop();
      }
    }
  } else if (modo == "linea") {
    modoBluetooth = false;
    // Implementa la lógica de seguimiento de línea aquí
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
  }
}

void MiBiblioteca::MotorAdelante() {
  // Implementa la lógica para mover el carrito hacia adelante
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);
  digitalWrite(PinIN3, HIGH);
  digitalWrite(PinIN4, LOW);
}

void MiBiblioteca::MotorIzquierda() {
  // Implementa la lógica para mover el carrito a la izquierda
  digitalWrite(PinIN1, HIGH);
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, HIGH);
  digitalWrite(PinIN4, LOW);
}

void MiBiblioteca::MotorDerecha() {
  // Implementa la lógica para mover el carrito a la derecha
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, HIGH);
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}

void MiBiblioteca::MotorStop() {
  // Implementa la lógica para detener el carrito
  digitalWrite(PinIN1, LOW);
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, LOW);
}

void MiBiblioteca::MotorAtras() {
  // Implementa la lógica para mover el carrito hacia atrás
  digitalWrite(PinIN1, HIGH);
  digitalWrite(PinIN2, LOW);
  digitalWrite(PinIN3, LOW);
  digitalWrite(PinIN4, HIGH);
}