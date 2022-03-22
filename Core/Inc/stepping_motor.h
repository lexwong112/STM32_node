/***
@Author: Vincent Chan
@About: Motor Control libraries
***/
#include "main.h"  

/*** Enabled peripherals ***/
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;

/*** User defined variables ***/
/*enum STEPPING_MOTOR_DIRECTION{STEPPING_CLOCKWISE,STEPPING_COUNTERCLOCKWISE,STEPPING_BREAK};

/*** Function Prototypes ***/
/*void stepping_motor_peripherals_init();*/

/*** Function Definition ***/
// 1. Enable motor peripherals based on MOTOR_INDEX
/*void stepping_motor_peripherals_init()
{
		HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1); //Enable PWM Channel 1 in Timer1
}*/

/*void stepping_motor_controller(STEPPING_MOTOR_DIRECTION turn)
{
	if(turn == STEPPING_CLOCKWISE)
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENA_GPIO_Port, ENA_Pin, GPIO_PIN_SET);
	}
	else if (turn == STEPPING_COUNTERCLOCKWISE)
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(ENA_GPIO_Port, ENA_Pin, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(DIR_GPIO_Port, DIR_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(ENA_GPIO_Port, ENA_Pin, GPIO_PIN_RESET);
	}
}
*/