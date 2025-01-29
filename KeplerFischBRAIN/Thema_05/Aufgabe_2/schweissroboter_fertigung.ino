#include "KeplerFischBRAIN.h"

int8_t start;

void setup() {
  // Initialisiere das KeplerFischBRAIN System
  KeplerFischBRAIN_INIT();
  
  // Setze alle Motoren auf 0 (aus)
  WRITE_MOTOR(M1, 0);
  WRITE_MOTOR(M2, 0);
  WRITE_MOTOR(M3, 0);
  WRITE_MOTOR(M4, 0);
  
  // Setze den Start-Status auf 0
  start = 0;
}

void loop() {
  // Überprüfe, ob der Knopf D1 gedrückt ist
  if (READ_IN_PRESSED(D1) == 1) {
    // Setze Motor M1 auf -50 und Motor M4 auf 100
    WRITE_MOTOR(M1, -50);
    WRITE_MOTOR(M4, 100);
    WRITE_MOTOR(M3, 0);
    
    // Warte, bis der Knopf D3 gedrückt wird
    while (true) {
      if (READ_IN_PRESSED(D3) == 1) {
        start = 1;
        break;
      }
    }
    
    // Stoppe Motor M1
    WRITE_MOTOR(M1, 0);

    // Wenn der Start-Status 1 ist, führe die folgenden Aktionen aus
    if (start == 1) {
      SLEEP(1000); // Warte 1 Sekunde
      WRITE_MOTOR(M1, 50); // Setze Motor M1 auf 50
      SLEEP(3200); // Warte 3,2 Sekunden
      WRITE_MOTOR(M1, 0); // Stoppe Motor M1
      SLEEP(200); // Warte 0,2 Sekunden
      
      // Wiederhole das Ein- und Ausschalten von Motor M2
      for (int i = 0; i < 3; i++) {
        WRITE_MOTOR(M2, 100);
        SLEEP(200);
        WRITE_MOTOR(M2, 0);
        SLEEP(200);
      }

      WRITE_MOTOR(M1, 50); // Setze Motor M1 auf 50
      SLEEP(4100); // Warte 4,1 Sekunden
      WRITE_MOTOR(M1, 0); // Stoppe Motor M1
      SLEEP(200); // Warte 0,2 Sekunden
      
      // Wiederhole das Ein- und Ausschalten von Motor M2
      for (int i = 0; i < 3; i++) {
        WRITE_MOTOR(M2, 100);
        SLEEP(200);
        WRITE_MOTOR(M2, 0);
        SLEEP(200);
      }

      WRITE_MOTOR(M1, 50); // Setze Motor M1 auf 50
      SLEEP(5200); // Warte 5,2 Sekunden
      WRITE_MOTOR(M1, 0); // Stoppe Motor M1
      SLEEP(200); // Warte 0,2 Sekunden
      
      // Wiederhole das Ein- und Ausschalten von Motor M2
      for (int i = 0; i < 3; i++) {
        WRITE_MOTOR(M2, 100);
        SLEEP(200);
        WRITE_MOTOR(M2, 0);
        SLEEP(200);
      }

      WRITE_MOTOR(M1, 50); // Setze Motor M1 auf 50
      SLEEP(5900); // Warte 5,9 Sekunden
      WRITE_MOTOR(M1, 0); // Stoppe Motor M1
      WRITE_MOTOR(M3, 100); // Setze Motor M3 auf 100
      WRITE_MOTOR(M4, 0); // Stoppe Motor M4

      // Setze den Start-Status zurück auf 0
      start = 0;
    }
  }
}
