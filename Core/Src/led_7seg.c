#include "led_7_seg.h"


void DisplayNum(uint8_t num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG1_Pin | SEG2_Pin | SEG3_Pin | SEG4_Pin | SEG5_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG6_Pin, SET);
		break;
	case 1:
		HAL_GPIO_WritePin(PORT_LED, SEG1_Pin | SEG2_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG3_Pin | SEG4_Pin |SEG5_Pin | SEG6_Pin, SET);
		break;
	case 2:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG1_Pin | SEG3_Pin |SEG4_Pin | SEG6_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG5_Pin | SEG2_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG1_Pin | SEG2_Pin |SEG3_Pin | SEG6_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG5_Pin | SEG4_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(PORT_LED, SEG1_Pin | SEG2_Pin | SEG5_Pin |SEG6_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG4_Pin | SEG3_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG5_Pin | SEG2_Pin |SEG3_Pin | SEG6_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG1_Pin | SEG4_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG5_Pin | SEG2_Pin |SEG3_Pin | SEG4_Pin | SEG6_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG1_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG1_Pin | SEG2_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, SET);
		break;
	case 8:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG1_Pin | SEG2_Pin |SEG3_Pin | SEG4_Pin | SEG5_Pin | SEG6_Pin, RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(PORT_LED, SEG0_Pin | SEG1_Pin | SEG2_Pin |SEG3_Pin | SEG5_Pin | SEG6_Pin, RESET);
		HAL_GPIO_WritePin(PORT_LED, SEG4_Pin, SET);
		break;
	}
}
