/*
 * global.c
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */
#include <global.h>
uint8_t savePoint;
uint8_t number;

uint8_t flagIncreaseNumberMode1;
uint8_t flagDecreaseNumberMode1;

uint8_t	flagDecreaseNumberMode2;
void InitVar(void){
	savePoint = 0;
	number = 0;
	 flagIncreaseNumberMode1 = 0;
	 flagDecreaseNumberMode1 = 0;

	flagDecreaseNumberMode2 = 0;
}

