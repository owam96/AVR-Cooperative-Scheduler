#include "../main.h"
#include "../DIO/DIO.h"
#include "TrafficLights.h"

enum Light_State {RED, AMBER, GREEN};
enum Traffic_Light_State {FREE_GREEN, FREE_PREPARE, BOTH_RED, BUSY_GREEN, BUSY_PREPARE};

#define FREE_STREET_PORT PORTA
#define BUSY_STREET_PORT PORTA

#define FREE_LIGHT_RED 0
#define FREE_LIGHT_GREEN 1
#define FREE_LIGHT_AMBER 2
#define BUSY_LIGHT_RED 3
#define BUSY_LIGHT_GREEN 4
#define BUSY_LIGHT_AMBER 5

enum Traffic_Light_State traffic_light_state, last_active_state;

static uint8_t time_in_state = 0;

void TrafficLights_clear(){
	
	DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_RED, LOW);
	DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_GREEN, LOW);
	DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_AMBER, LOW);
	
	DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_RED, LOW);
	DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_GREEN, LOW);
	DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_AMBER, LOW);
	
	
};

void TrafficLights_init(){
	
	DIO_init_port(PORTA, 255);
	
	TrafficLights_clear();
	
	traffic_light_state = BOTH_RED;
	DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_RED, HIGH);
	DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_RED, HIGH);
	time_in_state = 3;
	last_active_state = FREE_GREEN;
}


void TrafficLights_update(){

	switch(traffic_light_state){
		case BOTH_RED:
			TrafficLights_clear();
			DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_RED, HIGH);
			DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_RED, HIGH);
			if(--time_in_state == 1){
				if (last_active_state == FREE_GREEN){
					traffic_light_state = BUSY_GREEN;
					time_in_state = 12;
					last_active_state = BUSY_GREEN;
					}
				else{
					traffic_light_state = FREE_GREEN;
					time_in_state = 6;
					last_active_state = FREE_GREEN;
					}
			}
			break;
		
		case FREE_GREEN:
			TrafficLights_clear();
			DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_GREEN, HIGH);
			DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_RED, HIGH);
			if(--time_in_state == 1){
				traffic_light_state = FREE_PREPARE;
				time_in_state = 3;
			}
			break;
		
		case FREE_PREPARE:
		TrafficLights_clear();
		DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_AMBER, HIGH);
		DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_RED, HIGH);
		if(--time_in_state == 1){
			traffic_light_state = BOTH_RED;
			time_in_state = 2;
		}
		break;
		
		case BUSY_GREEN:
		TrafficLights_clear();
		DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_RED, HIGH);
		DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_GREEN, HIGH);
		if(--time_in_state == 1){
			traffic_light_state = BUSY_PREPARE;
			time_in_state = 3;
		}
		break;
		
		case BUSY_PREPARE:
		TrafficLights_clear();
		DIO_write_bit(FREE_STREET_PORT, FREE_LIGHT_RED, HIGH);
		DIO_write_bit(BUSY_STREET_PORT, BUSY_LIGHT_AMBER, HIGH);
		if(--time_in_state == 1){
			traffic_light_state = BOTH_RED;
			time_in_state = 2;
		}
		break;
		
	}
}

