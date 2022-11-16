#include "main.h"
#include "Scheduler/Scheduler.h"
#include "TrafficLights/TrafficLights.h"

int main(void)
{
    TrafficLights_init();

    SCH_init();

    SCH_add_task(TrafficLights_update, 0, 1000);
	
    SCH_start();

    while(1){
        SCH_dispatch_tasks();
    }

    return 0;
}
