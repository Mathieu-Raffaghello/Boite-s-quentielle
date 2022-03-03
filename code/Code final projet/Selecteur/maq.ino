#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3); // HC-12 TX Pin, HC-12 RX Pin

const int bouton_plus=5;
const int bouton_moins=6;
int vitesse=0;

Servo monServomoteur_1;   //on affecte des valeurs aux servomoteurs.
Servo monServomoteur_2;
const int servo_1 = 10;
const int servo_2 = 9;

int val_servo_1 = 0;
int val_servo_2 = 0;

int val_plus = 0;
int val_moins = 0;


void setup() {
  pinMode(bouton_plus, INPUT);
  pinMode(bouton_moins, INPUT);

  monServomoteur_1.attach(servo_1);    //on attache le servomoteur 1 sur la broche D10
  monServomoteur_2.attach(servo_2);   //on attache le servomoteur 2 sur la broche D9

  monServomoteur_1.write(90);
  monServomoteur_2.write(90);

  Serial.begin(9600);            
  HC12.begin(9600); 
}

void loop() {
  //determiner la vitesse en fonction de la position du Servomoteur...
  val_servo_1 =  monServomoteur_1.read();
  val_servo_2 =  monServomoteur_2.read();
  if(val_servo_1 == 120 && val_servo_2 == 50){   //On déduit de la postion des servomoteurs que la marche arrière est engagée
    vitesse = -1;
  }
  if(val_servo_1 == 90 && val_servo_2 == 90){   //On déduit de la postion des servomoteurs que la boîte est au point mort.
    vitesse = 0;
  }
  if(val_servo_1 == 60 && val_servo_2 == 140){   //On déduit de la postion des servomoteurs que la 1ère est engagée
    vitesse = 1;
  }
  if(val_servo_1 == 60 && val_servo_2 == 50){   //On déduit de la postion des servomoteurs que la 2nde est engagée
    vitesse = 2;
  }
  if(val_servo_1 == 90 && val_servo_2 == 140){   //On déduit de la postion des servomoteurs que la 3ème est engagée
    vitesse = 3;
  }
  if(val_servo_1 == 90 && val_servo_2 == 50){   //On déduit de la postion des servomoteurs que la 4ème est engagée
    vitesse = 4;
  }
  if(val_servo_1 == 120 && val_servo_2 == 140){   //On déduit de la postion des servomoteurs que la 5ème est engagée
    vitesse = 5;
  }
  

  val_plus=digitalRead(bouton_plus);
  val_moins=digitalRead(bouton_moins);

  if(val_plus==LOW){
    if(vitesse==-1){
    //passer le point mort
    monServomoteur_2.write(90);
    delay(500);
    monServomoteur_1.write(90);
    vitesse ++;


     HC12.write(vitesse);
                
    }
    else{
      if(vitesse==0){
      //passer la 1ère
      monServomoteur_1.write(60);
      delay(500);
      monServomoteur_2.write(140);
      vitesse ++;

     HC12.write(vitesse);
      }
      else{
        if(vitesse==1){
        //passer la 2nde
        monServomoteur_1.write(60);
        delay(500);
        monServomoteur_2.write(50);
        vitesse ++;

     HC12.write(vitesse);
        }
        else{
          if(vitesse==2){
          //passer la 3ème
          monServomoteur_2.write(90);
          delay(500);
          monServomoteur_1.write(90);
          delay(500);
          monServomoteur_2.write(140);
          vitesse ++;

     HC12.write(vitesse);
          }
          else{
            if(vitesse==3){
            //passer la 4ème
            monServomoteur_1.write(90);
            delay(500);
            monServomoteur_2.write(50);
            vitesse ++;

     HC12.write(vitesse);
            }
            else{
              if(vitesse==4){
              //passer la 5ème
              monServomoteur_2.write(90);
              delay(500);
              monServomoteur_1.write(120);
              delay(500);
              monServomoteur_2.write(140);
              vitesse ++;

     HC12.write(vitesse);
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
      monServomoteur_2.write(90);
      delay(500);
      monServomoteur_1.write(90);
      delay(500);
      monServomoteur_2.write(50);
      vitesse --;

     HC12.write(vitesse);
      }
      else{
        if(vitesse==4){
        //passer la 3ème
        monServomoteur_1.write(90);
        delay(500);
        monServomoteur_2.write(140);
        vitesse --;

     HC12.write(vitesse);
        }
        else{
          if(vitesse==3){
          //passer la 2nde
          monServomoteur_2.write(90);
          delay(500);
          monServomoteur_1.write(60);
          delay(500);
          monServomoteur_2.write(50);
          vitesse --;

     HC12.write(vitesse);
          }
          else{
            if(vitesse==2){
            //passer la 1ère
            monServomoteur_1.write(60);
            delay(500);
            monServomoteur_2.write(140);
            vitesse --;

     HC12.write(vitesse);
            }
            else{
              if(vitesse==1){
              //passer le point mort
              monServomoteur_2.write(90);
              delay(500);
              monServomoteur_1.write(90);
              vitesse --;

     HC12.write(vitesse);
              }
              else{
                if(vitesse==0){
                //passer la marche arrière
                monServomoteur_1.write(120);
                delay(500);
                monServomoteur_2.write(50);
                vitesse --;

     HC12.write(6);
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
