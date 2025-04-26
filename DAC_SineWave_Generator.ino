#include <Arduino.h>
#include <math.h>

int Sin_Array[256];                 // Define array to store sine wave values
float Period = (2 * PI) / 256;      // Define the sine wave conversion factor
float Rad_Angle;

void setup() {
  Serial.begin(115200); // Initialize serial communication
  delay(1000); // Wait for serial monitor to open
  while (!Serial);
  
  for (int Angle = 0; Angle < 256; Angle++) {
    Rad_Angle = Angle * Period;               // calculate the angle in radian
    Sin_Array[Angle] = (sin(Rad_Angle) * 127) + 128;  // calculate the angle and shift by 128
  }
}

void loop() {
  for (int i = 0; i < 256; i++) {
    Serial.println(Sin_Array[i]); // Print the sine wave values to the serial port
    dacWrite(25, Sin_Array[i]);   // Write the sine wave value to the DAC pin
    delay(10);                     // Adjust delay as needed (in milliseconds)
  }
}
