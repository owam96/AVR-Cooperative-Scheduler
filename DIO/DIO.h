#ifndef _DIO_H_
#define _DIO_H_

#include "../main.h"

enum PORT {PORTA = 1, PORTB = 2, PORTC = 3, PORTD = 4};
enum DIRECTION {INPUT = 0, OUTPUT = 1};
enum V_LEVEL {LOW = 0, HIGH = 1};

void DIO_init_bit(int PORT_NAME, int PIN_NO, int DIR);
void DIO_write_bit(int PORT_NAME, int PIN_NO, int LEVEL);
uint8_t DIO_read_bit(int PORT_NAME, int PIN_NO);
void DIO_toggle_bit(int PORT_NAME, int PIN_NO);

void DIO_init_port(int PORT_NAME, uint8_t value);
void DIO_write_port(int PORT_NAME, uint8_t value);
uint8_t DIO_read_port(int  PORT_NAME);

#endif
