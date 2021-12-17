/**
 * Exemple de code pour un servomoteur, il fait faire des va-et-vient à la tête du servomoteur.
 */

 /* Inclut la lib Servo pour manipuler le servomoteur */
#include <Servo.h>

/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur_1;
Servo monServomoteur_2;

void setup() {
  
  // Attache le servomoteur à la broche D9
  monServomoteur_1.attach(9);
  monServomoteur_2.attach(10);
}

void loop() {

  // Fait bouger le bras de 0° à 180°
  for (int position = 0; position <= 180; position++) {
    monServomoteur_1.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 180; position >= 0; position--) {
    monServomoteur_1.write(position);
    delay(15);
  }

  // Fait bouger le bras de 0° à 180°
  for (int position = 0; position <= 180; position++) {
    monServomoteur_2.write(position);
    delay(15);
  }
  
  // Fait bouger le bras de 180° à 10°
  for (int position = 180; position >= 0; position--) {
    monServomoteur_2.write(position);
    delay(15);
  }
}
