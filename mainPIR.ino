#include <Arduino.h>
/* Código de sensor PIR, detector de movimento com LED interno */

int sensor = 13; // Pino que o sensor está conectado
int state = LOW; // Estado inicial do sensor, nenhum movimento detectado
int val = 0; // Variável para guardar o status do sensor
int ledPin = 2; // LED interno no GPIO 2 (verifique se este é o pino correto para seu ESP32)
int i = 0; // Contador de detecções de movimento

void setup()
{
  pinMode(sensor, INPUT);
  pinMode(ledPin, OUTPUT); // Configura o pino do LED como saída
  Serial.begin(9600);
}

void loop()
{
  val = digitalRead(sensor);

  if (val == HIGH) {
    delay(100); // Debounce delay
    if (state == LOW) {
      Serial.print("Motion Detected at ");
      Serial.print(millis());
      Serial.print(" ms - Count: ");
      Serial.println(i);
      digitalWrite(ledPin, HIGH); // Acende o LED
      state = HIGH;
      i++; // Incrementa o contador de detecções
    }
  } 
  else {
    delay(200); // Debounce delay
    if (state == HIGH) {
      Serial.print("Motion Stopped at ");
      Serial.print(millis());
      Serial.println(" ms");
      digitalWrite(ledPin, LOW); // Apaga o LED
      state = LOW;
    }
  }
}
