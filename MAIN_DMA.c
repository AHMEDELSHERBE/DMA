#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

#include    "STK_interface.h"
#include	"RCC_interface.h"
#include	"DIO_int.h"
#include	"NVIC_int.h"
#include	"DMA_interface.h"

u16 Count;

int	main(void)
{
	/*	Initialization Part		*/
	u32 Arr1[1000];
	u32 Arr2[1000] = {0};
	u32 Arr3[1000];
	u32 Arr4[1000] = {0};
	/*	Initialize the Array    */
	for(u16 i = 0; i<1000;i++)
	{
		Arr1[i] = i;
		Arr3[i] = i;
	}
	/*	System Clk init			*/
	MRCC_voidSysClkInit();
	
	/*	Toggle Led C13	GPIOC	*/
	/*	1- Enable Per Clk "RCC" Port C		*/
	MRCC_voidEnablePerClk(RCC_APB2,4);
	/*	2- Enable Per Clk "RCC" DMA1		*/
	MRCC_voidEnablePerClk(RCC_AHB,0);
	
	/*	Direction for C13 is output Push Pull */
	/*MDIO_voidSetPinDirection(PORTC, PIN13, OUT_2MHZ_PP);*/
	
		
	/*	NVIC Initialization		*/
	NVIC_void_Init();
	
	/*	DMA1 Channel1 NVIC interrupt Enable 	*/
	NVIC_void_EnableInt(11);
	
	/*	DMA1 initilaization	*/
	DMA1_voidChannelInit();
	
	DMA1_voidChannelStart(Arr1,Arr2,1000);
	
	for(Count = 0 ; Count<1000 ; Count++)
	{
		Arr4[Count] = Arr3[Count];
	}
	
	while(1)
	{
		/*	Toggle led */
		/*M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, LOW);
		STK_voidBusyWait(1000000);
		M_GPIO_void_SetPinValue(PORTC_ID, PIN13_ID, HIGH);
		STK_voidBusyWait(1000000);*/
	}
	return 0;
}

void DMA1_Channel1_IRQHandler(void)
{
	
	/*Clear GIF flag*/
	/*Clear TC flag*/
}
 