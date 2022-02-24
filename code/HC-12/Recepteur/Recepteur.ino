#include <SoftwareSerial.h>
SoftwareSerial HC12(2, 3);//RX, TX

int bp = 7;
int bm = 8;
int p = 1;
int m = 2;
int DataIn = 0;
int ledR = 5;
int ledV = 6;


void setup() {
  // put your setup code here, to run once:
  HC12.begin(9600);
  Serial.begin(9600);
  pinMode(ledR, OUTPUT);
  pinMode(ledV, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (HC12.available() > 1) //si données arrivées, les lire
  { 
    DataIn = HC12.parseInt();//lit le port serie et convertit en integer (-32,768 to 32,767)
    if (DataIn == p) { //si le code convenu est bon
      digitalWrite(ledR, HIGH);
      digitalWrite(ledV, LOW);
    }
    if (DataIn == m) { //si le code convenu est bon
      digitalWrite(ledV, HIGH);
      digitalWrite(ledR, LOW);
    }
   HC12.flush();//Vide le buffer 
   delay(20);
  }
}
