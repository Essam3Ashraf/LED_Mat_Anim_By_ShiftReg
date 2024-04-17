
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"

// Function Prototype
void LEDMAT_voidDisplay_BY_ShiftREG(u8 * Copy_pu8Data);

//Active One COL Only
const u8 Set_COL_Array[] = {0b11111110, 0b11111101, 0b11111011, 0b11110111,
							0b11101111, 0b11011111, 0b10111111, 0b01111111};
//main Function
void main(void)
{
	u8 Local_u8PinInit;

	// LED Matrix - The first letter of my name
	u8 FirstLetterName[] ={0x7f,0x49,0x49,0x49,0x49,0x49,0x00,0x00};
	// LED Matrix - Za3bola Animations
	u8 ANIM0_P1[] ={0xa0,0x52,0x3d,0x5a,0x60,0x00,0x00,0x00};
	u8 ANIM0_P2[] ={0xa0,0x52,0x3d,0x5a,0x90,0x00,0x00,0x00};
	u8 ANIM1_P1[] ={0xa0,0x52,0x3d,0x5a,0x80,0x20,0x00,0x00};
	u8 ANIM1_P2[] ={0xa0,0x52,0x3d,0x5a,0x80,0x00,0x10,0x00};
	u8 ANIM1_P3[] ={0xa0,0x52,0x3d,0x5a,0x80,0x00,0x00,0x08};
	u8 ANIM1_P4[] ={0xa0,0x52,0x3d,0x5a,0x80,0x00,0x04,0x00};
	u8 ANIM1_P5[] ={0xa0,0x52,0x3d,0x5a,0x80,0x02,0x00,0x00};
	u8 ANIM1_P6[] ={0xa0,0x50,0x3a,0x5d,0x83,0x00,0x00,0x00};

	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB_BUS, RCC_AHB_GPIOAEN);

	for(Local_u8PinInit=0; Local_u8PinInit<3; Local_u8PinInit++)
	{
     MGPIO_voidSetPinMode(PORTA, Local_u8PinInit, OUTPUT);
     MGPIO_voidSetPinOutputMode(PORTA, Local_u8PinInit, PUSH_PULL);
     MGPIO_voidSetPinOutputSpeed(PORTA, Local_u8PinInit, LOW_SPEED);
	}
	MSTK_voidInit();

 while(1)
 {
	// The first letter of my name
    for(u8 LOCAL_u8Times=0; LOCAL_u8Times<15; LOCAL_u8Times++)
    {
      for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
	  {
			 LEDMAT_voidDisplay_BY_ShiftREG(FirstLetterName);
      }
    }

	// Za3bola-Animation Part1
	for(u8 LOCAL_u8Times=0; LOCAL_u8Times<10; LOCAL_u8Times++)
	{

	  for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
	  {
		 LEDMAT_voidDisplay_BY_ShiftREG(ANIM0_P1);
	   }

	   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
	   {
		  LEDMAT_voidDisplay_BY_ShiftREG(ANIM0_P2);
	   }
	}


	// Za3bola-Animation Part2
	for(u8 LOCAL_u8Times=0; LOCAL_u8Times<4; LOCAL_u8Times++)
		{
		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		   {
			  LEDMAT_voidDisplay_BY_ShiftREG(ANIM0_P1);
		   }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		   {
			  LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P1);
	       }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P2);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P3);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		   {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P4);
	       }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P5);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P6);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P5);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		   {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P4);
	       }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P3);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		    {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P2);
		    }

		   for(u8 LOCAL_u8Count=0; LOCAL_u8Count<10; LOCAL_u8Count++)
		   {
			   LEDMAT_voidDisplay_BY_ShiftREG(ANIM1_P1);
	       }
	     }
 }
}


// Functions
void LEDMAT_voidDisplay_BY_ShiftREG(u8 * Copy_pu8Data)
{
	u8 Local_u8CountLoop;
	u8 Local_u8LoopCounter;

	for(Local_u8LoopCounter=0; Local_u8LoopCounter<8; Local_u8LoopCounter++)
	{
    // Set Only One COL
	for (Local_u8CountLoop=0; Local_u8CountLoop<8; Local_u8CountLoop++)
	{
		MGPIO_voidSetPinOutputValue(PORTA, PIN0, GET_BIT(Set_COL_Array[Local_u8LoopCounter], (7-Local_u8CountLoop)));
		MGPIO_voidSetPinOutputValue(PORTA, PIN1, HIGH);
		MSTK_voidSetBusyWait(10);
		MGPIO_voidSetPinOutputValue(PORTA, PIN1, LOW);
	}

   // SET Rows value
   for (Local_u8CountLoop=0; Local_u8CountLoop<8; Local_u8CountLoop++)
   {
		MGPIO_voidSetPinOutputValue(PORTA, PIN0, GET_BIT(*(Copy_pu8Data+Local_u8LoopCounter), (7-Local_u8CountLoop)));
		MGPIO_voidSetPinOutputValue(PORTA, PIN1, HIGH);
		MSTK_voidSetBusyWait(10);
		MGPIO_voidSetPinOutputValue(PORTA, PIN1, LOW);
   }
   // Send Data To Storage REG
	MGPIO_voidSetPinOutputValue(PORTA, PIN2, HIGH);
	MSTK_voidSetBusyWait(10);
	MGPIO_voidSetPinOutputValue(PORTA, PIN2, LOW);
  // Delay 50 FPS
    MSTK_voidSetBusyWait(2500);
	}
}



