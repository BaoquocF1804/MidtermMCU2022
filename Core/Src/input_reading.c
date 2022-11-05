/*
 * input_reading.c
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */

#include <input_reading.h>

#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET

uint16_t buttonPin[3] = {RESET_Pin, INC_Pin, DEC_Pin};

static GPIO_PinState buttonBuffer[N0_OF_BUTTONS] = {BUTTON_IS_RELEASED, BUTTON_IS_RELEASED, BUTTON_IS_RELEASED};

static GPIO_PinState debounce1[N0_OF_BUTTONS];
static GPIO_PinState debounce2[N0_OF_BUTTONS];
static uint8_t flagForButtonPress3s[N0_OF_BUTTONS];
static uint16_t counterForButtonPress3s[N0_OF_BUTTONS];


void button_reading(void){
	for(uint8_t i = 0; i < N0_OF_BUTTONS; i ++){
		debounce2[i] = debounce1[i];
		debounce1[i] = HAL_GPIO_ReadPin(BUTTON_PORT, buttonPin[i]);

		if(debounce1[i] == debounce2[i]){
			buttonBuffer[i] = debounce1[i];
			if(buttonBuffer[i] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress3s[i] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress3s[i]++;
				} else {
					flagForButtonPress3s[i] = 1;
				}
			} else {
				counterForButtonPress3s[i] = 0;
				flagForButtonPress3s[i] = 0;
			}
		}
	}
}


unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;

	if(buttonBuffer[index] == BUTTON_IS_PRESSED){
		return (counterForButtonPress3s[index] == 1);
	}
	return 0;
}

unsigned char is_button_pressed_long_press(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress3s[index] == 1);
}
