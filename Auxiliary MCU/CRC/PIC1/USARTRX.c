sbit LCD_RS at RD0_bit;
sbit LCD_EN at RD1_bit;
sbit LCD_D4 at RD2_bit;
sbit LCD_D5 at RD3_bit;
sbit LCD_D6 at RD4_bit;
sbit LCD_D7 at RD5_bit;

sbit LCD_RS_Direction at TRISD0_bit;
sbit LCD_EN_Direction at TRISD1_bit;
sbit LCD_D4_Direction at TRISD2_bit;
sbit LCD_D5_Direction at TRISD3_bit;
sbit LCD_D6_Direction at TRISD4_bit;
sbit LCD_D7_Direction at TRISD5_bit;

char txt1[5]="K";

char output[10]="";

int k=0,l=0;


void interrupt()
{

if(PIR1.RCIF)
{

 PIR1.RCIF=0; 
 PORTC.F0=1;  //LED 1
 /// 7OK            234567890*OK
 UART1_Read_Text(output,"OK", 30);    // reads text until 'OK' is found
 

 
 UART1_Write_Text(output); UART1_Write(79); UART1_Write(75);
 //7OK
 
}
}

void main()
{ 

  TRISC.F0=0;
  PORTC.F0=0;
  Lcd_Init();                        // Initialize LCD

  TRISB = 0;
  PORTB = 0;
 ////////////////////////////// UART AYARLARI /////////////////////////////////////

 UART1_Init(9600);    // UART 9600 Baudrate ile baslatıldı.
 INTCON.GIE = 1;      // GLOBAL INTERRUPT ENABLE
 PIE1.RCIE = 1;       // RECIEVE INTERRUPT ENABLE
 INTCON.PEIE = 1;     // peripheral intterrupt
 PIR1.RCIF=0;         // RX FLAG BIT
 RCSTA.CREN=1;
 ///////////////////////////// UART AYARLARI SONU //////////////////////////////////
  
  
  while (1)
  { 
  
  
  // Endless loop

       }
       }
