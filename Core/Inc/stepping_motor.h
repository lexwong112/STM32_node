/***
@Author: Vincent Chan
@About: Motor Control libraries
***/
#include "main.h"  

/*** Enabled peripherals ***/
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim8;

/*** User defined variables ***/
enum STEPPING_MOTOR_DIRECTION{STEPPING_CLOCKWISE,STEPPING_COUNTERCLOCKWISE,STEPPING_BREAK};
int step = 200;

/*** Function Prototypes ***/
void stepping_motor_peripherals_init();

/*** Function Definition ***/
// 1. Enable motor peripherals based on MOTOR_INDEX
void stepping_motor_peripherals_init()
{
		HAL_TIM_PWM_Start(&htim4,TIM_CHANNEL_1); //Enable PWM Channel 1 in Timer1
}

void RCservo_init()
{
	HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_1); //Enable PWM Channel 1 in Timer1
	HAL_TIM_PWM_Start(&htim8,TIM_CHANNEL_2); //Enable PWM Channel 1 in Timer1
}

void stepping_motor_controller(STEPPING_MOTOR_DIRECTION turn)
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

void stepping_motor_speed_byPWM(int PWM)
{
	//assume steps = 200
	//PWM = 1kHz
	//motor speed = 5 rev/sec
	
	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,PWM);  
}

void RCServo_speed_byPWM(int PWM, int servo)
{
	//frequency = 50hz
	//0 degree = 645us
	//90 degree = 1520us
	//180 degree = 2150us

	if (servo == 1)
	{
		__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_1,PWM);  
	} 
	else 
	{
		__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,PWM);  
	}
	
}

void RCServo_speed_STOP(int servo)
{
	if (servo == 1)
	{
		__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_1,0);  
	} 
	else 
	{
		__HAL_TIM_SET_COMPARE(&htim8,TIM_CHANNEL_2,0);  
	}
	
}



void stepping_motor_speed_bySpeed(int motor_speed)
{
	//assume steps = 200
	//PWM = 1kHz
	//motor speed = 5 rev/sec = 1khz/200
	int PWM = motor_speed*step;
	__HAL_TIM_SET_COMPARE(&htim4,TIM_CHANNEL_1,PWM);  
}

