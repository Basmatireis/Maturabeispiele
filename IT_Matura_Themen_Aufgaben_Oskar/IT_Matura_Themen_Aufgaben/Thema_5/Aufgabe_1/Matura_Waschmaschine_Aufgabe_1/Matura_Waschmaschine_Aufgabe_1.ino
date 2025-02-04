#include "KeplerFischBRAIN.h"

int x = 0;
int vorgang = 0;

void setup() {
    KeplerFischBRAIN_INIT();
    WRITE_MOTOR(M3, 0);
    LCD_DRAW_TEXT(1, 1, "Start");
}

void loop() {
    if ((READ_IN_PRESSED(D1) == 1) && (READ_IN_CLOSED(D3) == 1) && (vorgang == 0)) {
        vorgang = 1;
    }

    switch (vorgang) {
        case 1:  // Waschgang
            LCD_DRAW_TEXT(1, 1, "Waschgang    ");
            WRITE_MOTOR(M3, 30);
            WRITE_MOTOR(M1, 100);
            SLEEP(10000);
            vorgang = 2;
            break;

        case 2:  // Schleudergang
            LCD_DRAW_TEXT(1, 1, "Schleudergang");
            WRITE_MOTOR(M3, 100);
            SLEEP(15000);
            x = 0;
            vorgang = 3;
            break;

        case 3:  // Trocknen
            LCD_DRAW_TEXT(1, 1, "Trocknen     ");
            while (x < 4) {
                WRITE_MOTOR(M3, 30);
                SLEEP(5000);
                WRITE_MOTOR(M3, -30);
                SLEEP(5000);
                WRITE_MOTOR(M3, 0);
                SLEEP(2000);
                x++;
            }
            vorgang = 4;
            break;

        case 4:  // Waschgang fertig
            LCD_DRAW_TEXT(1, 1, "Wäsche fertig");
            LCD_DRAW_TEXT(1, 2, "bitte aufhängen");
            WRITE_MOTOR(M3, 0);
            WRITE_MOTOR(M1, 0);
            vorgang = 0;  // Zurücksetzen
            break;
    }

    // Sicherheitsstopp, falls Tür geöffnet wird
    if (READ_IN_CLOSED(D3) == 0) { 
        WRITE_MOTOR(M3, 0);
        WRITE_MOTOR(M1, 0);
        LCD_DRAW_TEXT(1, 1, "Start");
        vorgang = 0;
    }
}
