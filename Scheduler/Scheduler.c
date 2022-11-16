#include "../main.h"
#include "Scheduler.h"
#define __STDINT_H_ // Assume stdint is defined so my own "types.h" will be used instead
#include <avr/interrupt.h>

sTask scheduler_tasks[SCH_MAX_TASKS];

void SCH_init(){
    uint8_t index;
    for(index = 0; index < SCH_MAX_TASKS; ++index){
        SCH_delete_task(index);
    }

    //Set up and start timer

    // Write 0x00 to TCNT1 register
    TCNT1H = 0x00;
    TCNT1L = 0x00;

    // Load OCR1A with 1000 (1000 oscillations = 1ms)
    OCR1AH = 0x03;
    OCR1AL = 0xE8;

    //Activate timer in CTC (clear timer on compare match) mode (auto-reload)
    //with prescaler set to 8
    TCCR1A = 0x00;
    TCCR1B = 0x09;


}

uint8_t SCH_add_task(void (*given_function)(void), const uint16_t given_delay, const uint16_t given_period){
    uint8_t index;

    for(index = 0; index < SCH_MAX_TASKS; index++){
        if(scheduler_tasks[index].go_to_function == 0)
            break;
    }

    if(index == SCH_MAX_TASKS){
        return -1;
    }
    else{
        scheduler_tasks[index].go_to_function = given_function;
        scheduler_tasks[index].delay_to_start = given_delay;
        scheduler_tasks[index].period = given_period;
        scheduler_tasks[index].run_me = 0;

        return index;
    }


}

void SCH_dispatch_tasks(){
    uint8_t index;

    for(index = 0; index < SCH_MAX_TASKS; index++){
        if(scheduler_tasks[index].run_me){
            (*scheduler_tasks[index].go_to_function)();
            scheduler_tasks[index].run_me -= 1;
            if(scheduler_tasks[index].period == 0){
                SCH_delete_task(index);
            }
        }
    }

    SCH_report_status();

}

void SCH_start(){

    // Enable interrupts

    //Enable CTC timer 1 interrupt
    //by setting bit OCIE1A in TIMSK register
    SET_BIT(TIMSK, OCIE1A);

    //Enable global interrupts
    sei();
}

ISR(TIMER1_COMPA_vect){ // SCH_update function -- Timer 1 CTC interrupt

    uint8_t index;
    for(index = 0; index < SCH_MAX_TASKS; index++){

        if(scheduler_tasks[index].go_to_function){

            if(scheduler_tasks[index].delay_to_start == 0){

                scheduler_tasks[index].run_me++;

                if(scheduler_tasks[index].period){

                    scheduler_tasks[index].delay_to_start = scheduler_tasks[index].period;

                }
            }
            else{
                scheduler_tasks[index].delay_to_start--;
            }
        }
    }

}

void SCH_report_status(){


}

void SCH_delete_task(const uint8_t index){

    if(index < SCH_MAX_TASKS){
        scheduler_tasks[index].go_to_function = 0;
        scheduler_tasks[index].delay_to_start = 0;
        scheduler_tasks[index].period = 0;
        scheduler_tasks[index].run_me = 0;
    }
    else{
        return;
    }

}
