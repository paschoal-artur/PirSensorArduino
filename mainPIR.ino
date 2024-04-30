
#include <Arduino.h>
/*Código de sensor PIR, detector de movimento*/

int sensor = 13; //Pino que o sensor está conectado
int state = LOW; //Estado inicial do sensor, nenhum movimento detectado
int val = 0; //Variável para guardar o status do sensor

void setup() {
  
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  
  val = digitalRead(sensor);

  if (val == HIGH) {
    
    delay(100);
    if (state == LOW) {
      
      Serial.println("Motion Detected at ");
      Serial.print(millis());
      Serial.println(" ms");
      state = HIGH;
      
    }
  }
  
  else {
    
    delay(200);
    if (state == HIGH) {
      
      Serial.println("Motion Stopped at ");
      Serial.print(millis());
      Serial.println(" ms\n");
      state = LOW;
      
    }
  }

}
