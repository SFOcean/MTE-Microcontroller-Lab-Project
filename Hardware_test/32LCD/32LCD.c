//Hardware_test_1
#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "Lcdlbr/lcd.h"

void T1Delay();
char SHOWA [16];

int main(void)
{
	DDRA=0;
	PORTA=0b00000011;
	//char String[5];
	//int value;

	//ADC_Init();
	int16_t COUNTA =0;
	
lcd_init(LCD_DISP_ON_CURSOR); /*initialize lcd,display on, cursor on */

                 lcd_clrscr();             /* clear screen of lcd */
		lcd_home();               /* bring cursor to 0,0 */
		lcd_puts("hello");        /* type something random */
		lcd_gotoxy(0,1);          /* go to 2nd row 1st col */


		lcd_puts("");  /* type something random */
       while(1)
	{
	
		/* LCD16x2 cursor position */
		//value=ADC_Read(0);	/* Read ADC channel 0 */
		//itoa(value,String,10);	/* Integer to string conversion */ 
		if (!(PINA &(00000001))==0)
		{
			COUNTA++;
			T1Delay();
			T1Delay();
			itoa(COUNTA,SHOWA,10);
		}
		lcd_puts(SHOWA);
		T1Delay();
		 lcd_clrscr();						
				
	}
}

void T1Delay(){
	TCNT1 = 0;     // timer starts from 00
	OCR1A = 750 - 1; // Output Compare Register A
	TCCR1A = 0x00; TCCR1B = 0x0C; //Run Timer1, Clear
	// Timer on Compare Match, Prescaler mode 1:256
	while ((TIFR & (1<<OCF1A))==0);//wait for OCF1A
	TCCR1B = 0x00;            // Stop Timer
	TIFR =  (1<<OCF1A);      //clear OCF2 flag
}