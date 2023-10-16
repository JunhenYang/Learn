#include "msDelay.h"
#include "stm32f1xx_hal.h"
#include "tim.h"

void My_Delay_ms(uint16_t time){
	uint16_t differ = 11451 - time;
    //设置定时器2的技术初始值
  __HAL_TIM_SetCounter(&htim2, differ);
  //开启定时器
  HAL_TIM_Base_Start(&htim2);

  while(differ < 11451){
        differ = __HAL_TIM_GetCounter(&htim2);
    };
 //关闭定时器
  HAL_TIM_Base_Stop(&htim2);
}
