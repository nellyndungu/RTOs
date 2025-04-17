// NDUNG'U NELLY W
// EMBEDDED SYSTEM ENGINEER
// NAIROBI, KENYA
// 16/03/2025
// Task: Control biult-in LED with different blinking patterns
//Use only one core of ESP32
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif
// Define LED pin
static const int LED = 2;
//Blinking LED task (ON = 500 ms OFF = 200ms)
 void blinkLed(void *parameter){
   while(1){
    digitalWrite(LED, HIGH);
    vTaskDelay(500/ portTICK_PERIOD_MS);
    digitalWrite(LED, LOW);
    vTaskDelay(200/ portTICK_PERIOD_MS);
   }}
 void signalLed(void *parameter){
   while(1){
    digitalWrite(LED, HIGH);
    vTaskDelay(200/ portTICK_PERIOD_MS);
    digitalWrite(LED, LOW);
    vTaskDelay(200/ portTICK_PERIOD_MS);
   }  
 }

void setup() {
  //configure the LED pin
  pinMode(LED, OUTPUT);
  //Task to always run
  //Function
  xTaskCreatePinnedToCore(
    blinkLed,     //Function to be called
    "Blink LED",  //Name of task
    1024,         //Memory stack size
    NULL,         //Parameter to pass to function
    1,            // Task priority
    NULL,         // Task handle
    app_cpu) ;   // Define the core the task will run
//Create another task/thread with different blinking frequency
  xTaskCreatePinnedToCore(
    signalLed,
    "Signal LED",
    1024,
    NULL,
    5,
    NULL,
    app_cpu);
}

void loop() {
  // put your main code here, to run repeatedly:

}
