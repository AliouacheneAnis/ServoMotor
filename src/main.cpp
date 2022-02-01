/*
  Titre      : Servo moteur
  Auteur     : Anis Aliouachene
  Date       : 30/01/2022
  Description: Controler un servo moteur
  Version    : 0.0.1
*/


#include <Arduino.h>
#include<Servo.h>




const int TOUCH_SENSOR = 2; 
const int BOUTTON = 3; 
const int LED_RED = 4;
const int LED_BLUE = 5; 
const int SERVO = 9; 

#define NOTE_FS6 1480;
int Sound = NOTE_FS6; 

const int Durre = 200; 

Servo myservo;
int pos = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH_SENSOR, INPUT);
  pinMode(BOUTTON, INPUT); 
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(8 , OUTPUT);
  myservo.attach(SERVO);

  }


void loop() {
  
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);


  // put your main code here, to run repeatedly:
  if (digitalRead(TOUCH_SENSOR) == 1){
          
        if (pos == 180)
        {    
            tone(8, Sound, 200);  
            digitalWrite(LED_RED, HIGH);
    
      }else if (pos < 180 ){
          pos+= 1;
          myservo.write(pos); 
          delay(20);
      }

  }


  if (digitalRead(BOUTTON) == HIGH){
        
        if (pos == 0)
        {    
            tone(8, Sound, 200);  
            digitalWrite(LED_BLUE, HIGH);

      }else if (pos > 0) {
          pos-= 1;
          myservo.write(pos);
          delay(20);
      }    
}

}

