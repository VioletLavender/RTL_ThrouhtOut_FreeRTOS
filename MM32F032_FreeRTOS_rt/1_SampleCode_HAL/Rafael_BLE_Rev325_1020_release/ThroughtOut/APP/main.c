/******************************************************************************
 * @file    main.c
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
#define __MAIN_C__


/* Includes -----------------------------------------------------------------*/
#include "main.h"


/* Includes -----------------------------------------------------------------*/
#include "systick.h"
#include "uart.h"
#include <stdio.h>
#include "main.h"
#include "rf_phy.h"
#include "porting_spi.h"
#include "porting_misc.h"
#include "porting_LLtimer.h"
#include "systick.h"
#include "uart.h"
#include "spi.h"
#include "mcu_definition.h"
#include "ble_cmd.h"

/* Includes -----------------------------------------------------------------*/
#include "bsp_led.h"
#include "FreeRTOS.h"
#include "task.h"



/* Private typedef ----------------------------------------------------------*/
/* Private define -----------------------------------------------------------*/
/* Private macro ------------------------------------------------------------*/
/* Private variables --------------------------------------------------------*/
/* Private function prototypes ----------------------------------------------*/
/* Private functions --------------------------------------------------------*/


/* Exported variables -------------------------------------------------------*/
/* Exported function prototypes ---------------------------------------------*/

#define TASK1_STACK_SIZE          1280
#define TASK1_PRIORITY            1

//#define _PWR_test
BLE_Addr_Param bleAddrParam;
extern void BleApp_Main(void);
extern BleStackStatus Ble_Kernel_Root(void);
extern void BleApp_Init(void);

// use UART for TRSPX
#if (BLE_DEMO==DEMO_TRSPX_UART_SLAVE)
    #include "host.h"   //put UART char to att_HDL_UDF01S_UDATN01 and notify_send

    int BLEDemo_UartRxData_Handle(uint8_t *data, uint32_t dataLen);
    void UART02_IRQHandler(void);
    void UART_TX_Send(uint32_t len, uint8_t *ptr);        //show data on UART
    extern void trspx_send(uint8_t *data, uint16_t len);  //send out RF data

    #if (BLE_DATA_LENGTH_EXTENSION_SUPPORT == ENABLE_)
        #define TRSPX_DEFAULT_MTU   247
    #else
        #define TRSPX_DEFAULT_MTU   23
    #endif
    uint32_t TRSPX_mtu = TRSPX_DEFAULT_MTU - 3;      //transparent data block length. att_HDL_UDF01S_UDATN01[] is also 20 bytes now!!!

#endif //#if (BLE_DEMO==DEMO_TRSPX_UART_SLAVE)

void RF_Open()
{
    //void SPI_DMA_25xxTest(void) ;
    //GPIO_InitTypeDef GPIO_InitStructure;

    /* Wait RF PHY stable ,delay 25ms */
    SysTick_DelayMs(25);

    /* Initialize Gpio reset pin */
    MCU_GpioResetInit();

    /* Do Gpio Reset */
    MCU_GpioReset();
    SysTick_DelayMs(50);

    /* SPI IO remapping */
    RF_SpiIoMapping();

    /* Initialize RF PHY */
    RF_Init();                   //EnableGpioInterrupt in the end of this function

}


void rf_Stack_task(void *pvParameters)
{
    for (;;)
    {
        if (Ble_Kernel_Root() == BLESTACK_STATUS_FREE)
        {
            BleApp_Main();
        }
    }
}

void AppTaskCreate(void)
{
    xTaskCreate(rf_Stack_task, "Task1", TASK1_STACK_SIZE, NULL, TASK1_PRIORITY, NULL);
    printf("TASK IS READY\r\n");
}

/******************************************************************************
 * @brief
 * @param
 * @retval
 * @attention
******************************************************************************/
int main(void)
{
    delay_init();

    BSP_LED_Init();

    NVIC_SetPriority(EXTI4_15_IRQn, 0);

    UARTx_Configure(DEBUG_UART, 115200, UART_WordLength_8b, UART_StopBits_1,  \
                    UART_Parity_No);

    /* Enable the BLE RF PHY */
    RF_Open();
    SysTick_DelayMs(2000);

    /*get chipID*/
    printf("-------------------\n");
    printf("  BLE Start.....\n");
    printf("-------------------\n");

    printf("Chip_ID=0x%x\n", ChipId_Get());

    /* Set BD ADDR */
    bleAddrParam.addrType = PUBLIC_ADDR;
    bleAddrParam.addr[0] = 0x11;
    bleAddrParam.addr[1] = 0x22;
    bleAddrParam.addr[2] = 0x33;
    bleAddrParam.addr[3] = 0x54;
    bleAddrParam.addr[4] = 0x55;
    bleAddrParam.addr[5] = 0x56;
    setBLE_BleDeviceAddr(&bleAddrParam);

    printf("MM32TEST");

    /*INIT ADV*/
    BleApp_Init();

    /*FreeRTOS Creat task*/
    AppTaskCreate();

    /* start task*/
    vTaskStartScheduler();

    return 0;
}


/******************* (C) COPYRIGHT 2020 ************************END OF FILE***/

