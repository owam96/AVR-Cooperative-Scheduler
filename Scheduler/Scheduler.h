#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include "../main.h"

#define SCH_MAX_TASKS (1)

typedef struct task{

    void (*go_to_function)(void);
    uint16_t delay_to_start;
    uint16_t period;
    uint8_t run_me;

} sTask;

void SCH_init();
uint8_t SCH_add_task(void (*)(void),const uint16_t, const uint16_t);
void SCH_dispatch_tasks();
void SCH_start();
void SCH_delete_task(const uint8_t);
void SCH_report_status();


#endif // _SCHEDULER_H_
