#include <WiFi.h>   // Utilisation de la librairie WiFi.h
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager

void setup() {
    Serial.begin(115200);

  // WiFiManager
  WiFiManager wifiManager;
  wifiManager.autoConnect("Buzzer");
  Serial.println("Connected.");
}

void loop() { 

}
