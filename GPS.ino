#include <Arduino.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

const int RXPin = 16; // GPIO16 (pin D2) on ESP32
const int TXPin = 17; // GPIO17 (pin D3) on ESP32

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a serial object for GPS communication
HardwareSerial GPSSerial(2); // Using UART 1 (pins RXPin and TXPin)

void setup() {
  Serial.begin(9600); // Initialize serial monitor
  GPSSerial.begin(9600, SERIAL_8N1, RXPin, TXPin); // Initialize GPS serial communication
}

void loop() {
  while (GPSSerial.available() > 0) {
    // Read data from GPS serial buffer
    if (gps.encode(GPSSerial.read())) {
      // If new data is available from GPS
      if (gps.location.isValid()) {
        // If GPS location data is valid
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
      } else {
        Serial.println("GPS data not valid");
      }
    }
  }
}
