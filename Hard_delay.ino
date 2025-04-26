#include <Arduino.h>

#define LED 2

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH); 
  
  for(int i = 0; i < 1000; i++) {
    
  }
  
  digitalWrite(LED, LOW); 
  
  for(int i = 0; i < 1000; i++) {
    
  }
}
#include <Arduino.h>

const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH); 
  
  for(int i = 0; i < 1000000; i++) {
   
  }
  
  digitalWrite(ledPin, LOW); 
  
 
  for(int i = 0; i < 1000000; i++) {
   
  }
}

