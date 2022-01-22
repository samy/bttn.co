//Définition URL à appeler
#include "Settings.h"

//Bibliothèque AsyncHTTPSRequest_Generic pour gérer la requête HTTP, à installer via l'IDE Arduino ou depuis https://github.com/khoih-prog/AsyncHTTPSRequest_Generic
#include <AsyncHTTPSRequest_Generic.h>
#include <AsyncHTTPSRequest_Impl_Generic.h>

//Bibliothèque Ticker pour gérer la répétition de la vérification du bouton enfoncé, à installer via l'IDE Arduino ou depuis https://github.com/sstaub/Ticker
#include <Ticker.h>

//Bibliothèque native Wifi
#include <WiFi.h>

//Bibliothèque WifiManager pour gérer le portail de connexion au WiFi et la connexion automatique, à installer via l'IDE Arduino ou depuis https://github.com/tzapu/WiFiManager
#include <WiFiManager.h>

//Variables techniques
bool sendHTTPRequest = false; // Devons-nous faire la requête HTTP ?
const byte BUTTON_PIN = 14; // Numéro du PIN auquel est relié le bouton
const byte LED_PIN = 12; // Numéro du PIN auquel est relié la LED
int ledState = HIGH;         // Etat de la LED (on utilise une résistance de pullup donc l'état est inversé)
int buttonState       ;       // Etat du bouton
int lastButtonState = LOW;   // Stockage du précédent état du bouton
unsigned long lastDebounceTime = 0;  // Variable utilisée pour le filtrage du bouncing du bouton
unsigned long debounceDelay = 50;    // Temps d'ajustement du debounce, à augmenter si la LED clignote trop
AsyncHTTPSRequest request; // Objet qui va effectuée la requête HTTP
Ticker ticker; // Objet qui va gérer la répétition

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  // WiFiManager

  WiFiManager wifiManager;
  wifiManager.autoConnect("Buzzer"); // Démarre un réseau WiFi nommé "Buzzer" si aucun identifiant n'a précédemment été stocké

  //Le déroulement est bloqué à la fonction d'avant si la carte n'a pas accès à un réseau WiFi

  // On initialise la lED
  digitalWrite(LED_PIN, ledState);

  // On indique de répéter toutes les secondes la vérification de l'état du bouton, pour lancer la requête HTTP
  ticker.attach(1, sendRequest);
}

void loop() {
  // Vérification de l'état du bouton
  int reading = digitalRead(BUTTON_PIN);

  // Si le bouton a changé d'état on stocke à quelle microseconde cela s'est produit
  // Pour tester plus tard si cela fait suffisamment longtemps que le bouton a changé d'état
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  // Si le délai est suffisant depuis le dernier changement d'état, on considère que c'est un vrai changement d'état
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

      // On inverse l'état de la LED
      ledState = !ledState;
      if (ledState == LOW) {

        // Si la LED a changé d'état vers LOW (ici le fait qu'elle soit allumée, on va déclencher la requête HTTP
        sendHTTPRequest = true;
      }
    }
  }

  // On met à jour l'éclairage de la LED
  digitalWrite(LED_PIN, ledState);

  // Et on stocke enfin l'état du bouton pour le réutiliser
  lastButtonState = reading;
}

void sendRequest()
{
  // S'il n'est pas temps de lancer la requête HTTP, autant s'arrêter ici
  if (!sendHTTPRequest) {
    return;
  }
  sendHTTPRequest = false;
  static bool requestOpenResult;

  // Envoi de la requête et messages d'erreur si un problème survient
  if (request.readyState() == readyStateUnsent || request.readyState() == readyStateDone)
  {
    requestOpenResult = request.open("GET", URL.c_str());
    if (requestOpenResult)
    {
      Serial.println("Request is OK");
      request.send();
    }
    else
    {
      Serial.println("Can't send bad request");
    }
  }
  else
  {
    Serial.println("Can't send request");
  }
}
