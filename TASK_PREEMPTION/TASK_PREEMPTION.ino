//NDUNG'U NELLY
//EMBEDDED SYSTEM ENGINEER
//10/03/2025
//Task preemption demonstration - task execution based on priority


//CONFIGURE USING ONE CORE OF ESP32
//run FreeRtos on first core only using CONFIG_FREERTOS_UNICORE
#if CONFIG_FREERTOS_UNICORE     
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu =1;
#endif
//Some string to print
const char message[] = "Nelly Ndung'u";
//Use task handles in order to control tasks from a third task
static TaskHandle_t TASK_1 = NULL;
static TaskHandle_t TASK_2 = NULL;

//TASK: Print to serial monitor with lower priority
void printTask1 (void *parameter){
  //Count number of characters in message
  int msgLength = strlen(message);
  while(1){
    for(int i=0; i< msgLength; i++){
      Serial.print(message[i]);
    }
    //Delay or put in blocked state for 1 sec
    Serial.println();
    vTaskDelay(500/ portTICK_PERIOD_MS);
  }
}
//TASK: Print to serial monitor with higher priority
void printTask2(void *parameter){
  while(1){
    Serial.print("*");
    vTaskDelay(100/ portTICK_PERIOD_MS);
  }
} 
void setup() {
  // Setup serial monitor
  Serial.begin(300);
  //Delay to connect serial communication
  vTaskDelay(2000/ portTICK_PERIOD_MS);
  Serial.println();
  Serial.println("Task Preemption");
  //Print core and priority
  Serial.print("Setup and loop task running on core ");
  //Get the core using xPortGetCoreID
  Serial.print(xPortGetCoreID());
  Serial.print(" with priority ");
  Serial.print(uxTaskPriorityGet(NULL));

  //Start running tasks
  //Task 1
  xTaskCreatePinnedToCore(
    printTask1,  
    "Task 1",
    1024,
    NULL,
    1,
    &TASK_1,
    app_cpu);

    //Task 2
    xTaskCreatePinnedToCore(
      printTask2,
      "Task 2",
      1024,
      NULL,
      2,
      &TASK_2,
      app_cpu);
}


void loop() {
  // Suspending higher priority task
  for(int y = 0; y < 3; y++){
    vTaskSuspend(TASK_2);
    vTaskDelay(2000/ portTICK_PERIOD_MS);
    vTaskResume(TASK_2);
    vTaskDelay(2000/ portTICK_PERIOD_MS);
  }
  //Delete lower priority task
  if(TASK_1 != NULL){
    vTaskDelete(TASK_1);
    //Calling a NULL task can cause precessor to crash
    TASK_1 = NULL;
  }
}
