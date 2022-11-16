#ifndef _MAIN_H_
#define _MAIN_H_

#include "include/types.h"
#include "include/ATmega32A_Registers.h"

/* The ATmega family have a 1-instruction per 1 clock cycle ratio */
#define CLOCK_FREQ (1000000UL)

#define TRUE (1)
#define FALSE (0)

#define SET_BIT(register, bit) register|=(1<<bit)
#define CLR_BIT(register, bit) register&=~(1<<bit)

#endif // _MAIN_H_
