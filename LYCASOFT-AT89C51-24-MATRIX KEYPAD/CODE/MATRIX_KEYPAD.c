#include<reg51.h>
#include "8051_delay.h"
#include "LCD_4_BIT_HEADER_FILE.h"

sbit a = P3^4;		 //defines row A
sbit b = P3^5;		 //defines row B
sbit c = P3^6;		 //defines row C
sbit d = P3^7;		 //defines row D

char READ_SWITCHES()
{
	P3 =0xfe;
	{
		if (a == 0)
		{
			return '3';
		}
		if (b == 0)
		{
			return '6';
		}
		if (c == 0)
		{
			return '9';
		}
		if (d == 0)
		{
			return '#';
		}
	}

	P3 =0xfd;
	{
		if (a == 0)
		{
			return '2';
		}
		if (b == 0)
		{
			return '5';
		}
		if (c == 0)
		{
			return '8';
		}
		if (d == 0)
		{
			return '0';
		}
	}

	P3 =0xfb;
	{
		if (a == 0)
		{
			return '1';
		}
		if (b == 0)
		{
			return '4';
		}
		if (c == 0)
		{
			return '7';
		}
		if (d == 0)
		{
			return '*';
		}
	}
	return 'n';									// Means no key has been pressed
}

char get_key(void)						//get key from user
{
	char key = 'n';							//assume no key pressed
 
	while(key=='n')							//wait untill a key is pressed
		key = READ_SWITCHES();		//scan the keys again and again
 
	return key;									//when key pressed then return its value
}

void main()
{
	int i;
//  char key;										// key char for keeping record of pressed key
	
	Lcd_Intialization();

	Lcd_Command(0x80);
	Lcd_String("LYCA SOFT");

	Lcd_Command(0xC0);
	Lcd_String("KEPDAD:");
	
	while(1)
	{
			Lcd_Command(0XC7);

			i = get_key();					// Get pressed key
			Lcd_Data(i);
	}
}