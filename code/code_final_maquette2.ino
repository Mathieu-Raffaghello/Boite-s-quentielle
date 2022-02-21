#include <Servo.h>

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

///////////////////////////
//////// AFFICHEUR ////////
///////////////////////////

int DIN_pin = 11;
int CS_pin = 10;
int CLK_pin = 12;
int UN[8] = {0x18, 0x38, 0x78, 0x18, 0x18, 0x18, 0x3C, 0x7E}; //afficher le chiffre 1
int DEUX[8] = {0x7E, 0x7E, 0x06, 0x7E, 0x7E, 0x60, 0x7E, 0x7E}; //afficher le chiffre 2
int TROIS[8] = {0x7E, 0x7E, 0x06, 0x3E, 0x3E, 0x06, 0x7E, 0x7E}; //afficher le chiffre 3
int QUATRE[8] = {0x0E, 0x1E, 0x36, 0x66, 0xFF, 0xFF, 0x06, 0x06}; //afficher le chiffre 4
int CINQ[8] = {0x7E, 0x7E, 0x60, 0x7E, 0x7E, 0x06, 0x7E, 0x7E}; //afficher le chiffre 5
int N[8] = {0xC3, 0xE3, 0xF3, 0xFB, 0xDF, 0xCF, 0xC7, 0xC3}; //afficher la lettre N
int R[8] = {0x7C, 0x7E, 0x66, 0x66, 0x7E, 0x7C, 0x6E, 0x67}; //afficher la lettre R
void write_pix(int data)
{
 digitalWrite(CS_pin, LOW);
 for (int i = 0; i < 8; i++)
 {
   digitalWrite(CLK_pin, LOW);
   digitalWrite(DIN_pin, data & 0x80); // masquage de donnée
   data = data << 1; // on décale les bits vers la gauche
   digitalWrite(CLK_pin, HIGH);
 }
}
void write_line(int adress, int data)
{
 digitalWrite(CS_pin, LOW);
 write_pix(adress);
 write_pix(data);
 digitalWrite(CS_pin, HIGH);
}
void write_matrix(int *tab)
{
 for (int i = 0; i < 8; i++) write_line(i + 1, tab[i]);
}
void init_MAX7219(void)
{
 write_line(0x09, 0x00); //decoding BCD
 write_line(0X0A, 0x01); //brightness
 write_line(0X0B, 0x07); //scanlimit 8leds
 write_line(0X0C, 0x01); //power-down mode 0, normalmode1;
 write_line(0X0F, 0x00);
}
void clear_matrix(void)
{
 const int clean[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
 write_matrix(clean);
}
int intToHex(int x)
{
 switch (x)
 {
   case 0: return 0x01; break; //LED sur la première case
   case 1: return 0x02; break; //LED sur 2 case
   case 2: return 0x04; break; //LED sur 3 case
   case 3: return 0x08; break; //LED sur 4 case
   case 4: return 0x10; break; //LED sur 5 case
   case 5: return 0x20; break; //LED sur 6 case
   case 6: return 0x40; break; //LED sur 7 case
   case 7: return 0x80; break; //LED sur 8 case
 }
}
///////////////// fin aff

void setup() {
  pinMode(bouton_plus, INPUT);
  pinMode(bouton_moins, INPUT);

  monServomoteur_1.attach(servo_1);    //on attache le servomoteur 1 sur la broche D10
  monServomoteur_2.attach(servo_2);   //on attache le servomoteur 2 sur la broche D9

  monServomoteur_1.write(90);
  monServomoteur_2.write(90);

///////////////////////////
//////// AFFICHEUR ////////
///////////////////////////

  pinMode(CS_pin, OUTPUT);
  pinMode(DIN_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  delay(50);
  init_MAX7219();
  clear_matrix();
 ////////////////////////// fin aff
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
    write_matrix(N);
    }
    else{
      if(vitesse==0){
      //passer la 1ère
      monServomoteur_1.write(60);
      delay(500);
      monServomoteur_2.write(140);
      vitesse ++;
      write_matrix(UN);
      }
      else{
        if(vitesse==1){
        //passer la 2nde
        monServomoteur_1.write(60);
        delay(500);
        monServomoteur_2.write(50);
        vitesse ++;
        write_matrix(DEUX);
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
          write_matrix(TROIS);
          }
          else{
            if(vitesse==3){
            //passer la 4ème
            monServomoteur_1.write(90);
            delay(500);
            monServomoteur_2.write(50);
            vitesse ++;
            write_matrix(QUATRE);
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
              write_matrix(CINQ);
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
      write_matrix(QUATRE);
      }
      else{
        if(vitesse==4){
        //passer la 3ème
        monServomoteur_1.write(90);
        delay(500);
        monServomoteur_2.write(140);
        vitesse --;
        write_matrix(TROIS);
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
          write_matrix(DEUX);
          }
          else{
            if(vitesse==2){
            //passer la 1ère
            monServomoteur_1.write(60);
            delay(500);
            monServomoteur_2.write(140);
            vitesse --;
            write_matrix(UN);
            }
            else{
              if(vitesse==1){
              //passer le point mort
              monServomoteur_2.write(90);
              delay(500);
              monServomoteur_1.write(90);
              vitesse --;
              write_matrix(N);
              }
              else{
                if(vitesse==0){
                //passer la marche arrière
                monServomoteur_1.write(120);
                delay(500);
                monServomoteur_2.write(50);
                vitesse --;
                write_matrix(R);
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
