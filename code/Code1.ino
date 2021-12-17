#include <Servo.h>

const int bouton_plus=;
const int bouton_moins=;
int vitesse=0;

Servo monServomoteur_1;   //on affecte des valeurs aux servomoteurs.
Servo monServomoteur_2;
const int servo_1 = 9;
const int servo_2 = 10;

void setup() {
  pinMode(bouton_+, INPUT);
  pinMode(bouton_-, INPUT);

  monServomoteur_1.attach(servo_1);    //on attache le servomoteur 1 sur la broche D9
  monServomoteur_2.attach(servo_2);   //on attache le servomoteur 2 sur la broche D9
}

void loop() {
  //determiner la vitesse en fonction de la position du Servomoteur...
  val_servo_1 = int monServomoteur_1.read();
  val_servo_2 = int monServomoteur_2.read();
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la marche arrière est engagée
    vitesse = -1;
  }
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la boîte est au point mort.
    vitesse = 0;
  }
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la 1ère est engagée
    vitesse = 1;
  }
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la 2nde est engagée
    vitesse = 2;
  }
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la 3ème est engagée
    vitesse = 3;
  }
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la 4ème est engagée
    vitesse = 4;
  }
  if(val_servo_1 == . && val_servo_2 == .){   //On déduit de la postion des servomoteurs que la 5ème est engagée
    vitesse = 5;
  }
  

  val_plus=digitalRead(bouton_plus);
  val_moins=digitalRead(bouton_moins);

  if(val_plus==LOW){
    if(vitesse==-1){
    //passer le point mort
    monServomoteur_1.write();
    delay(15);
    monServomoteur_2.write();
    vitesse ++;
    }
    else{
      if(vitesse==0){
      //passer la 1ère
      monServomoteur_1.write();
      delay(15);
      monServomoteur_2.write();
      vitesse ++;
      }
      else{
        if(vitesse==1){
        //passer la 2nde
        monServomoteur_1.write();
        delay(15);
        monServomoteur_2.write();
        vitesse ++;
        }
        else{
          if(vitesse==2){
          //passer la 3ème
          monServomoteur_1.write();
          delay(15);
          monServomoteur_2.write();
          vitesse ++;
          }
          else{
            if(vitesse==3){
            //passer la 4ème
            monServomoteur_1.write();
            delay(15);
            monServomoteur_2.write();
            vitesse ++;
            }
            else{
              if(vitesse==4){
              //passer la 5ème
              monServomoteur_1.write();
              delay(15);
              monServomoteur_2.write();
              vitesse ++;
              }
              else{
                if(vitesse==5){
                //Ne rien faire
                }
                else{
                  //
                }
              }
            }
          }
        }
      }
    }
  }
  else{
    if(val_moins==LOW){
      if(vitesse==5){
      //passer la 4ème
      monServomoteur_1.write();
      delay(15);
      monServomoteur_2.write();
      vitesse --;
      }
      else{
        if(vitesse==4){
        //passer la 3ème
        monServomoteur_1.write();
        delay(15);
        monServomoteur_2.write();
        vitesse --;
        }
        else{
          if(vitesse==3){
          //passer la 2nde
          monServomoteur_1.write();
          delay(15);
          monServomoteur_2.write();
          vitesse --;
          }
          else{
            if(vitesse==2){
            //passer la 1ère
            monServomoteur_1.write();
            delay(15);
            monServomoteur_2.write();
            vitesse --;
            }
            else{
              if(vitesse==1){
              //passer le point mort
              monServomoteur_1.write();
              delay(15);
              monServomoteur_2.write();
              vitesse --;
              }
              else{
                if(vitesse==0){
                //passer la marche arrière
                monServomoteur_1.write();
                delay(15);
                monServomoteur_2.write();
                vitesse --;
                }
                else{
                  if(vitesse==-1){
                  //Ne rien faire
                  }
                  else{
                    //
                  }
                }
              }
            }
          }
        }
      }
    }
  }







}
