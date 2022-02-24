#include <SoftwareSerial.h>
SoftwareSerial HC12(2, 3);//RX, TX

int bp = 7;
int bm = 8;
int p = 1;
int m = 2;
int dataIn = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(bp, INPUT);
  pinMode(bm, INPUT);
  HC12.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(bp)==1){
    HC12.println(p);
  }

  if(digitalRead(bm)==1){
    HC12.println(m);
  }

}
