# bttn.co

## Résumé du projet

Ce projet, qui m'a été proposé à l'origine par [Patrice Cassard](https://twitter.com/patricecassard), consiste en un buzzer connecté à un service d'automatisation (Integromat dans le projet initial).

<p align="center">
  <img width="250" src="https://user-images.githubusercontent.com/1282106/150687162-1c86d744-36c9-4954-873b-d6a903c10d4a.png">
</p>

# Principe de base
Le fonctionnement est simple : une pression sur le buzzer doit pouvoir appeler une URL via HTTP.

# Base technique
La nécessité dans ce projet était de combiner la simplicité d'Arduino et l'accès au Wifi, le choix s'est donc tourné vers les cartes du type ESP32 qui pour un prix modique (autour de 10 euros) proposent une connectique WiFi/Bluetooth facilement accessible via le code C/C++ d'Arduino.
<p align="center">
  <img width="250" src="https://user-images.githubusercontent.com/1282106/150687652-98054109-703c-446a-b6bb-629b0d94848b.jpg">
</p>

Niveau buzzer justement, il s'agit d'un bête interrupteur à pression (équipé ici d'une LED centrale pour indiquer s'il est enfoncé.
<p align="center">
  <img width="250" src="https://user-images.githubusercontent.com/1282106/150687574-f4285a2e-aab3-4846-b5ea-991c0c15df6e.jpg">
</p>

# Matériel utilisé
- Une carte ESP32 (j'ai utilisé le [ESP32 Wroom DevKit de chez uPesy](https://upesy.com/products/upesy-esp32-wroom-devkit-board), ou toute autre carte compatible Arduino et WiFi
- Un bouton poussoir (n'importe quel modèle peut convenir mais c'est ici un [EG START](https://www.amazon.fr/gp/product/B01MSNXLN0/) qui a été retenu
- Une LED pour indiquer que le bouton a été enfoncé (ici on utilise celle du bouton)
- Un câble USB (pour alimenter et programmer le boitier). Il existe d'ailleurs des [câbles à angle droit](https://www.amazon.fr/gp/product/B071YMDNQN) qui sont très pratiques !
