#include <WiFi.h>   // Utilisation de la librairie WiFi.h
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager
//Variables
WiFiManager wifiManager;
bool isButtonPressed = false;
const byte BUTTON_PIN = 14;
const byte LED_PIN = 12;
volatile byte state = LOW;
unsigned long lastButtonChange;


void setup() {
  pinMode(BUTTON_PIN, INPUT);
  //attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), checkButtonState, CHANGE);

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  // WiFiManager
  //wifiManager.autoConnect("Buzzer");
  //Serial.println("Connected.");
}

void loop() {
  Serial.println(digitalRead(BUTTON_PIN));
  //digitalWrite(LED_PIN, state);
  return;
  if (isButtonPressed & (millis() - lastButtonChange) > 300) {
    isButtonPressed = false;
    lastButtonChange = millis();
    sendHTTPCall();
  }
}

void checkButtonState() {
  Serial.println("changement");
  Serial.println(state);

  state = !state;
  isButtonPressed = state;
}

void sendHTTPCall() {
  Serial.println(isButtonPressed);
  Serial.println(digitalRead(BUTTON_PIN));
  Serial.println("I'm not a HTTP call");
}
