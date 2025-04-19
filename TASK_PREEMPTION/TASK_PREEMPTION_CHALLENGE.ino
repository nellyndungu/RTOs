// NDUNG'U NELLY W
// EMBEDDED SYSTEM ENGINEER
// 10/03/2025
// PREEMPTION CHALLENGE

//CHALLENGE: Use 2 tasks to control blinking rate of LED
      // Task_1 should listen for input from serial terminal for delay
      // Task_2 have a preset delay for blinking LED
      // Use 1 core

//Configure one core of ESP32 
#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif

//Define the LED output pin
static const int LED = 2;
//Task: listen to Serial monitor for blinking frequency
void serialBlink(void *parameter){
  while(1){
  if(Serial.available() > 0){
    int tick = Serial.parseInt();
    Serial.println(tick);
    digitalWrite(LED, HIGH);
    vTaskDelay(tick/ portTICK_PERIOD_MS);
    digitalWrite(LED, LOW);
    vTaskDelay(tick/ portTICK_PERIOD_MS);
  }
  else{
    Serial.println("Enter delay");
  }
  }
}
//Task: Blink LED via preset frequency
void blinkLed(void *parameter){
  while(1){
  digitalWrite(LED, HIGH);
  vTaskDelay(500/ portTICK_PERIOD_MS);
  digitalWrite(LED, LOW);
  vTaskDelay(500/ portTICK_PERIOD_MS);
}
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  vTaskDelay(2000/ portTICK_PERIOD_MS);
  //Call tasks
  //Task_1 with higher priority
  xTaskCreatePinnedToCore(
    serialBlink,
    "User Blink",
    1024,
    NULL,
    2,
    NULL,
    app_cpu);
    
  //Task 2 with lower priority
  xTaskCreatePinnedToCore(
    blinkLed,
    "Program Blink",
    1024,
    NULL,
    1,
    NULL,
    app_cpu);
    vTaskDelete(NULL);
}

void loop() {
  // put your main code here, to run repeatedly:

}
