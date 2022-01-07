/**
 * Exemple de code pour un servomoteur, avec 1 bouton poussoir
 */

 /* Inclut la lib Servo pour manipuler le servomoteur */
#include <Servo.h>

/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur_1;

const int bouton=7;
int val=0;

void setup() {
  
  // Attache le servomoteur à la broche D9
  monServomoteur_1.attach(9);

  pinMode(bouton, INPUT);
}

void loop() {
  val=digitalRead(bouton);
  if(val==LOW){
    for (int position = 0; position <= 180; position++) {
      monServomoteur_1.write(position);
      delay(15);
    }
    for (int position = 180; position >= 0; position--) {
      monServomoteur_1.write(position);
      delay(15);
    }
  }
  
}
