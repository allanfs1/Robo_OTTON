
/* Sweep
Auhor@Allan
*/

#include <Servo.h>
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>

#define buzzer 13
#define start 1000 ///tempo do delay
#define tempo 200
#define FAIXA_ANGULO 45
#define OPERACT 5
//-----DFPlayer Volume
#define VOLUME 30
//--------------------------------------------------------------
SoftwareSerial secondarySerial(4, 5); // RX, TX (Serial digital)
//----------------------------------------------------------------------
///(Const) Definição do pinos Servos Pinos Servos
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
Servo myservo3;
Servo myservo4;
// twelve servo objects can be created on most boards
int pos=0,FE=420,tempo_delay[4] = {8,10,12,14},i=0; //ms   // variable to store the servo position

void Milliseconds(int corte);
void padrao_um(int8_t angulo_beta,int8_t angulo_teta);
void padrao_dois(int8_t angulo_beta,int8_t angulo_teta,const int ZERO,boolean padrao);
void buzz();

///Metodos Estaticos//
class Mp3Notify
{
public:
  static void OnError(uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }

  static void OnPlayFinished(uint16_t globalTrack)
  {
    Serial.println();
    Serial.print("Play finished for #");
    Serial.println(globalTrack);   
  }

  static void OnCardOnline(uint16_t code)
  {
    Serial.println();
    Serial.print("Card online ");
    Serial.println(code);     
  }

  static void OnUsbOnline(uint16_t code)
  {
    Serial.println();
    Serial.print("USB Disk online ");
    Serial.println(code);     
  }

  static void OnCardInserted(uint16_t code)
  {
    Serial.println();
    Serial.print("Card inserted ");
    Serial.println(code); 
  }

  static void OnUsbInserted(uint16_t code)
  {
    Serial.println();
    Serial.print("USB Disk inserted ");
    Serial.println(code); 
  }

  static void OnCardRemoved(uint16_t code)
  {
    Serial.println();
    Serial.print("Card removed ");
    Serial.println(code);  
  }

  static void OnUsbRemoved(uint16_t code)
  {
    Serial.println();
    Serial.print("USB Disk removed ");
    Serial.println(code);  
  }
};

DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);
void setup() {
  Serial.begin(9600);
  mp3.begin();//DF Player mini
  //----------------------------------------------
  mp3.playMp3FolderTrack(5); // sd:/mp3/0005.mp3
  delay(start+4000);  ///Fala de Inicio
  //--------------------------------------------------
  ///Start
  buzz();
  delay(start);
  //----------------------------------------------------------------------------------
  myservo1.attach(11);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(12);  // attaches the servo on pin 9 to the servo object
  myservo3.attach(10);  // attaches the servo on pin 9 to the servo object
 // myservo4.attach(9);  // attaches the servo on pin 9 to the servo object
  //Angulo Inicial
  myservo1.write(0);              // tell servo to go to position in variable 'pos'
  myservo2.write(0);  ///Definindo servos para ponto 0
  myservo3.write(0);              // tell servo to go to position in variable 'pos'
  //myservo4.write(0);
  ////-----------------------------------------------------------------------------
  //DFPlayer pro mini
  uint32_t volume = mp3.getVolume();
  mp3.setVolume(VOLUME);
  uint8_t count = mp3.getTotalTrackCount();
  Serial.print("Pasta n=");
  Serial.println(count);
///-----------------------------------------
///Buzzer//
  pinMode(buzzer,OUTPUT);
  tone(buzzer,200,tempo);
  delay(2000);
  tone(buzzer,600,tempo);
  delay(2000);
  
  mp3.playMp3FolderTrack(2); // sd:/mp3/0002.mp3
  delay(start+3500); ///Fala escolhendo musica
  

}

void loop() {  
int j =0;

for (char i=0; i<(OPERACT*2);i++){ 
 for (pos = 0; pos <= FAIXA_ANGULO; pos += 1) {
    myservo3.write(pos);
    delay(5);
    tone(buzzer,FE+=1,tempo);
}

 for (pos = FAIXA_ANGULO; pos >= 0; pos -= 1){
  myservo3.write(pos);
  delay(5);
  tone(buzzer,FE+=1,tempo);
}
  }


 for (char i=0; i<(OPERACT/2);i++){ 
   for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(0);              // tell servo to go to position in variable 'pos'
    myservo2.write(pos); 
    delay(tempo_delay[j]);                       // waits 15ms for the servo to reach the position
    tone(buzzer,FE+=1,tempo);
  }
  
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(0);
    myservo2.write(pos);
   // myservo3.write(pos);// tell servo to go to position in variable 'pos'
    delay(tempo_delay[j]);                       // waits 15ms for the servo to reach the position
    tone(buzzer,FE-=1,tempo);
  }

 }



 for (char i=0; i<(OPERACT/2);i++){ 
   for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo2.write(0); 
    delay(tempo_delay[j]/2);                       // waits 15ms for the servo to reach the position
    tone(buzzer,FE+=1,tempo);
  }
  
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);
    myservo2.write(0);
   // myservo3.write(pos);// tell servo to go to position in variable 'pos'
    delay(tempo_delay[j]/2);                       // waits 15ms for the servo to reach the position
    tone(buzzer,FE-=1,tempo);
  }

 }

  for (char i=0; i<OPERACT;i++){
     padrao_um(45,0);
     tone(buzzer,FE,tempo*2);
  }


for (char i=0; i<(OPERACT/2);i++){ 
  for (char i=0; i<5;i++){/// meio Segundo = (500ms)
     padrao_dois(0,90,0,true);
     tone(buzzer,FE,(tempo + i)/2);
  }

 for (char i=0; i<(OPERACT/2);i++){/// meio Segundo = (500ms)
     padrao_dois(0,90,0,false);
     tone(buzzer,FE,(tempo + i)/2);
  }

}

  for (char i=0; i<(OPERACT/2);i++){
     padrao_um(45,0);
     tone(buzzer,FE,tempo/2);
  }

myservo1.write(0);
myservo2.write(0);

for (char i=0; i<(OPERACT*2);i++){ 
 for (pos = 0; pos <= FAIXA_ANGULO; pos += 1) {
    myservo3.write(pos);
    delay(5);
    tone(buzzer,FE+=1,tempo);
}

 for (pos = FAIXA_ANGULO; pos >= 0; pos -= 1){
  myservo3.write(pos);
  delay(5);
  tone(buzzer,FE+=1,tempo);
}
  }





for (char i=0; i<(OPERACT/2);i++){ 
 for (pos = 0; pos <= FAIXA_ANGULO; pos += 1) {
    myservo3.write(pos);
    delay(10);
    tone(buzzer,FE-=1,tempo);
}

 for (pos = FAIXA_ANGULO; pos >= 0; pos -= 1){
  myservo3.write(pos);
  delay(10);
  tone(buzzer,FE-=1,tempo);
}

}


};



 void padrao_um(int8_t angulo_beta,int8_t angulo_teta){
    mp3.playMp3FolderTrack(4); // sd:/mp3/0004.mp3
    Milliseconds(300);
    
    myservo1.write(angulo_beta); 
    myservo2.write(angulo_beta);
    delay(150);
    
    myservo1.write(angulo_teta);
    myservo2.write(angulo_teta);
    delay(250);
 
    myservo1.write(angulo_beta);
    myservo2.write(angulo_beta);
    delay(150);
    
  }


void padrao_dois(int8_t angulo_beta,int8_t angulo_teta,const int ZERO,boolean padrao){
 
  
  if(padrao == true){
    myservo1.write(angulo_beta); 
    myservo2.write(ZERO);//0
    delay(150);
    
    myservo1.write(angulo_teta);
    myservo2.write(ZERO);
    delay(250);
 
    myservo1.write(angulo_beta);
    myservo2.write(ZERO);
    delay(150);

  }

  else{
    myservo1.write(ZERO); 
    myservo2.write(angulo_beta);//0
    delay(150);
    
    myservo1.write(ZERO);
    myservo2.write(angulo_teta);
    delay(250);
 
    myservo1.write(ZERO);
    myservo2.write(angulo_beta);
    delay(150);

  }
  

    
  }

void buzz(){
// turn off tone function for pin 8:
for(char i=0;i<6;i++){
  noTone(buzzer);
  // play a note on pin 6 for 200 ms:
  tone(buzzer, 440);
  delay(200);

  // turn off tone function for pin 6:
  noTone(buzzer);
  // play a note on pin 7 for 500 ms:
  tone(buzzer, 894);
  delay(500);

  // turn off tone function for pin 7:
  noTone(buzzer);
  // play a note on pin 8 for 300 ms:
  tone(buzzer, 123);
  delay(300);

  }

}


void Milliseconds(int corte){
  unsigned  long vl_init = millis(); 
  while ((millis() - vl_init) < corte)
  {
    mp3.loop(); 
    delay(1);
  }
  
}
 


 
