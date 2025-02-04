#include "KeplerOpenBOT.h"

int16_t StartWert;
uint16_t AktuellerWert;

void setup() {
  KeplerOpenBOT_INIT();
  WRITE_I2C_BNO055_INIT();
  WRITE_LCD_CONTRAST(180);

  StartWert = READ_I2C_BNO055_YAW();
  if (StartWert+90 > 360){ StartWert = StartWert - 360;}
  AktuellerWert = 0;
  WRITE_MOTOR(ML, 20);
  WRITE_MOTOR(MR, -20);
}

void loop() {
  AktuellerWert = READ_I2C_BNO055_YAW();
  WRITE_LCD_INT(1,2,AktuellerWert,3);
  WRITE_LCD_INT(1,4,StartWert+90,3);
  if (AktuellerWert >= StartWert + 90) {
    WRITE_MOTOR(ML, 0);
    WRITE_MOTOR(MR, 0);
  }
}