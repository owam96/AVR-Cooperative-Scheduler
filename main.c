#include "main.h"
#include "Scheduler/Scheduler.h"
#include "LED/LED.h"

int main(void)
{

    LED_init();

    SCH_init();

    SCH_add_task(LED_update, 0, 1000);

    SCH_start();

    while(1){
        SCH_dispatch_tasks();
    }

    return 0;
}
