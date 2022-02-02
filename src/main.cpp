/*
  Titre      : Servo moteur
  Auteur     : Anis Aliouachene
  Date       : 30/01/2022
  Description: Controler un servo moteur
  Version    : 0.0.1
*/

#include <Arduino.h>
#include<Servo.h>
#define NOTE_FS6 1480;

// Declaration constantes 
const int TOUCH_SENSOR = 2; 
const int BOUTTON = 3; 
const int LED_RED = 4;
const int LED_BLUE = 5; 
const int SERVO = 9; 
const int SPEAKER = 8;
const int Duree = 200; 

// Variables 
int Sound = NOTE_FS6; 
int pos = 0;

Servo myservo;



void setup() {

  //setup broches
  pinMode(TOUCH_SENSOR, INPUT);
  pinMode(BOUTTON, INPUT); 
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(SPEAKER , OUTPUT);
  myservo.attach(SERVO);

  }


void loop() {
  
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);

  // Condition Touch Sensor 
  if (digitalRead(TOUCH_SENSOR) == 1){
          
        if (pos == 180)
        {    
            tone(SPEAKER, Sound, Duree);  
            digitalWrite(LED_RED, HIGH);
            delay(1);
            noTone(SPEAKER);
    
      }else if (pos < 180 ){
          pos+= 1;
          myservo.write(pos); 
          delay(20);
      }

  }

  // Condition Bouton 
  if (digitalRead(BOUTTON) == HIGH){
        
        if (pos == 0)
        {    
            tone(SPEAKER, Sound, Duree);  
            digitalWrite(LED_BLUE, HIGH);
            delay(1);
            noTone(SPEAKER);

      }else if (pos > 0) {
          pos-= 1;
          myservo.write(pos);
          delay(20);
      }    
}

}

