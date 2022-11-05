#include "software_timer.h"

static uint16_t		TIME_CYCLE			= 10;

static uint8_t		timer_0				= 0;
static uint8_t		counter_timer_0 	= 0;

static uint8_t		timer_1				= 0;
static uint8_t		counter_timer_1 	= 0;


void InitSoftwareTimer(void);

void SetTimer0(uint16_t duration){
	counter_timer_0 = duration / TIME_CYCLE;
	timer_0 = 0;
}
void SetTimer1(uint16_t duration){
	counter_timer_1 = duration / TIME_CYCLE;
	timer_1 = 0;
}

void RunSoftwareTimer(void){
	if(counter_timer_0 > 0){
		counter_timer_0--;
		if(counter_timer_0 == 0){
			timer_0 = 1;
		}
	}
	if(counter_timer_1 > 0){
		counter_timer_1--;
		if(counter_timer_1 == 0){
			timer_1 = 1;
		}
	}
}

uint8_t Timer0(void){
	return timer_0;
}
uint8_t Timer1(void){
	return timer_1;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2) {
		RunSoftwareTimer();
		button_reading();
	}
}
