#include <SoftwareSerial.h>

SoftwareSerial HC12(2, 3); // HC-12 TX Pin, HC-12 RX Pin

//int Data = 0;
char Lettre;
int DIN_pin = 12;
int CS_pin = 11;
int CLK_pin = 10;
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

void setup() {
  Serial.begin(9600);            
  HC12.begin(9600);      


  pinMode(CS_pin, OUTPUT);
  pinMode(DIN_pin, OUTPUT);
  pinMode(CLK_pin, OUTPUT);
  delay(50);
  init_MAX7219();
  clear_matrix();
  write_matrix(N);
}

void loop() {
  while (HC12.available()) {

   int Data = HC12.read();
       Serial.println(Data);
    if (Data == -1){write_matrix(R);}
    if (Data == 0){write_matrix(N);}
    if (Data == 1){write_matrix(UN);}
    if (Data == 2){write_matrix(DEUX);}
    if (Data == 3){write_matrix(TROIS);}
    if (Data == 4){write_matrix(QUATRE);}
    if (Data == 5){write_matrix(CINQ);}
    if (Data == 6){write_matrix(R);} 
 }
  
  



  //while (Serial.available()) { 
    //HC12.write(Serial.read());
   // HC12.println(Data);
  //}
}
