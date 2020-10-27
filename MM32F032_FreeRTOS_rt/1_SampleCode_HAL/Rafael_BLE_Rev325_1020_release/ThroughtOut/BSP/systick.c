/******************************************************************************
 * @file    systick.c
 * @author  King
 * @version V1.00
 * @date    20-May-2020
 * @brief   ......
 ******************************************************************************
 * @attention
 *
 * THE EXISTING FIRMWARE IS ONLY FOR REFERENCE, WHICH IS DESIGNED TO PROVIDE
 * CUSTOMERS WITH CODING INFORMATION ABOUT THEIR PRODUCTS SO THEY CAN SAVE
 * TIME. THEREFORE, MINDMOTION SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES ABOUT ANY CLAIMS ARISING OUT OF THE CONTENT OF SUCH
 * HARDWARE AND/OR THE USE OF THE CODING INFORMATION CONTAINED HEREIN IN
 * CONNECTION WITH PRODUCTS MADE BY CUSTOMERS.
 * <H2><CENTER>&COPY; COPYRIGHT 2020 MINDMOTION </CENTER></H2>
******************************************************************************/


/* Define to prevent recursive inclusion ------------------------------------*/
#define __SYSTICK_C__


/* Includes -----------------------------------------------------------------*/
#include "systick.h"


/* Private typedef ----------------------------------------------------------*/
/* Private define -----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/


/* Private variables --------------------------------------------------------*/
volatile uint32_t SysTick_DelayTicks = 0;


/* Private function prototypes ----------------------------------------------*/
/* Private functions --------------------------------------------------------*/


/* Exported variables -------------------------------------------------------*/
/* Exported function prototypes ---------------------------------------------*/


/******************************************************************************
 * @brief
 * @param
 * @retval
 * @attention
******************************************************************************/
void SysTick_Init(uint32_t ticks)
{
    if (SysTick_Config(RCC_GetSysClockFreq() / ticks))
    {
        /* Capture error */
        while (1);
    }

    //NVIC_SetPriority(SysTick_IRQn, 0);
    NVIC_SetPriority(SysTick_IRQn, 1);
}


/******************************************************************************
 * @brief
 * @param
 * @retval
 * @attention
******************************************************************************/
//void SysTick_Handler(void)
//{
//    if (SysTick_DelayTicks)
//    {
//        SysTick_DelayTicks--;
//    }
//}

static u8 fac_us=0;//us延时倍乘数

static u16 fac_ms=0;//ms延时倍乘数

void delay_init(void)

{

SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);//选择外部时钟HCLK/8

fac_us=48000000/8000000; //72000000/8000000 = 9

fac_ms=(u16)fac_us*1000; // 值为9000

}
/******************************************************************************
 * @brief
 * @param
 * @retval
 * @attention
******************************************************************************/
void SysTick_DelayMs(uint32_t ms)
{
//    SysTick_DelayTicks  =  ms;
//    while (SysTick_DelayTicks);
u32 temp;

SysTick->LOAD=(u32)ms*fac_ms;//时间加载(SysTick->LOAD为24bit)

SysTick->VAL =0x00; //清空计数器

SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ; //开始倒数

do

{

temp=SysTick->CTRL;

}

while(temp&0x01&&!(temp&(1<<16)));//等待时间到达

SysTick->CTRL&=~SysTick_CTRL_ENABLE_Msk; //关闭计数器

SysTick->VAL =0X00; //清空计数器
}


/******************* (C) COPYRIGHT 2020 ************************END OF FILE***/

