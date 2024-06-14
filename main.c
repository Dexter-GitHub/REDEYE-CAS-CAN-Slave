/*
 * main.c
 *
 *  Created on: 2024. 6. 14.
 *      Author: Dexter
 */
#include "DSP28x_Project.h"
#include "component.h"
#include "gpio.h"
#include "sci.h"
#include "ecan.h"

void main(void)
{
    Uint8 txBuff[MAX_DATA_LEN] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    Uint8 rxBuff[MAX_DATA_LEN] = {0,};
    Uint16 i = 0;

    InitSysCtrl();
    InitGpio();
    InitSciaGpio();    
    InitECanGpio();
    InitECan();

    DINT;
    InitPieCtrl();

    IER = 0x0000;
    IFR = 0x0000;

    InitPieVectTable();

    EnableInterrupts();
    MemCopy(&RamfuncsLoadStart, &RamfuncsLoadEnd, &RamfuncsRunStart);

    SCI_SetFIFO();
    SCI_SetConfig();
    GPIO_SetConfig();
    ECAN_SetConfig();

    EINT;
    ERTM;

    ECAN_SetSelfTestMode(ECAN_SELF_TEST_MODE_ENABLE);

    GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_0_VAL, GPIO_PIN_RESET);
    GPIO_WritePin(GPIOA, GPIO_PIN_1, GPIO_PIN_1_VAL, GPIO_PIN_RESET);
    GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_2_VAL, GPIO_PIN_RESET);
    GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_3_VAL, GPIO_PIN_RESET);
    GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_4_VAL, GPIO_PIN_RESET);
    GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_5_VAL, GPIO_PIN_RESET);
    SCIA_Print("Hello world\r\n");    
    
    ECAN_Write(txBuff, 1000);
    FOREVER {
        if (true == ECAN_GetIsr()) {
            SCIA_Print("ECAN Inturrupt !!\r\n");
            ECAN_Read(1, rxBuff);
            for (i = 0; i < MAX_DATA_LEN; i++) {
                SCIA_Print("%d. 0x%x\r\n", i, rxBuff[i]);
            }
        }
        DELAY_US(1000000);
    }
}
