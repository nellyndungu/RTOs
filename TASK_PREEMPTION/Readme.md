## Task Preemption
Allows two tasks with different priorities to interact, suspend, resume and delete these tasks during runtime. <br>

### Features
1. Unicore configuration
2. Dual task execution
    > Task 1 prints name character by character <br>
    > Task 2 prints astericks repeatedly
4. Task suspension and resumption
5. Task deletion
6. Task control using handles
### Tips
1. Avoid calling vTaskDelete() on NULL task handles — this may crash the processor.
2. Use xTaskCreatePinnedToCore() for pinning tasks to a specific ESP32 core.
3. vTaskDelay() yields control to allow other tasks to run.
### Dependancies
1. ESP32 board (with Arduino core)
2. FreeRTOS (bundled with ESP32 Arduino)
