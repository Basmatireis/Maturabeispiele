## schweissroboter_test.ino

Diese Datei initialisiert das KeplerFischBRAIN-System und steuert die Motoren und LEDs basierend auf dem Zustand verschiedener Eingänge.

### Setup

Die `setup`-Funktion initialisiert das System und setzt alle Motoren auf 0 (aus).

```cpp
void setup() {
  KeplerFischBRAIN_INIT();
  WRITE_MOTOR(M1, 0);
  WRITE_MOTOR(M2, 0);
  WRITE_MOTOR(M3, 0);
  WRITE_MOTOR(M4, 0);
}
```

### Loop

Die `loop`-Funktion überprüft kontinuierlich den Zustand verschiedener Eingänge und steuert die Motoren und LEDs entsprechend.

```cpp
void loop() {
  if (READ_IN_CLOSED(D1) == 1) {
    WRITE_LED(L3, 1);
  } else {
    WRITE_LED(L3, 0);
  }

  if (READ_IN_CLOSED(D3) == 1) {
    WRITE_LED(L1, 1);
  } else {
    WRITE_LED(L1, 0);
  }

  if (READ_BUTTON_CLOSED(B1) == 1) {
    WRITE_MOTOR(M1, -100);
  } else if (READ_BUTTON_CLOSED(B2) == 1) {
    WRITE_MOTOR(M1, 100);
  } else {
    WRITE_MOTOR(M1, 0);
  }

  if ((READ_BUTTON_CLOSED(B4) == 0) && (READ_BUTTON_CLOSED(B3) == 1)) {
    WRITE_MOTOR(M4, 100);
  } else {
    WRITE_MOTOR(M4, 0);
  }

  if ((READ_BUTTON_CLOSED(B4) == 1) && (READ_BUTTON_CLOSED(B3) == 0)) {
    WRITE_MOTOR(M3, 100);
  } else {
    WRITE_MOTOR(M3, 0);
  }

  if ((READ_BUTTON_CLOSED(B4) == 1) && (READ_BUTTON_CLOSED(B3) == 1)) {
    WRITE_MOTOR(M4, 0);
    WRITE_MOTOR(M3, 0);
    WRITE_MOTOR(M2, 100);
  } else {
    WRITE_MOTOR(M2, 0);
  }
}
```

## schweissroboter_fertigung.ino

Diese Datei initialisiert das KeplerFischBRAIN-System und steuert die Motoren basierend auf dem Zustand verschiedener Eingänge, mit einem Fokus auf eine spezifische Abfolge von Motoroperationen.

### Setup

Die `setup`-Funktion initialisiert das System, setzt alle Motoren auf 0 (aus) und initialisiert die Variable `start`.

```cpp
void setup() {
  KeplerFischBRAIN_INIT();
  WRITE_MOTOR(M1, 0);
  WRITE_MOTOR(M2, 0);
  WRITE_MOTOR(M3, 0);
  WRITE_MOTOR(M4, 0);
  start = 0;
}
```

### Loop

Die `loop`-Funktion überprüft, ob der Knopf D1 gedrückt ist, um eine Abfolge von Motoroperationen zu starten. Sie wartet darauf, dass der Knopf D3 gedrückt wird, um mit der Abfolge fortzufahren.

```cpp
void loop() {
  if (READ_IN_PRESSED(D1) == 1) {
    WRITE_MOTOR(M1, -50);
    WRITE_MOTOR(M4, 100);
    WRITE_MOTOR(M3, 0);

    while (true) {
      if (READ_IN_PRESSED(D3) == 1) {
        start = 1;
        break;
      }
    }

    WRITE_MOTOR(M1, 0);

    if (start == 1) {
      SLEEP(1000);
      WRITE_MOTOR(M1, 50);
      SLEEP(3200);
      WRITE_MOTOR(M1, 0);
      SLEEP(200);

      for (int i = 0; i < 3; i++) {
        WRITE_MOTOR(M2, 100);
        SLEEP(200);
        WRITE_MOTOR(M2, 0);
        SLEEP(200);
      }

      WRITE_MOTOR(M1, 50);
      SLEEP(4100);
      WRITE_MOTOR(M1, 0);
      SLEEP(200);

      for (int i = 0; i < 3; i++) {
        WRITE_MOTOR(M2, 100);
        SLEEP(200);
        WRITE_MOTOR(M2, 0);
        SLEEP(200);
      }

      WRITE_MOTOR(M1, 50);
      SLEEP(5200);
      WRITE_MOTOR(M1, 0);
      SLEEP(200);

      for (int i = 0; i < 3; i++) {
        WRITE_MOTOR(M2, 100);
        SLEEP(200);
        WRITE_MOTOR(M2, 0);
        SLEEP(200);
      }

      WRITE_MOTOR(M1, 50);
      SLEEP(5900);
      WRITE_MOTOR(M1, 0);
      WRITE_MOTOR(M3, 100);
      WRITE_MOTOR(M4, 0);

      start = 0;
    }
  }
}
