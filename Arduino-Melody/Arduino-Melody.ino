/*
  Based on Tom Igoe's code
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
#include <Servo.h>

const int buzzerPin = 2;         //the number of the buzzer pin 
const int buttonPin = 7;         //the number of the pushbutton pin
const int ledPin = 11;           //the number of the LED pin
Servo myServo;


//varible will change:
int buttonState = 0;          // variable for reading the pushbutton status

void setup() {
//initialize the LED pin as an output: 
pinMode(buzzerPin, OUTPUT);
//initialize the pushbutton pin as an input: 
pinMode(buttonPin, INPUT);
pinMode(ledPin, OUTPUT);
  //put your setup code here, to run once:
  myServo.attach(9);
}

// notes in the melody:
// use 0 for a rest
// put each measure on its own line
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_B4,
  NOTE_A4, NOTE_A4, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_E4

  
};

// note durations: 1 = whole note, 4 = quarter note, 8 = eighth note, etc.:
// be sure each note or rest in the melody above has a corresponding duration below
// put each measure on its own line
int noteDurations[] = {
 4, 4, 4, 4, 4, 4, 8, 
 4, 4, 4, 4, 4, 4, 8
 
};

// set the tempo
// a tempo of 60 is one beat per second
// a tempo of 120 would be twice as fast
int beatsPerMinute = 100;


void loop() {
   //read the state of the pushbutton value:
   buttonState = digitalRead(buttonPin); 

    // initialize digital pin LED_BUILTIN as an output.
    

      

    
      // put your main code here, to run repeatedly:
      
    
    
   //check if the pushbutton is pressed. If it is, the buttonState is HIGH:
   if (buttonState == HIGH) {

    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);   

         myServo.write(180);
      delay(1000);
      myServo.write(0);
      delay(1000);
    
  // iterate over the notes of the melody:
    int len = sizeof(melody)/sizeof(melody[0]);
    for (int thisNote = 0; thisNote < len; thisNote++) {
  
      // to calculate the note duration, take one second divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
      tone(buzzerPin, melody[thisNote], noteDuration);
  
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      noTone(buzzerPin);
    }
  } else { 
    //stop melody:
    digitalWrite(ledPin, LOW);

    
  // Pause before playing again
  delay(2000); 
  }
    }
