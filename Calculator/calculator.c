/***********************************************************************************************
 * [FILE NAME]:		calculator.c
 * [AUTHOR]:		Omar Yousry
 * [DATE CREATED]:	29 Dec 2019
 * [DESCRIPTION]:	This c file contains the code of a basic calculator which performs only
 * 					four operations: +,-,*,%
 ***********************************************************************************************/

#include "lcd.h"
#include "keypad.h"

void calculate (sint32 firstNum, sint32 secondNum, uint8 operation);
void getNum (sint32* firstNum, sint32* secondNum, uint8* operation);


int main ()
{
	LCD_init();
	LCD_displayStringRowColumn(0,0,"Basic Calculator");
	LCD_displayStringRowColumn(1,5,"Welcome");
	sint32 firstNum,secondNum;
	uint8 operation,key;
	while(1)
	{
		key = KEYPAD_getPressedKey();
		if (key == 13)
		{
			LCD_clearScreen();
		}
		if (key>=0 && key<=9)
		{
			getNum(&firstNum,&secondNum,&operation);
		}

		if (key == '=')
		{
			calculate(firstNum,secondNum,operation);
		}

	}
}

void calculate (sint32 firstNum, sint32 secondNum, uint8 operation)
{
	sint32 result=0;
	switch (operation)
	{
		case '+': result= firstNum+secondNum;
				  break;
		case '-': result= firstNum-secondNum;
				  break;
		case '*': result= firstNum*secondNum;
				  break;
		case '%': LCD_displayStringRowColumn(1,0,"/=");
				  LCD_intgerToString(firstNum/secondNum);
				  LCD_displayStringRowColumn(1,5,"%=");
				  LCD_intgerToString(firstNum%secondNum);
				  return;
		default:  LCD_displayStringRowColumn(1,0,"Error!");
				  _delay_ms(300); /* Press time */
				  return;
	}
	LCD_goToRowColumn(1,0);
	LCD_displayCharacter('=');
	LCD_intgerToString(result);
}


void getNum (sint32* firstNum, sint32* secondNum, uint8* operation)
{
	/*make firstNum, secondNum and also operation equals to zero
	 * for a new operation to be performed*/
	*firstNum=0;
	*secondNum=0;
	*operation=0;
	/*if the user entered another number, it will clear the screen to begin a new operation*/
	LCD_clearScreen();

	/*while loop to get the first number
	 * loop until we get operation symbol*/
	while(KEYPAD_getPressedKey()>=0 && KEYPAD_getPressedKey()<=9)
	{
		/*If the user entered a number of more than one digit*/
		*firstNum=((*firstNum)*10)+KEYPAD_getPressedKey();
		/*display the number a digit by digit on LCD*/
		LCD_intgerToString(KEYPAD_getPressedKey());
		_delay_ms(300); /* Press time */
	}
	/*after going out of the loop, we have the operation symbol*/
	*operation=KEYPAD_getPressedKey();
	/*display the operation symbol on LCD*/
	LCD_displayCharacter(*operation);
	_delay_ms(300); /* Press time */

	/*while loop to get the second number
	 * loop until we get = symbol*/
	while((KEYPAD_getPressedKey()>=0 && KEYPAD_getPressedKey()<=9))
	{
		*secondNum=((*secondNum)*10)+KEYPAD_getPressedKey();
		LCD_intgerToString(KEYPAD_getPressedKey());
		_delay_ms(300); /* Press time */
	}
}
