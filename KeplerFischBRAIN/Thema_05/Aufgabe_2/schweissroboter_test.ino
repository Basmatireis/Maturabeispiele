#include "KeplerFischBRAIN.h"

// Initialisierung des Setups
void setup() {
  KeplerFischBRAIN_INIT(); // Initialisiert das KeplerFischBRAIN
  WRITE_MOTOR(M1,0); // Setzt Motor M1 auf 0
  WRITE_MOTOR(M2,0); // Setzt Motor M2 auf 0
  WRITE_MOTOR(M3,0); // Setzt Motor M3 auf 0
  WRITE_MOTOR(M4,0); // Setzt Motor M4 auf 0
}

// Hauptprogrammschleife
void loop() {
  // Überprüft, ob Eingang D1 geschlossen ist
  if(READ_IN_CLOSED(D1)==1){
    WRITE_LED(L3,1); // Schaltet LED L3 ein
  }
  else{
    WRITE_LED(L3,0); // Schaltet LED L3 aus
  }

  // Überprüft, ob Eingang D3 geschlossen ist
  if(READ_IN_CLOSED(D3)==1){
    WRITE_LED(L1,1); // Schaltet LED L1 ein
  }
  else{
    WRITE_LED(L1,0); // Schaltet LED L1 aus
  }

  // Überprüft, ob Knopf B1 gedrückt ist
  if(READ_BUTTON_CLOSED(B1)==1){
    WRITE_MOTOR(M1,-100); // Setzt Motor M1 auf -100
  }
  // Überprüft, ob Knopf B2 gedrückt ist
  else if(READ_BUTTON_CLOSED(B2)==1){
    WRITE_MOTOR(M1,100); // Setzt Motor M1 auf 100
  }
  else{
    WRITE_MOTOR(M1,0); // Setzt Motor M1 auf 0
  }

  // Überprüft, ob Knopf B4 nicht gedrückt und Knopf B3 gedrückt ist
  if((READ_BUTTON_CLOSED(B4)==0)&&(READ_BUTTON_CLOSED(B3)==1)){
    WRITE_MOTOR(M4,100); // Setzt Motor M4 auf 100
  }
  else{
    WRITE_MOTOR(M4,0); // Setzt Motor M4 auf 0
  }

  // Überprüft, ob Knopf B4 gedrückt und Knopf B3 nicht gedrückt ist
  if((READ_BUTTON_CLOSED(B4)==1)&&(READ_BUTTON_CLOSED(B3)==0)){
    WRITE_MOTOR(M3,100); // Setzt Motor M3 auf 100
  }
  else{
    WRITE_MOTOR(M3,0); // Setzt Motor M3 auf 0
  }

  // Überprüft, ob Knopf B4 und Knopf B3 gedrückt sind
  if((READ_BUTTON_CLOSED(B4)==1)&&(READ_BUTTON_CLOSED(B3)==1)){
    WRITE_MOTOR(M4,0); // Setzt Motor M4 auf 0
    WRITE_MOTOR(M3,0); // Setzt Motor M3 auf 0
    WRITE_MOTOR(M2,100); // Setzt Motor M2 auf 100
  }
  else{
    WRITE_MOTOR(M2,0); // Setzt Motor M2 auf 0
  }
}
