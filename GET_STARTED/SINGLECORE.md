The onboard LED is blinked with two different patterns using two tasks, both pinned to a single core of the ESP32.
### DATA TYPES
1. BaseType_t
  > This is used to define the core number where a task should run. 
  > It's a FreeRTOS type for handling of base-level operations.
2. void *parameter
  > Generic pointer passed to task functions.
  > Used to pass data when needed.
3. const int
  > Constant integer values <br>
Each task must:
  > Be defined as a function with void return type.
  > Accept a void* parameter (even if unused).
  > Run an infinite loop (while(1)) to keep the task alive.
FreeRTOS uses vTaskDelay() to pause a task without blocking the entire system:
  > vTaskDelay(500 / portTICK_PERIOD_MS); delays the task for 500ms.
  > portTICK_PERIOD_MS converts milliseconds into FreeRTOS ticks (usually 1ms/tick)
