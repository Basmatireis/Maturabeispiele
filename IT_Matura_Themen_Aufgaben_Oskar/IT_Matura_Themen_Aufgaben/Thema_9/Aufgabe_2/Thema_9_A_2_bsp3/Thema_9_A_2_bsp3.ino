#include "KeplerOpenBOT.h"

void setup() {
  KeplerOpenBOT_INIT();

  // Durchlaufe die Schleife 4-mal für die 4 Seiten des Quadrats
  for (uint8_t Counter = 1; Counter <= 4; Counter++) {
    // Gerade Strecke fahren
    WRITE_MOTOR(ML, 100);
    WRITE_MOTOR(MR, 100);
    SLEEP(2000);  // Zeit, um eine Seite zu fahren

    // Motoren stoppen, um eine Pause vor der Drehung zu machen
    WRITE_MOTOR(MR, 0);
    WRITE_MOTOR(ML, 0);
    SLEEP(500);  // Kleine Pause vor der Drehung

    // Drehung um 90 Grad (nach links)
    WRITE_MOTOR(MR, 0);
    WRITE_MOTOR(ML, 50);  // Leichte Drehung nach links
    SLEEP(1050);  // Drehzeit für 90 Grad

    // Keine Notwendigkeit mehr für das Stoppen der Motoren am Ende der Schleife
  }

  // Optional: Roboter stoppen, nachdem das Quadrat abgeschlossen ist
  WRITE_MOTOR(MR, 0);
  WRITE_MOTOR(ML, 0);
}

void loop() {
  // Keine weitere Aktion im Loop
}

