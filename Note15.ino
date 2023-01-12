#define LED 21
#define Button_Pin   35
hw_timer_t *My_timer = NULL;
int d;int cout = 0;
  int level;
void button(){
  
  
  if(digitalRead(Button_Pin)==HIGH){
    cout++;
  }
  level = cout%5;
  if(level == 0){
    d = 200; 
  }
  if(level == 1){
    d = 400; 
  }
  if(level == 2){
    d = 600; 
  }
  if(level == 3){
    d = 800; 
  }
  if(level == 4){
    d = 1000; 
  }
}

// This is the Timer ISR. It is automatically called 
// on a timer alarm event.
void IRAM_ATTR onTimer(){
  digitalWrite(LED, !digitalRead(LED));
}

void setup() {
  pinMode(Button_Pin, INPUT);
  pinMode(LED, OUTPUT);
  My_timer = timerBegin(0, 80, true);  // use tiemr 0 and set prescale to 80 so 1 tick is 1 uSec
  timerAttachInterrupt(My_timer, &onTimer, true); // point to the ISR
  timerAlarmWrite(My_timer, 800, true);  // set alarm every 1 sec
  timerAlarmEnable(My_timer);  // enable the alarm
  attachInterrupt(Button_Pin, button, RISING);
  
}

void loop() {

timerAlarmWrite(My_timer, 800, true);
delay(d);
timerAlarmWrite(My_timer, 600, true);
delay(d);
timerAlarmWrite(My_timer, 500, true);
delay(d);
timerAlarmWrite(My_timer, 900, true);
delay(d);
timerAlarmWrite(My_timer, 800, true);
delay(d);
timerAlarmWrite(My_timer, 400, true);
delay(d);
timerAlarmWrite(My_timer, 600, true);
delay(d);
timerAlarmWrite(My_timer, 880, true);
delay(d);
timerAlarmWrite(My_timer, 900, true);
delay(d);
timerAlarmWrite(My_timer, 869, true);
delay(d);
timerAlarmWrite(My_timer, 880, true);
delay(d);
timerAlarmWrite(My_timer, 780, true);
delay(d);
timerAlarmWrite(My_timer, 500, true);
delay(d);
timerAlarmWrite(My_timer, 900, true);
delay(d);
timerAlarmWrite(My_timer, 500, true);
delay(d);
timerAlarmWrite(My_timer, 1000, true);
delay(d);
timerAlarmWrite(My_timer, 100, true);
delay(d);
}