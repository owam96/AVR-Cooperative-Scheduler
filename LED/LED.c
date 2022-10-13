#include "../main.h"
#include "../DIO/DIO.h"
#include "LED.h"


void LED_init(){
    DIO_init_bit(PORTA, 2, OUTPUT);
    DIO_init_port(PORTD, 255);
    DIO_init_port(PORTC, 255);
    DIO_write_port(PORTC, 255);
}


void LED_update(){

    if(DIO_read_bit(PORTA, 2) == LOW){
        DIO_write_bit(PORTA, 2, HIGH);
    }
    else{
        DIO_write_bit(PORTA, 2, LOW);
    }

}

