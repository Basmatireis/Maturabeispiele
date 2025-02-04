// **********************************
// *** KeplerOpenBOTV2 06.05.2021 ***
// **********************************

// ********** Hardware Connections **********

// IO1 A7
// IO2 D6 PWM OC0A
// IO3 D5 PWM OC0B
// IO4 D3 PWM OC2B
// IO5 A1
// IO6 A0
// IO7 A2
// IO8 A3

// D0 SPI2 CS
// D1 SPICAM CS
// D2 SPI1 CS
// D3 IO4 PWM OC2B
// D4 DISPLAY CE 
// D5  IO3 PWM OC0B
// D6  IO2 PWM OC0A
// D7  DISPLAY DC
// D8  LED
// D9  SERVO LINKS PWM OC1A
// D10 SERVO RECHTS PWM OC1B
// D11 MOSI
// D12 MISO
// D13 SCK

// A0 IO6
// A1 IO5
// A2 IO7
// A3 IO8
// A4 I2C SDA
// A5 I2C SCL
// A6 TASTER
// A7 IO1

#include <Wire.h>
#include <SPI.h>

#define IO1 0x01
#define IO2 0x02
#define IO3 0x03
#define IO4 0x04
#define IO5 0x05
#define IO6 0x06
#define IO7 0x07
#define IO8 0x08

#define B1 0x11
#define B2 0x12
#define B3 0x13
#define B4 0x14

#define ML 0x21
#define MR 0x22

#define SPI1 0x31
#define SPI2 0x32

// *** I2C BNO055 ***

#define BNO055_ADDR      (0x28 << 1) 
#define BNO055_CHIP_ID          0x00
#define BNO055_CHIP_ID_VALUE    0xa0   
#define BNO055_AXIS_MAP_CONFIG  0x41
#define BNO055_OPR_MODE         0x3d
#define CONFIGMODE              0x00
#define MODE_NDOF               0x0c 
#define ACCEL_OFFSET_X_LSB      0x55
#define ACCEL_OFFSET_X_MSB      0x56
#define ACCEL_OFFSET_Y_LSB      0x57
#define ACCEL_OFFSET_Y_MSB      0x58
#define ACCEL_OFFSET_Z_LSB      0x59
#define ACCEL_OFFSET_Z_MSB      0x5a
#define MAG_OFFSET_X_LSB        0x5b
#define MAG_OFFSET_X_MSB        0x5c
#define MAG_OFFSET_Y_LSB        0x5d
#define MAG_OFFSET_Y_MSB        0x5e
#define MAG_OFFSET_Z_LSB        0x5f
#define MAG_OFFSET_Z_MSB        0x60
#define GYRO_OFFSET_X_LSB       0x61
#define GYRO_OFFSET_X_MSB       0x62
#define GYRO_OFFSET_Y_LSB       0x63
#define GYRO_OFFSET_Y_MSB       0x64
#define GYRO_OFFSET_Z_LSB       0x65
#define GYRO_OFFSET_Z_MSB       0x66
#define ACCEL_RADIUS_LSB        0x67
#define ACCEL_RADIUS_MSB        0x68
#define MAG_RADIUS_LSB          0x69
#define MAG_RADIUS_MSB          0x6a
#define BNO055_EULER_H_LSB      0x1a
#define BNO055_EULER_H_MSB      0x1b
#define BNO055_EULER_R_LSB      0x1c
#define BNO055_EULER_R_MSB      0x1d
#define BNO055_EULER_P_LSB      0x1e
#define BNO055_EULER_P_MSB      0x1f

// ********** GLOBALS **********

static const byte ASCII[][5] = {// ASCII Tabelle mit Fonts
 {0x00, 0x00, 0x00, 0x00, 0x00} // 20  
,{0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
,{0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
,{0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
,{0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
,{0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
,{0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
,{0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
,{0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
,{0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
,{0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
,{0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
,{0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
,{0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
,{0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
,{0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
,{0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
,{0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
,{0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
,{0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
,{0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
,{0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
,{0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
,{0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
,{0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
,{0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
,{0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
,{0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
,{0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
,{0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
,{0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
,{0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
,{0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
,{0x10, 0x08, 0x08, 0x10, 0x08} // 7e ←
,{0x78, 0x46, 0x41, 0x46, 0x78} // 7f →
};

const int LEDPIN = 8;
const int DISPLAYCEPIN = 4;
const int DISPLAYDCPIN = 7;

const int SPI1CSPIN = 2;
const int SPI2CSPIN = 0;
const int SPICAMCSPIN = 1;

uint16_t COUNTER;

uint8_t TEXTLINE1[15];
uint8_t TEXTLINE2[15];
uint8_t TEXTLINE3[15];
uint8_t TEXTLINE4[15];
uint8_t TEXTLINE5[15];
uint8_t TEXTLINE6[15];

uint8_t B1_CLOSED;
uint8_t B2_CLOSED;
uint8_t B3_CLOSED;
uint8_t B4_CLOSED;

uint8_t D1_CLOSED;
uint8_t D2_CLOSED;
uint8_t D3_CLOSED;
uint8_t D4_CLOSED;
uint8_t D5_CLOSED;
uint8_t D6_CLOSED;
uint8_t D7_CLOSED;
uint8_t D8_CLOSED;


// ********** DISPLAY **********

void DISPLAY_WRITECMD(uint8_t cmd)
{
  digitalWrite(DISPLAYDCPIN, LOW);
  digitalWrite(DISPLAYCEPIN, LOW);
  SPI.transfer(cmd);
  digitalWrite(DISPLAYCEPIN, HIGH);
}

void DISPLAY_WRITEDATA(uint8_t data)
{
  digitalWrite(DISPLAYDCPIN, HIGH);
  digitalWrite(DISPLAYCEPIN, LOW);
  SPI.transfer(data);
  digitalWrite(DISPLAYCEPIN, HIGH);
}

void DISPLAY_WRITECHARACTER(char character)
{
  for(int i=0; i < 5; i++) DISPLAY_WRITEDATA(ASCII[character - 0x20][i]);
  DISPLAY_WRITEDATA(0x00); 
}

void DISPLAY_WRITESTRING(char *characters)
{
  while(*characters) DISPLAY_WRITECHARACTER(*characters++);
}

void DISPLAY_CLEAR()
{
  for(int i=0; i < 504; i++) DISPLAY_WRITEDATA(0x00);
}

void DISPLAY_POS(uint8_t x, uint8_t y)
{
  uint8_t xpos = (x-1)*6;
  uint8_t ypos = y-1;
  DISPLAY_WRITECMD(0x80|xpos);
  DISPLAY_WRITECMD(0x40|ypos);
}


// ********** IOS **********

uint16_t READ_IO_CLOSED(uint8_t port)
{

  if (port==IO1)
  {
    pinMode(A7, INPUT);
    digitalWrite(A7, HIGH);
    if (digitalRead(A7)==0) return 1;
    else return 0;
  }
  if (port==IO2)
  {
    pinMode(6, INPUT);
    digitalWrite(6, HIGH);
    if (digitalRead(6)==0) return 1;
    else return 0;
  }
  if (port==IO3)
  {
    pinMode(5, INPUT);
    digitalWrite(5, HIGH);
    if (digitalRead(5)==0) return 1;
    else return 0;
  }
  if (port==IO4)
  {
    pinMode(3, INPUT);
    digitalWrite(3, HIGH);
    if (digitalRead(3)==0) return 1;
    else return 0;
  }
  if (port==IO5)
  {
    pinMode(A1, INPUT);
    digitalWrite(A1, HIGH);
    if (digitalRead(A1)==0) return 1;
    else return 0;
  }
  if (port==IO6)
  {
    pinMode(A0, INPUT);
    digitalWrite(A0, HIGH);
    if (digitalRead(A0)==0) return 1;
    else return 0;
  }
  if (port==IO7)
  {
    pinMode(A2, INPUT);
    digitalWrite(A2, HIGH);
    if (digitalRead(A2)==0) return 1;
    else return 0;
  }
  if (port==IO8)
  {
    pinMode(A3, INPUT);
    digitalWrite(A3, HIGH);
    if (digitalRead(A3)==0) return 1;
    else return 0;
  }
}


uint8_t READ_IO_PRESSED(uint8_t port)
{
  uint8_t D_PRESSED = 0;

  if (port==IO1)
  {
    pinMode(A7, INPUT);
    digitalWrite(A7, HIGH);
    if (digitalRead(A7)==0)
    {
      if (D1_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D1_CLOSED = 1;
    }
    else
    {
      D1_CLOSED = 0;
    } 
  }
  
  if (port==IO2)
  {
    pinMode(6, INPUT);
    digitalWrite(6, HIGH);
    if (digitalRead(6)==0)
    {
      if (D2_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D2_CLOSED = 1;
    }
    else
    {
      D2_CLOSED = 0;
    } 
  }

  if (port==IO3)
  {
    pinMode(5, INPUT);
    digitalWrite(5, HIGH);
    if (digitalRead(5)==0)
    {
      if (D3_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D3_CLOSED = 1;
    }
    else
    {
      D3_CLOSED = 0;
    } 
  }

  if (port==IO4)
  {
    pinMode(3, INPUT);
    digitalWrite(3, HIGH);
    if (digitalRead(3)==0)
    {
      if (D4_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D4_CLOSED = 1;
    }
    else
    {
      D4_CLOSED = 0;
    } 
  }

  if (port==IO5)
  {
    pinMode(A1, INPUT);
    digitalWrite(A1, HIGH);
    if (digitalRead(A1)==0)
    {
      if (D5_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D5_CLOSED = 1;
    }
    else
    {
      D5_CLOSED = 0;
    } 
  }

  if (port==IO6)
  {
    pinMode(A0, INPUT);
    digitalWrite(A0, HIGH);
    if (digitalRead(A0)==0)
    {
      if (D6_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D6_CLOSED = 1;
    }
    else
    {
      D6_CLOSED = 0;
    } 
  }

  if (port==IO7)
  {
    pinMode(A2, INPUT);
    digitalWrite(A2, HIGH);
    if (digitalRead(A2)==0)
    {
      if (D7_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D7_CLOSED = 1;
    }
    else
    {
      D7_CLOSED = 0;
    } 
  }

  if (port==IO8)
  {
    pinMode(A3, INPUT);
    digitalWrite(A3, HIGH);
    if (digitalRead(A3)==0)
    {
      if (D8_CLOSED==0)
      {
        D_PRESSED = 1;
      }
      D8_CLOSED = 1;
    }
    else
    {
      D8_CLOSED = 0;
    } 
  }

  return D_PRESSED;
}  


uint16_t READ_IO_ANALOG(uint8_t port)
{
	uint16_t value;

  if (port==IO1) value = analogRead(7);
  if (port==IO5) value = analogRead(1);
  if (port==IO6) value = analogRead(0);
  if (port==IO7) value = analogRead(2);
  if (port==IO8) value = analogRead(3);
  
  return value;
}


// ********** BUTTONS **********

uint16_t READ_BUTTON_CLOSED(uint8_t port)
{
  uint16_t valueanalog;
  uint16_t valuebutton = 0;

  valueanalog = analogRead(6);
  if ((port==B1)&&(valueanalog<600)&&(valueanalog>410)) valuebutton = 1;
  if ((port==B2)&&(valueanalog<390)&&(valueanalog>210)) valuebutton = 1;
  if ((port==B3)&&(valueanalog<190)&&(valueanalog>100)) valuebutton = 1;
  if ((port==B4)&&(valueanalog<30)) valuebutton = 1;
  
  return valuebutton;
}


uint8_t READ_BUTTON_PRESSED(uint8_t port)
{
  uint8_t B_PRESSED = 0;
  
  if (port==B1)
  {
    if (READ_BUTTON_CLOSED(B1)==0)
    {
      if (B1_CLOSED==0)
      {
        B_PRESSED = 1;
      }
      B1_CLOSED = 1;
    }
    else
    {
      B1_CLOSED = 0;
    } 
  }
  
  if (port==B2)
  {
    if (READ_BUTTON_CLOSED(B2)==0)
    {
      if (B2_CLOSED==0)
      {
        B_PRESSED = 1;
      }
      B2_CLOSED = 1;
    }
    else
    {
      B2_CLOSED = 0;
    } 
  }

  if (port==B3)
  {
    if (READ_BUTTON_CLOSED(B3)==0)
    {
      if (B3_CLOSED==0)
      {
        B_PRESSED = 1;
      }
      B3_CLOSED = 1;
    }
    else
    {
      B3_CLOSED = 0;
    } 
  }

  if (port==B4)
  {
    if (READ_BUTTON_CLOSED(B4)==0)
    {
      if (B4_CLOSED==0)
      {
        B_PRESSED = 1;
      }
      B4_CLOSED = 1;
    }
    else
    {
      B4_CLOSED = 0;
    } 
  }

  return B_PRESSED;

}


// ********** LED **********

void WRITE_LED(uint8_t value)
{
  if (value==1) digitalWrite(LEDPIN, HIGH);
  else digitalWrite(LEDPIN, LOW);
}
 

// ********** DISPLAY **********

void WRITE_LCD_CLEAR()
{
  DISPLAY_CLEAR();
}

void WRITE_LCD_CONTRAST(uint8_t value)
{
  DISPLAY_WRITECMD(0x21);
  DISPLAY_WRITECMD(value);
  DISPLAY_WRITECMD(0x20);
}

void WRITE_LCD_INT(uint8_t x, uint8_t y, int value, int len)
{
  char text[7];
  DISPLAY_POS(x,y);
  
  if ((len>=1)&&(len<=6)&&((x>=1)&&(x<=14)))
  {
    if (len==1) sprintf(text,"%1d",value);
    if (len==2) sprintf(text,"%2d",value);
    if (len==3) sprintf(text,"%3d",value);
    if (len==4) sprintf(text,"%4d",value);
    if (len==5) sprintf(text,"%5d",value);
    if (len==6) sprintf(text,"%6d",value);
    for(int j=0; j<len; j++)
    {
      for(int i=0; i < 5; i++) DISPLAY_WRITEDATA(ASCII[text[j] - 0x20][i]);
      DISPLAY_WRITEDATA(0x00); 
    }
  }
}

void WRITE_LCD_TEXT(uint8_t x, uint8_t y, char *pText)
{ 
  DISPLAY_POS(x,y);
  DISPLAY_WRITESTRING(pText);
}


// ********** SERVOMOTOREN **********

void WRITE_MOTOR(uint8_t port, int value)
{
  if (port==ML)
  {
    if (value>100) value = 100;
    if (value<-100) value = -100;
    OCR1A = 3000 + value * 4;
  }
  if (port==MR)
  {
    if (value>100) value = 100;
    if (value<-100) value = -100;
    OCR1B = 3000 - value * 4;
  }
}


// ********** I2C SRF10 **********

void WRITE_I2C_SRF10(uint8_t address, uint8_t gain, uint8_t range)
{
    Wire.beginTransmission(byte(address >> 1));
    Wire.write(byte(0x01)); // gain
    Wire.write(byte(gain)); // gain (0x00 - 0x10, default 0x04)
    Wire.endTransmission();
    
    Wire.beginTransmission(byte(address >> 1));
    Wire.write(byte(0x02)); // range
    Wire.write(byte(gain)); // range (0x00 - 0xFF, default 0x80)
    Wire.endTransmission();
}

uint8_t READ_I2C_SRF10(uint8_t address)
{
  uint8_t value = 0;
  
  Wire.beginTransmission(byte(address >> 1));
  Wire.write(byte(0x00));
  Wire.endTransmission();

  Wire.requestFrom(112, 1);

  while(Wire.available())
  {
    value = Wire.read(); 
  }
     
  if (value!=0xFF)
  {
    Wire.beginTransmission(byte(address >> 1));
    Wire.write(byte(0x03));
    Wire.endTransmission();

    Wire.requestFrom(byte(address >> 1), 1);

    while(Wire.available())
    {
      value = Wire.read();
    }
    Wire.beginTransmission(byte(address >> 1));
    Wire.write(byte(0x00));
    Wire.write(byte(0x51));
    Wire.endTransmission();
  }
  return value;
}


// ********** SPI LINE **********

uint16_t READ_SPI_LINE(uint8_t port, uint8_t sensor)
{
  uint16_t data1;
  uint16_t data2;
  uint16_t value;
  uint8_t spi_cs;
  uint8_t spi_address;

  if (port==SPI1) spi_cs = SPI1CSPIN;
  if (port==SPI2) spi_cs = SPI2CSPIN;

  if (sensor==1) spi_address = 0x80;
  if (sensor==2) spi_address = 0x90;
  if (sensor==3) spi_address = 0xA0;
  if (sensor==4) spi_address = 0xB0;
  if (sensor==5) spi_address = 0xC0;
  if (sensor==6) spi_address = 0xD0;
  if (sensor==7) spi_address = 0xE0;
  if (sensor==8) spi_address = 0xF0;
  
  digitalWrite(spi_cs, LOW);
  SPI.transfer(0x01);
  data1=SPI.transfer(spi_address);
  data2=SPI.transfer(0x00);
  digitalWrite(spi_cs, HIGH);
  value =(data1<<8) | data2;
  value = value & 0x03FF; 

  return value;
}

// ********** BNO055 **********

void WRITE_I2C_BNO055_INIT()
{
  do
  {
    delay(10);
    Wire.beginTransmission(0x28);
    Wire.write(0x00);
    Wire.endTransmission(false);
    Wire.requestFrom(0x28, 1, true);
  } while(Wire.read() != 0xA0);

  Wire.beginTransmission(0x28);
  Wire.write(0x3D);
  Wire.write(0x0C);
  Wire.endTransmission();

}

uint16_t READ_I2C_BNO055_YAW()
{
  uint16_t value = 0;
  Wire.beginTransmission(0x28);
  Wire.write(0x1A);  
  Wire.endTransmission(false);
  Wire.requestFrom(0x28, 2, true);
  value = (int16_t)(Wire.read()|Wire.read()<<8 )/16;  
  return value;  
}

uint16_t READ_I2C_BNO055_ROLL()
{
  uint16_t value = 0;
  Wire.beginTransmission(0x28);
  Wire.write(0x1C);  
  Wire.endTransmission(false);
  Wire.requestFrom(0x28, 2, true);
  value = (int16_t)(Wire.read()|Wire.read()<<8 )/16;  
  return value;  
}

uint16_t READ_I2C_BNO055_PITCH()
{
  uint16_t value = 0;
  Wire.beginTransmission(0x28);
  Wire.write(0x1E);  
  Wire.endTransmission(false);
  Wire.requestFrom(0x28, 2, true);
  value = (int16_t)(Wire.read()|Wire.read()<<8 )/16;  
  return value;  
}

/*
void I2C_BNO055_INIT()
{
  uint8_t data[7];
  uint8_t chip_id;
    
  uint8_t accel_offset_x_lsb_value = 8; 
  uint8_t accel_offset_x_msb_value = 0;
  uint8_t accel_offset_y_lsb_value = 34;
  uint8_t accel_offset_y_msb_value = 0;
  uint8_t accel_offset_z_lsb_value = 7;
  uint8_t accel_offset_z_msb_value = 0;

  uint8_t mag_offset_x_lsb_value = 45;
  uint8_t mag_offset_x_msb_value = 255;
  uint8_t mag_offset_y_lsb_value = 116;
  uint8_t mag_offset_y_msb_value = 0;
  uint8_t mag_offset_z_lsb_value = 90;
  uint8_t mag_offset_z_msb_value = 1;

  uint8_t gyro_offset_x_lsb_value = 1;
  uint8_t gyro_offset_x_msb_value = 0;
  uint8_t gyro_offset_y_lsb_value = 1;
  uint8_t gyro_offset_y_msb_value = 0;
  uint8_t gyro_offset_z_lsb_value = 0;
  uint8_t gyro_offset_z_msb_value = 0;

  uint8_t accel_radius_lsb_value = 0; 
  uint8_t accel_radius_msb_value = 3;
  uint8_t mag_radius_lsb_value = 66;
  uint8_t mag_radius_msb_value = 2;

        Wire.beginTransmission(byte(address >> 1));
    Wire.write(byte(0x01)); // gain
    Wire.write(byte(gain)); // gain (0x00 - 0x10, default 0x04)
    Wire.endTransmission();
    
byte index = 0;
while(Wire.available() > 0 && index < 6)
{
  thisArray[index] = Wire.receive();
  index++;
}


  data[0] = BNO055_CHIP_ID;
  i2c.write(BNO055_ADDR, data, 1, true);
  i2c.read(BNO055_ADDR, data, 7, false);
  chip_id = data[0];
  
  while (chip_id != BNO055_CHIP_ID_VALUE)
  {
    data[0] = BNO055_CHIP_ID;
    i2c.write(BNO055_ADDR, data, 1, true);
    i2c.read(BNO055_ADDR, data, 7, false);
    chip_id = data[0];
  }
  
  data[0] = BNO055_OPR_MODE;
  data[1] = CONFIGMODE;
  i2c.write(BNO055_ADDR, data, 2);
  wait_ms(50);
  
  data[0] = BNO055_AXIS_MAP_CONFIG; 
  data[1] = 0x24; 
  data[2] = 0x00;
  i2c.write(BNO055_ADDR, data, 2);
    
  data[0] = ACCEL_OFFSET_X_LSB; data[1] = accel_offset_x_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = ACCEL_OFFSET_X_MSB; data[1] = accel_offset_x_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = ACCEL_OFFSET_Y_LSB; data[1] = accel_offset_y_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = ACCEL_OFFSET_Y_LSB; data[1] = accel_offset_y_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = ACCEL_OFFSET_Z_LSB; data[1] = accel_offset_z_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = ACCEL_OFFSET_Z_LSB; data[1] = accel_offset_z_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
   
  data[0] = MAG_OFFSET_X_LSB; data[1] = mag_offset_x_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_OFFSET_X_MSB; data[1] = mag_offset_x_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_OFFSET_Y_LSB; data[1] = mag_offset_y_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_OFFSET_Y_LSB; data[1] = mag_offset_y_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_OFFSET_Z_LSB; data[1] = mag_offset_z_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_OFFSET_Z_LSB; data[1] = mag_offset_z_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
   
  data[0] = GYRO_OFFSET_X_LSB; data[1] = gyro_offset_x_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = GYRO_OFFSET_X_MSB; data[1] = gyro_offset_x_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = GYRO_OFFSET_Y_LSB; data[1] = gyro_offset_y_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = GYRO_OFFSET_Y_LSB; data[1] = gyro_offset_y_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = GYRO_OFFSET_Z_LSB; data[1] = gyro_offset_z_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = GYRO_OFFSET_Z_LSB; data[1] = gyro_offset_z_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
   
  data[0] = ACCEL_RADIUS_LSB; data[1] = accel_radius_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = ACCEL_RADIUS_MSB; data[1] = accel_radius_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_RADIUS_LSB; data[1] = mag_radius_lsb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
  data[0] = MAG_RADIUS_MSB; data[1] = mag_radius_msb_value; i2c.write(BNO055_ADDR, data, 2); wait_ms(20);
   
  data[0] = BNO055_OPR_MODE;
  data[1] = MODE_NDOF;
  i2c.write(BNO055_ADDR, data, 2);
  wait_ms(10);
}

int I2C_BNO055_READ_YAW()
{ 
  int16_t wert;
  char data[3];
  
  data[0] = BNO055_EULER_H_LSB;
  i2c.write(BNO055_ADDR, data, 1, true);
  i2c.read(BNO055_ADDR, data, 2, false);
  
  wert = data[1] << 8 | data[0];
  wert = (double)wert/16;
  return wert;
}

int I2C_BNO055_READ_PITCH()
{ 
  int16_t wert;
  char data[3];
  
  data[0] = BNO055_EULER_P_LSB;
  i2c.write(BNO055_ADDR, data, 1, true);
  i2c.read(BNO055_ADDR, data, 2, false);
  
  wert = data[1] << 8 | data[0];
  wert = (double)wert/16;
  return wert;
}

int I2C_BNO055_READ_ROLL()
{ 
  int16_t wert;
  char data[3];
  
  data[0] = BNO055_EULER_R_LSB;
  i2c.write(BNO055_ADDR, data, 1, true);
  i2c.read(BNO055_ADDR, data, 2, false);
  
  wert = data[1] << 8 | data[0];
  wert = (double)wert/16;
  return wert;
}

*/

// ********** SLEEP **********

void SLEEP(uint16_t ms)
{
  delay(ms);
}


// ********** INIT **********

void KeplerOpenBOT_INIT()
{
  // ********** SPI **********
  pinMode(SPI1CSPIN, OUTPUT);
  digitalWrite(SPI1CSPIN, HIGH);

  pinMode(SPI2CSPIN, OUTPUT);
  digitalWrite(SPI1CSPIN, HIGH);

  pinMode(SPICAMCSPIN, OUTPUT);
  digitalWrite(SPICAMCSPIN, HIGH);

  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  // ********** I2C **********
  Wire.begin();

  // ********** LED **********
  pinMode(LEDPIN, OUTPUT);
  
  // ********** DISPLAY **********
  pinMode(DISPLAYCEPIN, OUTPUT);
  pinMode(DISPLAYDCPIN, OUTPUT);
  digitalWrite(DISPLAYCEPIN, HIGH);

  DISPLAY_WRITECMD(0x21); // LCD extended commands
  DISPLAY_WRITECMD(0xB0); // set LCD Vop (contrast) 0xB1(good @ 3.3V) or 0xBF if your display is too dark
  DISPLAY_WRITECMD(0x04); // set temp coefficent
  DISPLAY_WRITECMD(0x14); // LCD bias mode 1:40
  DISPLAY_WRITECMD(0x20); // LCD basic commands
  DISPLAY_WRITECMD(0x0C); // LCD normal video
  DISPLAY_CLEAR();

  for (int i=0; i<=13; i++)
  {
    TEXTLINE1[i] = 0x20;
    TEXTLINE2[i] = 0x20;
    TEXTLINE3[i] = 0x20;
    TEXTLINE4[i] = 0x20;
    TEXTLINE5[i] = 0x20;
    TEXTLINE6[i] = 0x20;
  }

  // ********** COUNTER **********
  
  COUNTER = 0;
  noInterrupts();   
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 6250; 
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();    
 

  // ********** PWM SERVOS **********
  DDRB |= _BV(DDB1) | _BV(DDB2);  
  TCCR1A = _BV(COM1A1) | _BV(COM1B1) | _BV(WGM11); 
  TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS11); 
  ICR1 = 40000; 
  OCR1A = 3000;
  OCR1B = 3000;
  TCNT1 = 0;     
}

ISR(TIMER1_COMPA_vect)
{
  COUNTER++;
}
 
