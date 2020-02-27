#include <avr/io.h> 
#include <util/delay.h> 
#include <stdlib.h> 
#include "lcd.c"

char get_key (void);
char READ_SWITCHES(void);
void Circ_Init(void);

int main(void)
{
	Circ_Init(); // Initialize the circuit
	LCD_Init(); // initialize LCD controller
	LCD_Clear();
	while(1)
	{
		char key=get_key();
		LCD_Char(key);
		_delay_ms(700);
	 
	}
	
}		
		  
void Circ_Init(void)
{
	
	// Use PB pins for LCD interface
	// Use PD pins for rows
	// Use PC pins for coloumns 
 
	DDRB = 0xFF; // 1111.1111; set PB0-PB7 as outputs	 
	DDRD=0b00000000; // Set PD4-PD7 as i/p
	DDRC=0xFF;// Set PC0-PC5 as o/p
	PORTD = 0xFF;    //enable all internal pull-ups  
	return;

}

char READ_SWITCHES()
{
	PORTC = 0b00000000;// Turn all rows to LOW
	PORTD = 0b11111000;// Enable Pull-ups
	
	//Check which coloumn has LOW i/p	
	if (!(PIND & (1<<PD3)))
	{
		// Change corresponding rows and check the i/p
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD3)))
		return '1';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD3)))
		return '4';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD3)))
		return '7';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD3)))
		return '.';
	}
	else if (!(PIND & (1<<PD4)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '2';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '5';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '8';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD4)))
		return '0';
	}
	
	else if (!(PIND & (1<<PD5)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '3';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '6';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '9';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD5)))
		return '=';
	}
	
	else if (!(PIND & (1<<PD6)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '+';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '-';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '*';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD6)))
		return '/';
	}


		else if (!(PIND & (1<<PD7)))
	{
		PORTC=0b00001110;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return 'C';
		PORTC=0b00001101;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return '^';
		PORTC=0b00001011;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return '!';
		PORTC=0b00000111;
		PORTC=PORTC;
		if (!(PIND & (1<<PD7)))
		return '%';
	}
	
	
	return 'n';           	// Means no key has been pressed
}

	 

char get_key(void)
{
	char key = 'n';
	while(key=='n')
	{
		key=READ_SWITCHES();
	}
	return key;
}
