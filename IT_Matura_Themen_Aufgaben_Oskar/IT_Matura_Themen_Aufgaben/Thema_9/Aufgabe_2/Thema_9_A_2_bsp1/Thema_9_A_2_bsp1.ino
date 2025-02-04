#include "KeplerOpenBOT.h"

void setup() {
  KeplerOpenBOT_INIT();

  // Erste Seite des Quadrats
  WRITE_MOTOR(ML, 100);  
  WRITE_MOTOR(MR, 100);  
  SLEEP(2000);  // Zeit, um eine Seite zu fahren
  WRITE_MOTOR(MR, 0);  
  WRITE_MOTOR(ML, 50);  // Drehung um 90 Grad
  SLEEP(1050);

  // Zweite Seite des Quadrats
  WRITE_MOTOR(ML, 100);  
  WRITE_MOTOR(MR, 100);  
  SLEEP(2000);  // Zeit, um eine Seite zu fahren
  WRITE_MOTOR(MR, 0);  
  WRITE_MOTOR(ML, 50);  // Drehung um 90 Grad
  SLEEP(1050);

  // Dritte Seite des Quadrats
  WRITE_MOTOR(ML, 100);  
  WRITE_MOTOR(MR, 100);  
  SLEEP(2000);  // Zeit, um eine Seite zu fahren
  WRITE_MOTOR(MR, 0);  
  WRITE_MOTOR(ML, 50);  // Drehung um 90 Grad
  SLEEP(1050);

  // Vierte Seite des Quadrats
  WRITE_MOTOR(ML, 100);  
  WRITE_MOTOR(MR, 100);  
  SLEEP(2000);  // Zeit, um eine Seite zu fahren
  WRITE_MOTOR(MR, 0);  
  WRITE_MOTOR(ML, 50);  // Drehung um 90 Grad
  SLEEP(1050);

  // Stoppt den Roboter
  WRITE_MOTOR(MR, 0);  
  WRITE_MOTOR(ML, 0);  
}

void loop() {
  // Keine weitere Aktion im Loop
}

