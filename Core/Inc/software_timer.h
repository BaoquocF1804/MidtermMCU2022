/*
 * software_timer.h
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_


#include <input_reading.h>
#include "main.h"

void RunSoftwareTimer(void);
void SetTimer0(uint16_t duration);
void SetTimer1(uint16_t duration);

uint8_t Timer0(void); //return timer0
uint8_t Timer1(void); //return timer1


#endif /* INC_SOFTWARE_TIMER_H_ */
