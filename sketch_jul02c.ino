
#define servo_ba_ES 11
#define servo_ba_DR 12
#define servo_pe_ES 13
#define servo_pe_DI 10

#define tempo 25


void servo0graus();
void servo90graus();
void servo180graus();

void servo90graus_di();
void servo0graus_di();




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(servo_ba_ES ,OUTPUT);
  pinMode(servo_ba_DR ,OUTPUT);
  pinMode(servo_pe_ES ,OUTPUT);
  pinMode(servo_pe_DI,OUTPUT);
}



void loop() {
  // put your main code here, to run repeatedly:

for(char i=0;i<tempo;i++)
    servo0graus(); 

for(char i=0;i<tempo;i++)
    servo90graus(); 


for(char i=0;i<tempo;i++)
    servo0graus_di(); 

for(char i=0;i<tempo;i++)
    servo90graus_di(); 


//for(char i=0;i<100;i++)
   // servo180graus(); 


}


void servo0graus(){
   ///Ba_ES
   digitalWrite(servo_ba_ES,HIGH);
   delayMicroseconds(600); //0.6 ms
   digitalWrite(servo_ba_ES,LOW); 
   for(int i=0;i<32;i++)
     delayMicroseconds(600);//20 ms = 20000us
}                           //20000us - 600us = 19400us
                            //19400us/600us ~~32 it

void servo0graus_di(){
 ///Ba_DI
   digitalWrite(servo_ba_DR,HIGH);
   delayMicroseconds(600); //0.6 ms
   digitalWrite(servo_ba_DR,LOW); 
   for(int i=0;i<32;i++)
     delayMicroseconds(600);
     

  
}



void servo90graus(){
   ///Ba_ES
   digitalWrite(servo_ba_ES,HIGH);
   delayMicroseconds(1500);//1.5 ms
   digitalWrite(servo_ba_ES,LOW);
   for(int i=0;i<12;i++)
     delayMicroseconds(1500);//20 ms = 20000us
}                           //20000us - 1500us = 18500us
                            //18500us/1500us ~~12 it



void servo90graus_di(){
  ///Ba_DI
   digitalWrite(servo_ba_DR,HIGH);
   delayMicroseconds(1500);//1.5 ms
   digitalWrite(servo_ba_DR,LOW);
   for(int i=0;i<12;i++)
     delayMicroseconds(1500);

}


  

void servo180graus(){
   
   digitalWrite(servo_ba_ES,HIGH);
   delayMicroseconds(2400);//2.4 ms
   digitalWrite(servo_ba_ES,LOW);
   for(int i=0;i<7;i++)
     delayMicroseconds(2400);//20 ms = 20000us
}                           //20000us - 600us = 17600us
                            //17600us/24000us ~~7
  
