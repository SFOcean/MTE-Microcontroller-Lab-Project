#define F_CPU 1000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "Lcdlbr/lcd.h"

//void ADC_Init()
//{
	//DDRA=0x0;			/* Make ADC port as input */
	//ADCSRA = 0x87;			/* Enable ADC, fr/128  */
	//ADMUX = 0x40;			/* Vref: Avcc, ADC channel: 0 */
	
//}

//int ADC_Read(char channel)
//{
	//int Ain,AinLow;
	
	//ADMUX=ADMUX|(channel & 0x0f);	/* Set input channel to read */

	//ADCSRA |= (1<<ADSC);		/* Start conversion */
	//while((ADCSRA&(1<<ADIF))==0);	/* Monitor end of conversion interrupt */
	
	//_delay_us(10);
	//AinLow = (int)ADCL;		/* Read lower byte*/
	//Ain = (int)ADCH*256;		/* Read higher 2 bits and 
					//Multiply with weight */
	//Ain = Ain + AinLow;				
	//return(Ain);			/* Return digital value*/
//} 


int main(void)
{
	//char String[5];
	//int value;
	DDRA=0;
	//ADC_Init();
	PORTA=00000011;
	int16_t COUNTA =0;
	char SHOWA [16];
	
	
lcd_init(LCD_DISP_ON_CURSOR); /*initialize lcd,display on, cursor on */

        lcd_clrscr();             /* clear screen of lcd */
		lcd_home();               /* bring cursor to 0,0 */
		lcd_puts("PLEASE VOTE");        /* type something random */
		lcd_gotoxy(0,1);          /* go to 2nd row 1st col */


		lcd_puts("");  /* type something random */
       while(1)
	{
		
		/* LCD16x2 cursor position */
		//value=ADC_Read(0);	/* Read ADC channel 0 */
		//itoa(value,String,10);	/* Integer to string conversion */ 
		if ((PINA &(00000001))==0)
		{
			COUNTA++;
			
		}
		lcd_puts(COUNTA);
		lcd_clrscr();
		
}