/**
 * Exemple de code pour un servomoteur, il fait faire des va-et-vient à la tête du servomoteur.
 */

 /* Inclut la lib Servo pour manipuler le servomoteur */
#include <Servo.h>

/* Créer un objet Servo pour contrôler le servomoteur */
Servo monServomoteur;
int val_servo = 0;

void setup() {
  
  // Attache le servomoteur à la broche D9
  monServomoteur.attach(9);
  Serial.begin(9600);
}

void loop() {


  monServomoteur.write(0);
  delay(3000);
  monServomoteur.write(180);
  delay(3000);
  
  //val_servo = monServomoteur.read();
 // Serial.println(val_servo);
  }
