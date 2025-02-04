#include "KeplerFischBRAIN.h"

uint8_t x;

void setup() {
    KeplerFischBRAIN_INIT();
    WRITE_LED(M4, 100);
    LCD_DRAW_TEXT(1, 1, "Status:");
    x = 5;
}

void loop() {  
    if (READ_BUTTON_PRESSED(B1) == 1 && x < 10) {  
        x++;  
    }  

    if (READ_BUTTON_PRESSED(B2) == 1 && x > 5) {  
        x--;  
    }  

    LCD_DRAW_INT(15, 2, x, 2);

    if (READ_IN_CLOSED(D1) == 1) {  
        LCD_DRAW_TEXT(9, 1, "Still ");
        WRITE_MOTOR(M1, 0);
    } else {  
        LCD_DRAW_TEXT(9, 1, "Drehen");
        WRITE_MOTOR(M1, 100);
        SLEEP(1000 * x);
    }  
}

