// *************************************
// *** KeplerFischBRAIN V 01.05.2018 ***
// *************************************

#include <SPI.h>

#define D1 0x01
#define D2 0x02
#define D3 0x03
#define D4 0x04
#define D5 0x05
#define D6 0x06
#define D7 0x07
#define D8 0x08
#define A1 0x09
#define A2 0x0A
#define A3 0x0B
#define A4 0x0C

#define B1 0x11
#define B2 0x12
#define B3 0x13
#define B4 0x14

#define L1 0x21
#define L2 0x22
#define L3 0x23

#define M1 0x31
#define M2 0x32
#define M3 0x33
#define M4 0x34

// ********** GLOBALS **********
const int SSPin = 10;

uint16_t COUNTER;

uint8_t TEXTLINE1[17];
uint8_t TEXTLINE2[17];

uint8_t LED1;
uint8_t LED2;
uint8_t LED3;

uint8_t MOTOR1;
uint8_t MOTOR2;
uint8_t MOTOR3;
uint8_t MOTOR4;

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

void SLEEP(uint16_t ms)
{
  delay(ms);
}

void KeplerFischBRAIN_INIT()
{
  // ********** IN PORTS **********
  pinMode(0, INPUT_PULLUP); //D0 FB_D4
  pinMode(1, INPUT_PULLUP); //D1 FB_D5
  pinMode(2, INPUT_PULLUP); //D2 FB_D3
  pinMode(3, INPUT_PULLUP); //D3 FB_D2
  pinMode(4, INPUT_PULLUP); //D4 FB_D6
  pinMode(5, INPUT_PULLUP); //D5 FB_D7
  pinMode(6, INPUT_PULLUP); //D6 FB_D1
  pinMode(7, INPUT_PULLUP); //D7 FB_D8

  pinMode(8, INPUT_PULLUP); //D8 FB_T2
  pinMode(9, INPUT_PULLUP); //D9 FB_T1
  pinMode(18, INPUT_PULLUP); //18 A4 FB_T3
  pinMode(19, INPUT_PULLUP); //19 A5 FB_T4
  
  // ********** SPI **********
  pinMode(SSPin, OUTPUT);
  digitalWrite(SSPin, HIGH);
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

  // ********** DISPLAY **********
  for (int i=0; i<=15; i++)
  {
    TEXTLINE1[i] = 0x20;
    TEXTLINE2[i] = 0x20;
  }

  // ********** LEDS **********
  LED1 = 0;
  LED2 = 0;
  LED3 = 0;
  
  // ********** MOTOREN **********
  MOTOR1 = 0;
  MOTOR2 = 0;
  MOTOR3 = 0;
  MOTOR4 = 0;
  
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
}

ISR(TIMER1_COMPA_vect)
{
  COUNTER++;
}

void KeplerFischBRAIN_WRITEDATA()
{

  // ********** LEDS Byte[0] **********
  digitalWrite(10, LOW); 
  SPI.transfer(0xEE);
  digitalWrite(10, HIGH); 

  // ********** LEDS Byte[1] - Byte[3] **********
  digitalWrite(SSPin, LOW); 
  SPI.transfer(LED1);
  digitalWrite(SSPin, HIGH); 

  digitalWrite(SSPin, LOW); 
  SPI.transfer(LED2);
  digitalWrite(SSPin, HIGH); 

  digitalWrite(SSPin, LOW); 
  SPI.transfer(LED3);
  digitalWrite(SSPin, HIGH); 
  
  // ********** MOTORS Byte[4] - Byte[7]**********
  digitalWrite(SSPin, LOW); 
  SPI.transfer(MOTOR1);
  digitalWrite(SSPin, HIGH); 
  
  digitalWrite(SSPin, LOW); 
  SPI.transfer(MOTOR2);
  digitalWrite(SSPin, HIGH); 
  
  digitalWrite(SSPin, LOW); 
  SPI.transfer(MOTOR3);
  digitalWrite(SSPin, HIGH); 
  
  digitalWrite(SSPin, LOW); 
  SPI.transfer(MOTOR4);
  digitalWrite(SSPin, HIGH); 

  // ********** DISPLAY Byte[8] - Byte[39] **********
  for (int i=0; i<=15; i++)
  {
    digitalWrite(SSPin, LOW); 
    SPI.transfer(TEXTLINE1[i]);
    digitalWrite(SSPin, HIGH); 
  }
  for (int i=0; i<=15; i++)
  {
    digitalWrite(SSPin, LOW); 
    SPI.transfer(TEXTLINE2[i]);
    digitalWrite(SSPin, HIGH); 
  }

  delay(10); 
}

uint16_t READ_IN_CLOSED(uint8_t port)
{
  if (port==D1)
  {
    if (digitalRead(6)==0) return 1;
    else return 0;
  }
  if (port==D2)
  {
    if (digitalRead(3)==0) return 1;
    else return 0;
  }
  if (port==D3)
  {
    if (digitalRead(2)==0) return 1;
    else return 0;
  }
  if (port==D4)
  {
    if (digitalRead(0)==0) return 1;
    else return 0;
  }
  if (port==D5)
  {
    if (digitalRead(1)==0) return 1;
    else return 0;
  }
  if (port==D6)
  {
    if (digitalRead(4)==0) return 1;
    else return 0;
  }
  if (port==D7)
  {
    if (digitalRead(5)==0) return 1;
    else return 0;
  }
  if (port==D8)
  {
    if (digitalRead(7)==0) return 1;
    else return 0;
  }
}

uint8_t READ_IN_PRESSED(uint8_t port)
{
  uint8_t D_PRESSED = 0;
  
  if (port==D1)
  {
    if (digitalRead(6)==0)
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
  
  if (port==D2)
  {
    if (digitalRead(3)==0)
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

  if (port==D3)
  {
    if (digitalRead(2)==0)
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

  if (port==D4)
  {
    if (digitalRead(0)==0)
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

  if (port==D5)
  {
    if (digitalRead(1)==0)
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

  if (port==D6)
  {
    if (digitalRead(4)==0)
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

  if (port==D7)
  {
    if (digitalRead(5)==0)
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

  if (port==D8)
  {
    if (digitalRead(7)==0)
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
  
  
uint16_t READ_BUTTON_CLOSED(uint8_t port)
{
  if (port==B1)
  {
    if (digitalRead(9)==0) return 1;
    else return 0;
  }
  if (port==B2)
  {
    if (digitalRead(8)==0) return 1;
    else return 0;
  }
  if (port==B3)
  {
    if (digitalRead(18)==0) return 1;
    else return 0;
  }
  if (port==B4)
  {
    if (digitalRead(19)==0) return 1;
    else return 0;
  }
}

uint8_t READ_BUTTON_PRESSED(uint8_t port)
{
  uint8_t B_PRESSED = 0;
  
  if (port==B1)
  {
    if (digitalRead(9)==0)
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
    if (digitalRead(8)==0)
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
    if (digitalRead(18)==0)
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
    if (digitalRead(19)==0)
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

void WRITE_LED(uint8_t port, uint8_t value)
{
  if (port==L1)
  {
    if (value==1) LED1 = 1;
    else LED1 = 0;
  }
  if (port==L2)
  {
    if (value==1) LED2 = 1;
    else LED2 = 0;
  }
  if (port==L3)
  {
    if (value==1) LED3 = 1;
    else LED3 = 0;
  }
  KeplerFischBRAIN_WRITEDATA();
}

void LCD_DRAW_INT(uint8_t x, uint8_t y, int value, int len)
{
  char text[16];
  if ((len>=1)&&(len<=6)&&((x>=1)&&(x<=16)))
  {
    if (len==1) sprintf(text,"%1d",value);
    if (len==2) sprintf(text,"%2d",value);
    if (len==3) sprintf(text,"%3d",value);
    if (len==4) sprintf(text,"%4d",value);
    if (len==5) sprintf(text,"%5d",value);
    if (len==6) sprintf(text,"%6d",value);

    for (int i=0; i<=len-1; i++)
    {
      if ((x-1+i)>15) break;
      if (y==1) TEXTLINE1[x-1+i] = text[i];
      if (y==2) TEXTLINE2[x-1+i] = text[i];
    }
  }
  KeplerFischBRAIN_WRITEDATA();
}


void LCD_DRAW_TEXT(uint8_t x, uint8_t y, char *pText)
{
  if ((x>=1)&&(x<=16))
  {
    while (*pText)
    {
      if (y==1) TEXTLINE1[x-1] = *pText;
      if (y==2) TEXTLINE2[x-1] = *pText;
      pText++;
      x++;
      if (x==17) break; 
    }
  }
  KeplerFischBRAIN_WRITEDATA();
}

void WRITE_MOTOR(uint8_t port, int value)
{
  if (port==M1)
  {
    if (value>100) value = 100;
    if (value<-100) value = -100;
    value = value + 100;
    MOTOR1 = value;
  }
  if (port==M2)
  {
    if (value>100) value = 100;
    if (value<-100) value = -100;
    value = value + 100;
    MOTOR2 = value;
  }
  if (port==M3)
  {
    if (value>100) value = 100;
    if (value<-100) value = -100;
    value = value + 100;
    MOTOR3 = value;
  }
  if (port==M4)
  {
    if (value>100) value = 100;
    if (value<-100) value = -100;
    value = value + 100;
    MOTOR4 = value;
  }
  KeplerFischBRAIN_WRITEDATA();
}
