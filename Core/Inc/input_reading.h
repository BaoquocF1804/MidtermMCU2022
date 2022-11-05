
#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"

#define N0_OF_BUTTONS 			3
#define BUTTON_PORT				GPIOA


#define DURATION_FOR_AUTO_INCREASING	   300


void button_reading(void);
unsigned char is_button_pressed(unsigned char index);
unsigned char is_button_pressed_long_press(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
