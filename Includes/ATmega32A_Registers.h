#ifndef _ATMEGA32A_REGISTERS_H_
#define _ATMEGA32A_REGISTERS_H_

//Interrupt vectors
void __vector_8 (void) __attribute__((signal,used)); //Timer 1 CTC interrupt

//SREG register
#define SREG *((volatile uint8_t*) (0X5F))

// DIO Registers

#define PA_DIR *((volatile uint8_t*) (0X3A))
#define PA_IN *((volatile uint8_t*) (0X39))
#define PA_OUT *((volatile uint8_t*) (0X3B))

#define PB_DIR *((volatile uint8_t*) (0X37))
#define PB_IN *((volatile uint8_t*) (0X36))
#define PB_OUT *((volatile uint8_t*) (0X38))

#define PC_DIR *((volatile uint8_t*) (0X34))
#define PC_IN *((volatile uint8_t*) (0X33))
#define PC_OUT *((volatile uint8_t*) (0X35))

#define PD_DIR *((volatile uint8_t*) (0X31))
#define PD_IN *((volatile uint8_t*) (0X30))
#define PD_OUT *((volatile uint8_t*) (0X32))

// Timer Registers

// General Timer Registers
#define TIMSK *((volatile uint8_t*) (0X59))
#define TIFR *((volatile uint8_t*) (0X58))

// Timer 0 Registers
#define OCR0 *((volatile uint8_t*) (0X5C))
#define TCCR0 *((volatile uint8_t*) (0X53))
#define TCNT0 *((volatile uint8_t*) (0X52))

// Timer 1 Registers
#define TCCR1A *((volatile uint8_t*) (0X4F))
#define TCCR1B *((volatile uint8_t*) (0X4E))
#define TCNT1H *((volatile uint8_t*) (0X4D))
#define TCNT1L *((volatile uint8_t*) (0X4C))
#define OCR1AH *((volatile uint8_t*) (0X4B))
#define OCR1AL *((volatile uint8_t*) (0X4A))
#define OCR1BH *((volatile uint8_t*) (0X49))
#define OCR1BL *((volatile uint8_t*) (0X48))
#define ICR1H *((volatile uint8_t*) (0X47))
#define ICR1L *((volatile uint8_t*) (0X46))

// Timer 2 Registers
#define TCCR2 *((volatile uint8_t*) (0X45))
#define TCNT2 *((volatile uint8_t*) (0X44))
#define OCR2 *((volatile uint8_t*) (0X43))

// Bit definitions
#define OCIE1A 4


#endif
