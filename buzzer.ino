#include <WiFi.h>   // Utilisation de la librairie WiFi.h
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
//Variables
WiFiManager wifiManager;
bool isButtonPressed = false;
int BUTTON_PIN = 13;
int LED_PIN = 12;

void setup() {
  //pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  // WiFiManager
  wifiManager.autoConnect("Buzzer");
  Serial.println("Connected.");
}

void loop() {
  if (LOW == digitalRead(BUTTON_PIN)) {
    if (isButtonPressed) {
      return;
    }
    isButtonPressed = true;

    // On garde la LED allumée
    digitalWrite(LED_PIN, HIGH);

    // Si le bouton était déja pressé on ne va pas plus loin


    //Si on arrive là, c'est la première fois qu'on détecte l'appui

    sendHTTPCall();
  } else {
    // Si le bouton était déja remonté, on ne fait rien
    if (!isButtonPressed) {
      return;
    }
    isButtonPressed = false;

    //Sinon, on éteint la LED
    digitalWrite(LED_PIN, LOW);
  }
}

void sendHTTPCall() {
  Serial.println(isButtonPressed);
  Serial.println(digitalRead(BUTTON_PIN));
  Serial.println("I'm not a HTTP call");
}
