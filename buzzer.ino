#include <WiFi.h>   // Utilisation de la librairie WiFi.h

const char* ssid = "NOM_DU_RESEAU_WIFI";  // Mettre votre SSID Wifi
const char* password = "MOT_DE_PASSE_WIFI";  // Mettre votre mot de passe Wifi

void setup() {
  Serial.begin(115200);   // Initialisation du moniteur série à 115200
  delay(1000);

  Serial.println("\n");
  WiFi.begin(ssid,password);  // Initialisation avec WiFi.begin / ssid et password
  Serial.print("Attente de connexion ...");  // Message d'attente de connexion
  while(WiFi.status() != WL_CONNECTED)  // Test connexion

{

    Serial.print(".");  // Affiche des points .... tant que connexion n'est pas OK

    delay(100);
  }
  

  Serial.println("\n");
  Serial.println("Connexion etablie !");  // Affiche connexion établie
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());  // Affiche l'adresse IP de l'ESP32 avec WiFi.localIP
}

void loop() { 

 // Ne rien mettre dans le loop
}
