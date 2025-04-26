#include <WiFi.h>
#include <time.h>

const char* ssid     = "Galaxy M21E0F2";
const char* password = "karthik@030";

void setup() {
  Serial.begin(9600);
  while (!Serial);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    configTime(5*3600, 0, "pool.ntp.org");
  
}

void loop() {
  delay(1000);
  printLocalTime();
  Serial.print("Connected to WiFi @ ");
  Serial.print(ssid); 
  Serial.print(" IP is ");
  Serial.print(WiFi.localIP()); 
  Serial.print(" & signal strength is ");
  Serial.println(WiFi.RSSI());
  delay(5000);
}

void printLocalTime()
{
struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
   Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
