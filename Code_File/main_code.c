/* write an ECP to display 'A' on 16x2 alphanumeric LCD using LPC2129 */

#include<LPC21XX.H>
#include "delay.c"

#define LCD_D 0xff
#define RS 1<<8
#define E 1<<9

void LCD_INIT(void);
void LCD_CMD(unsigned char);
void LCD_DATA(unsigned char);

int main(){
	
	char i=65;
	LCD_INIT();
	LCD_CMD(0x80);
	LCD_DATA('A');
			
/*	while(1){
		LCD_DATA('A');
	}
*/	

	
/*	while(1){
	
		LCD_CMD(0x80);
		LCD_DATA('A');
	}
*/
	
/*
	while(i<=90){
		
		LCD_CMD(0x80);
		LCD_DATA(i);
		delay_s(1);
		i++;
	}
*/
	
/*	while(1){
	
		LCD_CMD(0x80);
		LCD_DATA('A');
		LCD_DATA('B');
		LCD_DATA('C');
		LCD_DATA('D');
		LCD_DATA('E');
	}
*/
	
}

void LCD_INIT(void){
	
	IODIR0=LCD_D|RS|E;
	LCD_CMD(0x01);
	LCD_CMD(0x02);
	LCD_CMD(0x0C);
	LCD_CMD(0x38);
}

void LCD_CMD(unsigned char cmd){
	
	IOCLR0=LCD_D;
	IOSET0=cmd;
	IOCLR0=RS;
	IOSET0=E;
	delay_ms(2);
	IOCLR0=E;
}

void LCD_DATA(unsigned char d){
	
	IOCLR0=LCD_D;
	IOSET0=d;
	IOSET0=RS;
	IOSET0=E;
	delay_ms(2);
	IOCLR0=E;
}
