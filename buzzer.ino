#include <WiFi.h>   // Utilisation de la librairie WiFi.h
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
//Variables
WiFiManager wifiManager;
bool isButtonPressed = false;
int BUTTON_PIN = X;
int LED_PIN = X;

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(115200);

  // WiFiManager
  wifiManager.autoConnect("Buzzer");
  Serial.println("Connected.");
}

void loop() {
  if (HIGH == digitalRead(BUTTON_PIN)) {
    // On garde la LED allumée
    digitalWrite(LED_PIN, HIGH);

    // Si le bouton était déja pressé on ne va pas plus loin
    if (isButtonPressed) {
      return;
    }

    //Si on arrive là, c'est la première fois qu'on détecte l'appui
    sendHTTPCall();
    isButtonPressed = true;
  } else {
    // Si le bouton était déja remonté, on ne fait rien
    if (!isButtonPressed) {
      return;
    }

    //Sinon, on éteint la LED
    digitalWrite(LED_PIN, LOW);
    isButtonPressed = false;
  }
}

void sendHTTPCall() {
  Serial.println("I'm not a HTTP call");
}
