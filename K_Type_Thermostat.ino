#include <SPI.h>

// Define the pins for MAX6675
#define MAX6675_CLK 18
#define MAX6675_CS  5
#define MAX6675_DO  19

void setup() {
  Serial.begin(9600);
  pinMode(MAX6675_CS, OUTPUT);
  pinMode(MAX6675_CLK, OUTPUT);
  pinMode(MAX6675_DO, INPUT);

  // Initialize SPI communication
  SPI.begin();
}

void loop() {
  double celsius = readTemperature();
  if (celsius >= 0 ) {
    Serial.print("Temperature: ");
    Serial.print(celsius);
    Serial.println(" °C");
  } else {
    Serial.println("Error reading temperature.");
  }
  
  delay(1000); // Delay for stability
}

double readTemperature() {
  digitalWrite(MAX6675_CS, LOW); // Select MAX6675
  delayMicroseconds(1); // Ensure stability

  // Read 16-bit data from MAX6675
  uint16_t v = SPI.transfer16(0x0000);

  digitalWrite(MAX6675_CS, HIGH); // Deselect MAX6675

  // Check if thermocouple is disconnected
  if (v & 0x4) {
    return -1;
  }

  // Convert data to temperature
  double celsius = (v >> 3) * 0.25;

  return celsius;
}