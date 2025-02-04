#include "KeplerOpenBOT.h"

uint8_t Counter;

void setup() {
  KeplerOpenBOT_INIT();
  Counter = 1;

  while (Counter <= 4) {
    // Gerade Strecke fahren
    WRITE_MOTOR(ML, 100);
    WRITE_MOTOR(MR, 100);
    SLEEP(2000);  // Zeit, um eine Seite zu fahren

    // Motoren stoppen
    WRITE_MOTOR(MR, 0);
    WRITE_MOTOR(ML, 0);
    SLEEP(500);  // Kurze Pause, bevor der Roboter dreht

    // Drehung um 90 Grad
    WRITE_MOTOR(MR, 0);
    WRITE_MOTOR(ML, 50);  // Leichte Drehung (Korrekturwert nach Bedarf anpassen)
    SLEEP(1050);  // Zeit, um 90 Grad zu drehen

    // Zähler erhöhen, um zur nächsten Seite überzugehen
    Counter = Counter + 1;
  }

  // Roboter stoppen, nachdem er das Quadrat abgeschlossen hat
  WRITE_MOTOR(MR, 0);
  WRITE_MOTOR(ML, 0);
}

void loop() {
  // Keine weitere Aktion im Loop
}
