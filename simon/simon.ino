/*
https://123d.circuits.io/
 */
#include "pitches.h"

#define numLevels 4
#define pinLedRed 9
#define pinButtonRed 12
#define pinLedGreen 8
#define pinButtonGreen 11
#define pinLedYellow 7
#define pinButtonYellow 10
#define pinBuzzer 3

int vetPinLeds[]={pinLedRed, pinLedGreen, pinLedYellow};
int vetPinButtons[]={pinButtonRed, pinButtonGreen, pinButtonYellow};
int vetTons[]={NOTE_DS8, NOTE_GS5, NOTE_AS3};
int tonsLevelGame[10]={0,0,0,0,0,0,0,0,0,0};
int contTons;

int userTonsSelect[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int contUser;

bool userInput = false;

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  contTons = 0;
  contUser = 0;
  pinMode(pinLedRed, OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinLedYellow, OUTPUT);

  pinMode(pinButtonRed, INPUT);
  pinMode(pinButtonGreen, INPUT);
  pinMode(pinButtonYellow, INPUT);

  randomSeed(analogRead(0));
}

void loop() {

  if(userInput == true){
     if(contUser < contTons){
         if(digitalRead(vetPinButtons[0]) == HIGH) {
            pressButton(0);
            userTonsSelect[contUser]=0;
            validaButton();
            contUser= contUser+1;
          }
          else if (digitalRead(vetPinButtons[1]) == HIGH) {
            pressButton(1);
            userTonsSelect[contUser]=1;
            validaButton();
            contUser= contUser+1;
          }
          else if(digitalRead(vetPinButtons[2]) == HIGH) {
            pressButton(2);
            userTonsSelect[contUser]=2;
            validaButton();
            contUser= contUser+1;
          }
          
          if (contUser >= numLevels) {
            musicWinner();
            contTons = 0; 
            randomSeed(analogRead(0));  
            delay(3000);
          }
     }
     else {
         //usuário acerto a sequencia e vai para a proxima rodada
         userInput = false;
         contUser = 0;
         delay(2500);
     }
  }

  else {
      
      tonsLevelGame[contTons] = random(10,13) - 10;
      
      for (int i=0; i <= contTons; i++){
          digitalWrite(vetPinLeds[tonsLevelGame[i]], HIGH);
          tone(pinBuzzer, vetTons[tonsLevelGame[i]], 250);
          delay(1000);
          
          digitalWrite(vetPinLeds[tonsLevelGame[i]], LOW);
          noTone(pinBuzzer);
          delay(500);
      }
    
      contTons=contTons+1;

      userInput = true;      
  }

}

void pressButton(int indice){
  digitalWrite(vetPinLeds[indice],HIGH);
  tone(pinBuzzer, vetTons[indice], 250);
  delay(250);
  digitalWrite(vetPinLeds[indice],LOW); 
}

void validaButton(){
     if( userTonsSelect[contUser] != tonsLevelGame[contUser] ) {
        musicError();
        contTons = 0; 
        randomSeed(analogRead(0));
      }
}

void musicError() {
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(pinBuzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(pinBuzzer);
  }  
}

void musicWinner() {
  //tone(pin, note, duration)
    tone(3,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(3,LA3,Q);
    delay(1+Q);
    tone(3,LA3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    
    tone(3,LA3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,LA3,H);
    delay(1+H);
    
    tone(3,E4,Q); 
    delay(1+Q); 
    tone(3,E4,Q);
    delay(1+Q);
    tone(3,E4,Q);
    delay(1+Q);
    tone(3,F4,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    
    tone(3,Ab3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,LA3,H);
    delay(1+H);
    
    tone(3,LA4,Q);
    delay(1+Q);
    tone(3,LA3,E+S);
    delay(1+E+S);
    tone(3,LA3,S);
    delay(1+S);
    tone(3,LA4,Q);
    delay(1+Q);
    tone(3,Ab4,E+S);
    delay(1+E+S);
    tone(3,G4,S);
    delay(1+S);
    
    tone(3,Gb4,S);
    delay(1+S);
    tone(3,E4,S);
    delay(1+S);
    tone(3,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(3,Bb3,E);
    delay(1+E);
    tone(3,Eb4,Q);
    delay(1+Q);
    tone(3,D4,E+S);
    delay(1+E+S);
    tone(3,Db4,S);
    delay(1+S);
    
    tone(3,C4,S);
    delay(1+S);
    tone(3,B3,S);
    delay(1+S);
    tone(3,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(3,F3,E);
    delay(1+E);
    tone(3,Ab3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,LA3,S);
    delay(1+S);
    
    tone(3,C4,Q);
    delay(1+Q);
     tone(3,LA3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,E4,H);
    delay(1+H);
    
     tone(3,LA4,Q);
    delay(1+Q);
    tone(3,LA3,E+S);
    delay(1+E+S);
    tone(3,LA3,S);
    delay(1+S);
    tone(3,LA4,Q);
    delay(1+Q);
    tone(3,Ab4,E+S);
    delay(1+E+S);
    tone(3,G4,S);
    delay(1+S);
    
    tone(3,Gb4,S);
    delay(1+S);
    tone(3,E4,S);
    delay(1+S);
    tone(3,F4,E);
    delay(1+E);
    delay(1+E);//PAUSE
    tone(3,Bb3,E);
    delay(1+E);
    tone(3,Eb4,Q);
    delay(1+Q);
    tone(3,D4,E+S);
    delay(1+E+S);
    tone(3,Db4,S);
    delay(1+S);
    
    tone(3,C4,S);
    delay(1+S);
    tone(3,B3,S);
    delay(1+S);
    tone(3,C4,E);
    delay(1+E);
    delay(1+E);//PAUSE QUASI FINE RIGA
    tone(3,F3,E);
    delay(1+E);
    tone(3,Ab3,Q);
    delay(1+Q);
    tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    
    tone(3,LA3,Q);
    delay(1+Q);
     tone(3,F3,E+S);
    delay(1+E+S);
    tone(3,C4,S);
    delay(1+S);
    tone(3,LA3,H);
    delay(1+H);
    
    delay(2*H);  
}
