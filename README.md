# AVR-Cooperative-Scheduler

This is a rough implementation of a cooperative scheduler that executes tasks in a round-robin fashion, without priorities. It simply schedules tasks and assigns each task a number of ticks (1 ms) and decrements the tick counter for each task as the timer ticks. When the timer reaches 0, the task is ready for execution and will be executed if no other task is in execution.
