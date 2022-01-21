//https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce

#include <WiFi.h>   // Utilisation de la librairie WiFi.h
#include <WiFiManager.h>         // https://github.com/tzapu/WiFiManager//https://www.arduino.cc/en/Tutorial/BuiltInExamples/Debounce

bool isButtonPressed = false;
const byte BUTTON_PIN = 13;
const byte LED_PIN = 12;
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(BUTTON_PIN, INPUT);

  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);

  // WiFiManager
  //wifiManager.autoConnect("Buzzer");
  //Serial.println("Connected.");
  digitalWrite(LED_PIN, ledState);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;

     ledState = !ledState;
        if (ledState == LOW) {
          sendHTTPCall();
        }
    }
  }

  digitalWrite(LED_PIN, ledState);

  lastButtonState = reading;
}

void sendHTTPCall() {
  Serial.println("I'm not a HTTP call");
}
