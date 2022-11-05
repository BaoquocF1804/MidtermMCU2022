/*
 * fsmMidterm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: DELL
 */
#include <fsmMidterm.h>
#include <global.h>

enum MODE {MODE0, MODE1, MODE2};
enum MODE mode = MODE0;

//timeout for button is 10s, while time invoking fsm is 10ms

uint16_t counterTimeout	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
void Mode0Manual(){
	if(is_button_pressed(RESET_BUTTON)){
		counterTimeout	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		number = 0;
	}
	else if(is_button_pressed(INC_BUTTON)){
		counterTimeout	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		number = number + 1 > 9 ? 0 : number + 1;
	}
	else if(is_button_pressed(DEC_BUTTON)){
		counterTimeout	= TIMEOUT_FOR_BUTTON / TIME_INVOKE_FSM;
		number = number - 1 < 0 ? 9 : number - 1;
	}
}
void fsm_simple_buttons_run(){
	switch(mode){
	case MODE0:
		//in the case, number increases or decrements when a button is pressed
		Mode0Manual();
		if(is_button_pressed_long_press(INC_BUTTON) || is_button_pressed_long_press(DEC_BUTTON)){
			mode = MODE1;
		}
		if(counterTimeout == 0){
			savePoint = number;
			mode = MODE2;
		}
		counterTimeout--;
		break;
	case MODE1:
		//in case, number increases by 1 every sec
		if(is_button_pressed_long_press(INC_BUTTON)) {
			flagIncreaseNumberMode1 = 1;
		}
		else if(is_button_pressed_long_press(DEC_BUTTON)){
			flagDecreaseNumberMode1 = 1;
		}
		else {
			flagIncreaseNumberMode1 = 0;
			flagDecreaseNumberMode1 = 0;
			mode = MODE0;
		}
		break;
	case MODE2:
		//in the case, number decrements when a button not press in 10s
		flagDecreaseNumberMode2 = 1;
		if(is_button_pressed(INC_BUTTON) || is_button_pressed(DEC_BUTTON)){
			flagDecreaseNumberMode2 = 0;
			number = savePoint;
			mode = MODE0;
		}
		break;
	default:
		break;
	}
}
