#include "../main.h"
#include "DIO.h"

void DIO_init_bit(int /*PORTX (i.e. PORTA, PORTB..)*/ PORT_NAME, int /*PIN_NO (i.e. 0, 1, 2..)*/ PIN_NO, int /*Direction (i.e. INPUT, OUTPUT)*/ DIR){
	switch (PORT_NAME){
		case PORTA:
		switch (DIR){
			case INPUT:
			PA_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PA_DIR |= (1<<PIN_NO);
		break;}
		break;

		case PORTB:
		switch (DIR){
			case INPUT:
			PB_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PB_DIR |= (1<<PIN_NO);
		break;}

		break;

		case PORTC:
		switch (DIR){
			case INPUT:
			PC_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PC_DIR |= (1<<PIN_NO);
		break;}

		break;

		case PORTD:
		switch (DIR){
			case INPUT:
			PD_DIR &= ~(1<<PIN_NO);
			break;
			case OUTPUT:
			PD_DIR |= (1<<PIN_NO);
		break;}

		break;

	}
}

void DIO_write_bit(int /*PORTX (i.e. PORTA, PORTB..)*/ PORT_NAME, int /*PIN_NO (i.e. 0, 1, 2..)*/ PIN_NO, int /*LEVEL (i.e. LOW, HIGH)*/ LEVEL){
	switch (PORT_NAME){
		case PORTA:
		switch (LEVEL){
			case LOW:
			PA_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PA_OUT |= (1<<PIN_NO);
		break;}
		break;

		case PORTB:
		switch (LEVEL){
			case LOW:
			PB_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PB_OUT |= (1<<PIN_NO);
		break;}

		break;

		case PORTC:
		switch (LEVEL){
			case LOW:
			PC_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PC_OUT |= (1<<PIN_NO);
		break;}

		break;

		case PORTD:
		switch (LEVEL){
			case LOW:
			PD_OUT &= ~(1<<PIN_NO);
			break;
			case HIGH:
			PD_OUT |= (1<<PIN_NO);
		break;}

		break;

	}
}

uint8_t DIO_read_bit(int /*PORTX (i.e. PORTA, PORTB..)*/ PORT_NAME, int /*PIN_NO (i.e. 0, 1, 2..)*/ PIN_NO){
	uint8_t read_data = 0;
	switch (PORT_NAME){
		case PORTA:
		read_data = PA_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;

		case PORTB:
		read_data = PB_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;

		case PORTC:
		read_data = PC_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;

		case PORTD:
		read_data = PD_IN;
		read_data = read_data>>PIN_NO;
		read_data &= 0X01;
		break;

	}

	return read_data;
}

void DIO_toggle_bit(int PORT_NAME, int PIN_NO){

	if(DIO_read_bit(PORT_NAME, PIN_NO)){
		DIO_write_bit(PORT_NAME, PIN_NO, LOW);
	}
	else{
		DIO_write_bit(PORT_NAME, PIN_NO, HIGH);
	}
	return;
}

void DIO_init_port(int /*PORTX (i.e. PORTA, PORTB..)*/ PORT_NAME, uint8_t value){
	switch (PORT_NAME){
		case PORTA:
		PA_DIR = value;
		break;

		case PORTB:
		PB_DIR = value;
		break;

		case PORTC:
		PC_DIR = value;
		break;

		case PORTD:
		PD_DIR = value;
		break;

	}

}

void DIO_write_port(int /*PORTX (i.e. PORTA, PORTB..)*/ PORT_NAME, uint8_t value){
	switch (PORT_NAME){
		case PORTA:
		PA_OUT = value;
		break;

		case PORTB:
		PB_OUT = value;
		break;

		case PORTC:
		PC_OUT = value;
		break;

		case PORTD:
		PD_OUT = value;
		break;

	}
}

uint8_t DIO_read_port(int /*PORTX (i.e. PORTA, PORTB..)*/ PORT_NAME){
	switch (PORT_NAME){
		case PORTA:
		return PA_IN;
		break;

		case PORTB:
		return PB_IN;
		break;

		case PORTC:
		return PC_IN;
		break;

		case PORTD:
		return PD_IN;
		break;

	}
	return -1;
}
