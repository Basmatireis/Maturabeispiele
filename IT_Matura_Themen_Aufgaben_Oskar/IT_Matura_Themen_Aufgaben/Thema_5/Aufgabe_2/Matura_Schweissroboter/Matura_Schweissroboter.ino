#include "KeplerFischBRAIN.h"

void setup() { 
    KeplerFischBRAIN_INIT(); 

    // Motoren initialisieren und stoppen
    WRITE_MOTOR(M1, 0); 
    WRITE_MOTOR(M2, 0); 
    WRITE_MOTOR(M3, 0); 
    WRITE_MOTOR(M4, 0); 
} 

void loop() { 
    // LED L3 basierend auf D1 steuern
    if (READ_IN_CLOSED(D1) == 1) { 
        WRITE_LED(L3, 1); 
    } else { 
        WRITE_LED(L3, 0); 
    } 

    // LED L1 basierend auf D3 steuern
    if (READ_IN_CLOSED(D3) == 1) { 
        WRITE_LED(L1, 1); 
    } else { 
        WRITE_LED(L1, 0); 
    } 

    // Motor M1 Steuerung
    if (READ_BUTTON_CLOSED(B1) == 1) { 
        WRITE_MOTOR(M1, -100); 
    } else if (READ_BUTTON_CLOSED(B2) == 1) { 
        WRITE_MOTOR(M1, 100); 
    } else { 
        WRITE_MOTOR(M1, 0); 
    } 

    // Motor M4 Steuerung
    if (READ_BUTTON_CLOSED(B4) == 0 && READ_BUTTON_CLOSED(B3) == 1) { 
        WRITE_MOTOR(M4, 100); 
    } else { 
        WRITE_MOTOR(M4, 0); 
    } 

    // Motor M3 Steuerung
    if (READ_BUTTON_CLOSED(B4) == 1 && READ_BUTTON_CLOSED(B3) == 0) { 
        WRITE_MOTOR(M3, 100); 
    } else { 
        WRITE_MOTOR(M3, 0); 
    } 

    // Motor M2 Steuerung (wenn beide B3 und B4 gedrückt sind)
    if (READ_BUTTON_CLOSED(B4) == 1 && READ_BUTTON_CLOSED(B3) == 1) { 
        WRITE_MOTOR(M4, 0); 
        WRITE_MOTOR(M3, 0); 
        WRITE_MOTOR(M2, 100); 
    } else { 
        WRITE_MOTOR(M2, 0); 
    }  
}
