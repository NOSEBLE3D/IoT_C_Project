#include <Arduino.h>

const int switchPin = 15; // Example: Change to the desired interrupt pin number
const int ledPin = 2;     // Built-in LED pin

volatile bool switchPressed = false;
volatile int pressCount = 0;
unsigned long lastPressTime = 0;

void switchInterrupt() {
  switchPressed = true;
}

void delayWithVariable(int milliseconds) {
  for (int i = 0; i < milliseconds; i++) {
    delay(1); // Delay for 1 millisecond
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP); // Set the switch pin as input with pull-up resistor
  attachInterrupt(digitalPinToInterrupt(switchPin), switchInterrupt, FALLING); // Attach interrupt to the switch pin
}

void loop() {
  if (switchPressed) {
    unsigned long currentMillis = millis();
    unsigned long pressDuration = currentMillis - lastPressTime;
    
    if (pressDuration > 50) { // Filter out switch bounces
      switchPressed = false; // Reset the flag
      lastPressTime = currentMillis;
      pressCount++;
      
      if (pressCount == 1) {
        digitalWrite(ledPin, HIGH); // Solid blink
      } else if (pressCount == 2) {
        // Blink continuously until the next press
        for (int i = 0; i < 10; i++) { // Blink 10 times
          digitalWrite(ledPin, HIGH);
          delayWithVariable(500); // Delay for 500 milliseconds (0.5 second)
          digitalWrite(ledPin, LOW);
          delayWithVariable(500); // Delay for 500 milliseconds (0.5 second)

          if (switchPressed) {
            switchPressed = false; // Reset the flag
            pressCount = 0; // Reset press count
            break; // Exit the loop early if a new press is detected
          }
        }
      } else if (pressCount == 3) {
        digitalWrite(ledPin, LOW); // Turn off LED
        pressCount = 0; // Reset press count
      }
    }
  }
}