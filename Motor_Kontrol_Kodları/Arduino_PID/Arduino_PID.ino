/*Berkay Yildirim*/

String mySt="";
boolean stringComplete = false; // stringin complete i için
boolean motor_run = false;
//pin atamalari
const byte pin_a = 2; // encoder A pulse
const byte pin_b = 3; //encoder B pulse
const byte pin_forward = 4; //motor ileri yön
const byte pin_backward = 5; //motor geri yön
const byte pin_pwm = 6; //motor hizi
//motor ve hata degiskenleri
int encoder = 0;
double pv_speed = 0; // motorun simdiki hizi
double set_speed = 0; //motor icin ayarlanicak hiz
double error_speed = 0; // set_speed-pv_speed
double error_speed_pre = 0; //son hata hizi
double error_speed_sum = 0;//hatalarin toplami
double PID = 0;//pid degeri
double kp = 0;//proportional kontrol
double kd = 0;//derivative kontrol
double ki = 0;//integral kontrol
double p,in,d =0; // pid degerleri
int timer1_counter;//timer icin
volatile int lastencoded =0;





void setup() {
  //Pinler ayarlandı.
  pinMode(pin_a,INPUT_PULLUP);
  pinMode(pin_b,INPUT_PULLUP);
  pinMode(pin_forward,OUTPUT);
  pinMode(pin_backward,OUTPUT);
  pinMode(pin_pwm,OUTPUT);
  //kesme modu ayarlandi
  attachInterrupt(digitalPinToInterrupt(pin_a), a_encoder, RISING);
  attachInterrupt(digitalPinToInterrupt(pin_b), a_encoder, RISING);


  Serial.begin(9600);//haberlesme  ayarlandi




  cli();//tüm interruptlar devre dışı
  TCCR1A = 0; //tüm TCCR1A yazmacını sıfırlar.
  TCCR1B = 0; //tüm TCCR1B yazmacını sıfırlar.
  timer1_counter = 59286;   // preload timer  59286 for 0.1sec
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  sei(); //tüm interruptlar etkin  

  
  while (!Serial) {
    ; // seri port baglantisi icin bekleniyor.
  }
  
  analogWrite(pin_pwm,0);   //motor hizi 0
  digitalWrite(pin_forward,0);  //motor ileri yonde 0
  digitalWrite(pin_backward,0);  //motor geri yonde 0
  
  

}

void loop() {
  //veri alma isleminden sonra string temizleniyor.
  if (stringComplete) {
    mySt = "";  
    stringComplete = false;
  }
  //visualdan start komutu gelince motor ileri yonde harekete geciyor
  if (mySt.substring(0,5) == "start"){

    if(set_speed>0 ){
     
      digitalWrite(pin_forward,1);      
      digitalWrite(pin_backward,0);
      motor_run = true;
    }
    //ayarlanan hiz ters yönde ise ve visualdan start komutu gelince motor geri yonde  harekete geciyor

    else {
    
      digitalWrite(pin_forward,0);      
      digitalWrite(pin_backward,1);
      motor_run = true;
    }
    
  }
  //visualdan stop komutu gelince motor duruyor
  if (mySt.substring(0,4) == "stop"){
    digitalWrite(pin_forward,0);
    digitalWrite(pin_backward,0);      //stop motor
    motor_run = false;
  }
  if (mySt.substring(0,9) == "set_speed"){
   
    set_speed = mySt.substring(9,mySt.length()).toFloat(); //visualdan set speed ayarlaniyor.
  }
  if (mySt.substring(0,2) == "kp"){
       
    kp = mySt.substring(2,mySt.length()).toFloat(); //visualdan kp ayarlaniyor.
  }
  if (mySt.substring(0,2) == "ki"){
        
    ki = mySt.substring(2,mySt.length()).toFloat(); //visualdan ki ayarlaniyor.
  }
  if (mySt.substring(0,2) == "kd"){
  
    kd = mySt.substring(2,mySt.length()).toFloat(); //visualdan kd ayarlaniyor.
  }

}
//motorun hangi yonde dondugu tespit ediliyor.
void a_encoder(){
  int MSB =digitalRead(pin_a);
  int LSB =digitalRead(pin_b);
  int encoded =(MSB<<1)|LSB;
  int sum = (lastencoded<<2)|encoded;
  if(sum ==0b1101||sum==0b0100||sum==0b0010||sum==0b1011) encoder ++;
  if(sum ==0b1110||sum==0b0111||sum==0b0001||sum==0b1000) encoder --;
}


ISR(TIMER1_OVF_vect)        // interrupt service routine - tick every 0.1sec
{
  TCNT1 = timer1_counter;   // timer ayarlandi.
  pv_speed = 600.0*(encoder/200.0)/0.1;  //motor hizi hesaplandi.
  encoder=0;
  //print out speed
  if (Serial.available() <= 0) {
    Serial.print("speed");
    Serial.println(pv_speed);         //Speed degeri visual'a gonderildi.
  }

  if(set_speed>0){
    
    if(motor_run){
    
      error_speed = set_speed - pv_speed;
      p = kp*error_speed;
      in = error_speed_sum*ki;
      d = (kd*(error_speed-error_speed_pre));
      PID = p+in+d;
      error_speed_pre = error_speed;
      error_speed_sum += error_speed;
        if (error_speed_sum >4000)
          error_speed_sum = 4000;
        if (error_speed_sum <-4000) 
          error_speed_sum = -4000;
    }
    else{
      error_speed = 0;
      error_speed_pre = 0;
      PID = 0;
    }
    if (PID <255 & PID >0){
      analogWrite(pin_pwm,PID); 
    }
    else{
      if (PID>255){
        analogWrite(pin_pwm,255);
      }
      else{
        analogWrite(pin_pwm,0);
      }
    }
  }
  else{
    if(motor_run){
    
      error_speed = (set_speed - pv_speed)*-1;
      p = kp*error_speed;
      in = error_speed_sum*ki;
      d = (kd*(error_speed-error_speed_pre));
      PID = p+in+d;
      error_speed_pre = error_speed;
      error_speed_sum += error_speed;
        if (error_speed_sum >4000)
          error_speed_sum = 4000;
        if (error_speed_sum <-4000)
          error_speed_sum = -4000;
     }
     else{
       error_speed = 0;
       error_speed_pre = 0;
       PID = 0;
     }
     if (PID <255 & PID >0){
       analogWrite(pin_pwm,PID);  //set motor speed  
     }
     else{
       if (PID>255){
         analogWrite(pin_pwm,255);
       }
       else{
         analogWrite(pin_pwm,0);
       }
     }
   }
}

void serialEvent() {
  while (Serial.available()) {
       // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    if (inChar != '\n') {
      mySt += inChar;
    }
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
