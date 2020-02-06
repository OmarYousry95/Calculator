/*******************************************************************************************
 * [FILE NAME]:		keypad.h
 * [AUTHOR]:		Omar Yousry
 * [DATE CREATED]:	29 Dec 2019
 * [DESCRIPTION]:	This header file contains the protoypes of functions of keypad driver
 * 					either it is 4x3 or 4x4
 *******************************************************************************************/

#ifndef KEYPAD_H_
#define KEYPAD_H_

/***********HEADER FILES INCLUSION***********/
#include "common_macros.h"
#include "std_types.h"
#include "micro_config.h"


/**********STATIC CONFIGURATIONS*************/
#define N_COL					4
#define N_ROW					4
#define KEYPAD_PORT_IN 			PINA
#define KEYPAD_PORT_OUT			PORTA
#define KEYPAD_PORT_DIRECTION 	DDRA


/**********FUNCTIONS PROTOTYPES**************/
uint8 KEYPAD_getPressedKey (void);

#endif /* KEYPAD_H_ */
