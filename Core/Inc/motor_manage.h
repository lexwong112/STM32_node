/***
@Author: Vincent Chan
@About: Motor Control libraries
***/
#include "main.h"

/*** Enabled peripherals ***/
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim8;

/*** User defined variables ***/
const int max_register_value = 3600;
enum MOTOR_INDEX{MOTOR1,MOTOR2};
enum MOTOR_DIRECTION{CLOCKWISE,COUNTERCLOCKWISE,BREAK};

/*** Function Prototypes ***/
void motor_peripherals_init(MOTOR_INDEX motor);
void motor_controller(MOTOR_INDEX motor,MOTOR_DIRECTION turn,int duty_cycle);
int calculate_MOTOR_timer_register(int percentage,double counter_max);

/*** Function Definition ***/
// 1. Enable motor peripherals based on MOTOR_INDEX
void motor_peripherals_init(MOTOR_INDEX motor)
{
	int x = 0;
	if(motor == MOTOR1)
	{
		HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_1); //Enable PWM Channel 1 in Timer1
		HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
		// MOTOR1 with ENCODER 3
		// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
	}else if(motor == MOTOR2)
	{
		HAL_TIM_PWM_Start(&htim5,TIM_CHANNEL_2);
		HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
		// MOTOR2 with ENCODER 4 [Align with BAT IN in the motor drive]
		// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
	}
	
	x++;
}

// 2. Motor Controller
void motor_controller(MOTOR_INDEX motor,MOTOR_DIRECTION turn,int duty_cycle,int max_counter)
{
	int x = 0;
	if(motor == MOTOR1)
	{
		if(turn == CLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR1_IN1_GPIO_Port, MOTOR1_IN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR1_IN2_GPIO_Port, MOTOR1_IN2_Pin, GPIO_PIN_RESET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else if (turn == COUNTERCLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR1_IN1_GPIO_Port, MOTOR1_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR1_IN2_GPIO_Port, MOTOR1_IN2_Pin, GPIO_PIN_SET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else
		{
			HAL_GPIO_WritePin(MOTOR1_IN1_GPIO_Port, MOTOR1_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR1_IN2_GPIO_Port, MOTOR1_IN2_Pin, GPIO_PIN_RESET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}
		
			__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,duty_cycle);    
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
	}else if(motor == MOTOR2)
	{
		if(turn == CLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR2_IN1_GPIO_Port, MOTOR2_IN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR2_IN2_GPIO_Port, MOTOR2_IN2_Pin, GPIO_PIN_RESET);

			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else if (turn == COUNTERCLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR2_IN1_GPIO_Port, MOTOR2_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR2_IN2_GPIO_Port, MOTOR2_IN2_Pin, GPIO_PIN_SET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else
		{
				HAL_GPIO_WritePin(MOTOR2_IN1_GPIO_Port, MOTOR2_IN1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(MOTOR2_IN2_GPIO_Port, MOTOR2_IN2_Pin, GPIO_PIN_RESET);
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}
			__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_2,duty_cycle);  
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
	}
	
<<<<<<< Updated upstream
=======
	/*else if (motor == MOTOR3)
	{
		if(turn == CLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR3_IN1_GPIO_Port, MOTOR3_IN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR3_IN2_GPIO_Port, MOTOR3_IN2_Pin, GPIO_PIN_RESET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else if (turn == COUNTERCLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR3_IN1_GPIO_Port, MOTOR3_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR3_IN2_GPIO_Port, MOTOR3_IN2_Pin, GPIO_PIN_SET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else
		{
			HAL_GPIO_WritePin(MOTOR3_IN1_GPIO_Port, MOTOR3_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR3_IN2_GPIO_Port, MOTOR3_IN2_Pin, GPIO_PIN_RESET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}
		
			__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_3,duty_cycle);    
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
	}else{
		if(turn == CLOCKWISE)
		{
			HAL_GPIO_WritePin(MOTOR4_IN1_GPIO_Port, MOTOR4_IN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(MOTOR4_IN2_GPIO_Port, MOTOR4_IN2_Pin, GPIO_PIN_RESET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else if (turn == COUNTERCLOCKWISE)
		{.
			HAL_GPIO_WritePin(MOTOR4_IN1_GPIO_Port, MOTOR4_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR4_IN2_GPIO_Port, MOTOR4_IN2_Pin, GPIO_PIN_SET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}else
		{
			HAL_GPIO_WritePin(MOTOR4_IN1_GPIO_Port, MOTOR4_IN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(MOTOR4_IN2_GPIO_Port, MOTOR4_IN2_Pin, GPIO_PIN_RESET);
	
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
		}
		
			__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_4,duty_cycle);    
			// FILL IT IN BY YOURSELF (╯ ͡❛ ‿ ͡❛)╯┻━┻
	}*/
>>>>>>> Stashed changes
	x++;
}	

// 3. Convert duty cycle to counter register value
int calculate_MOTOR_timer_register(int percentage,double counter_max)
{
	return (int)((percentage*counter_max)/100);
}