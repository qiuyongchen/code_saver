#include "register_variant.h"
#define LED_CS2			(*((volatile unsigned short *)(0x10300000)))
#define LED_CS3			(*((volatile unsigned short *)(0x10400000)))


#define KPC				(*((volatile unsigned int *)(0x41500000)))
#define KPDK_VALUE		(*((volatile unsigned short *)(0x41500008)))
#define KPAS_VALUE 		(*((volatile unsigned short *)(0x41500020)))	


#define	OSCR		(*(volatile unsigned long *)(osTimer_OSCR))
#define	ICPR		(*(volatile unsigned long *)(int_ICPR))

#define	OSMR0		(*(volatile unsigned long *)(0x40a00000))
#define	OSMR1		(*(volatile unsigned long *)(0x40a00004))
#define	OSMR2		(*(volatile unsigned long *)(0x40a00008))	
#define	OSMR3		(*(volatile unsigned long *)(0x40a0000c))

#define OSSR		(*(volatile unsigned long *)(0x40a00014))
#define OIER		(*(volatile unsigned long *)(0x40a0001c))



void Delay(unsigned int x)
{
	unsigned int i, j, k;
	for (i =0; i <=x; i++)
		for (j = 0; j <0xff; j++)
			for (k = 0; k <0xff; k++);
}


void IRQ_Function(void)
{

	if (OSSR == 0x01)
	{
		LED_CS2 = 0x8F79;
		LED_CS3 = 0x8F8F;
		Delay(1000);
		LED_CS2 = 0x2479;
		LED_CS3 = 0x1930;
	}
	
	if (OSSR == 0x02)
	{
		LED_CS2 = 0x248F;
		LED_CS3 = 0x8F8F;
		Delay(1000);
		LED_CS2 = 0x2479;
		LED_CS3 = 0x1930;
	}	
	
	if (OSSR == 0x04)
	{
		LED_CS3 = 0x8F30;	
		LED_CS2 = 0x8F8F;
		Delay(1000);
		LED_CS2 = 0x2479;
		LED_CS3 = 0x1930;
	}
	
	if (OSSR == 0x08)
	{
		LED_CS3 = 0x198F;	
		LED_CS2 = 0x8F8F;
		Delay(1000);
		LED_CS2 = 0x2479;
		LED_CS3 = 0x1930;
	}
	
}



void dummyOs()
{
 	int pretimer;
	
	LED_CS2 = 0x2479;
	LED_CS3 = 0x1930;

    while(1)
    {
 		char i;
		i = KPDK_VALUE;
    	
    	switch (i)
    	{
    		case 0x40:
    			OIER = 0x1;		//enable timer 0
    			pretimer = OSCR;
    			OSMR0 = pretimer + 0x800000;
				Delay(10);
    		    break;
    		
    		case 0x02:
    			OIER = 0x2;		//enable timer 1
    			pretimer = OSCR; 
    		    OSMR1 = pretimer + 0x800000;
    		    Delay(10);
    		    break;
    		
    		case 0x04:
    			OIER = 0x4;		//enable timer 2
    			pretimer = OSCR;
    			OSMR2 = pretimer + 0x800000;
    			Delay(10);
    			break;
    			
    		case 0x20:
    			OIER = 0x8;		//enable timer 3
    			pretimer = OSCR;
    			OSMR3 = pretimer + 0x800000;
    			Delay(10);
    			break;
    				
    		default : break;
    			
    	}

    }

}