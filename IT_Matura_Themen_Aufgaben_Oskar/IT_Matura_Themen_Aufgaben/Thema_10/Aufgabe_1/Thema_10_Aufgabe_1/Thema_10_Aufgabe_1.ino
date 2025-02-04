#include "KeplerOpenBOT.h"
uint16_t EntfernungWert;
void setup() {
  KeplerOpenBOT_INIT();
  WRITE_LCD_TEXT(1, 1, "Entfernung:");
  EntfernungWert = 0;
}
void loop() {
  EntfernungWert = READ_IO_ANALOG(IO5);
  WRITE_LCD_INT(1, 2, EntfernungWert, 4);
  WRITE_MOTOR(ML, 50);
  WRITE_MOTOR(MR, 50);
  if (EntfernungWert > 430) {
    WRITE_MOTOR(ML, 50);
    WRITE_MOTOR(MR, -50);
    SLEEP(550);
    WRITE_MOTOR(ML, 50);
    WRITE_MOTOR(MR, 50);
    SLEEP(600);
    WRITE_MOTOR(ML, -50);
    WRITE_MOTOR(MR, 50);
    SLEEP(550);
  }
}
