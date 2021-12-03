#include <Servo.h>

const int bouton_+=;
const int bouton_-=;
int vitesse=0;

void setup() {
  pinMode(bouton_+, INPUT);
  pinMode(bouton_-, INPUT);

}

void loop() {
  //determiner la vitesse en fonction de la position du Servomoteur...

  val_+=digitalRead(bouton_+);
  val_-=digitalRead(bouton_-);

  if(val_+==LOW){
    if(vitesse==-1){
    //passer le point mort
    vitesse ++
    }
    else{
      if(vitesse==0){
      //passer la 1ère
      vitesse ++
      }
      else{
        if(vitesse==1){
        //passer la 2nde
        vitesse ++
        }
        else{
          if(vitesse==2){
          //passer la 3ème
          vitesse ++
          }
          else{
            if(vitesse==3){
            //passer la 4ème
            vitesse ++
            }
            else{
              if(vitesse==4){
              //passer la 5ème
              vitesse ++
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
    if(val_+==LOW){
      if(vitesse==5){
      //passer la 4ème
      vitesse --
      }
      else{
        if(vitesse==4){
        //passer la 3ème
        vitesse --
        }
        else{
          if(vitesse==3){
          //passer la 2nde
          vitesse --
          }
          else{
            if(vitesse==2){
            //passer la 1ère
            vitesse --
            }
            else{
              if(vitesse==1){
              //passer le point mort
              vitesse --
              }
              else{
                if(vitesse==0){
                //passer la marche arrière
                vitesse --
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
