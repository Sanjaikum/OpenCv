
#include <Servo.h>
#define recvalue 5
#define digitpervaluerec 1

Servo servoThumb;
Servo servoindex;
Servo servomiddle;
Servo servoring;
Servo servopinky;

int value[recvalue];
int stringlen =recvalue*digitpervaluerec+1;
int counter =0;
bool counterStart =false;
String receivedString;
void setup() {
Serial.begin(9600);
servoThumb.attach(7);
servoindex.attach(9);
servomiddle.attach(11);
servoring.attach(8);
servopinky.attach(10);
}

void received() {
  while(Serial.available()){
    char c =Serial.read();
    if(c=='$'){
      counterStart =true;
      }
    if(counterStart){
      
      if(counter<stringlen){
        receivedString =String(receivedString+c);
        counter++;
        }
      
      if(counter>=stringlen){
        for (int i=0;i<recvalue;i++){
          
          int num =(i*digitpervaluerec)+1;
          value[i] =  receivedString.substring(num,num+digitpervaluerec).toInt();
          }
        receivedString ="";
        counter=0;
        counterStart =false;
        
        }
      }
    
    
    
    
    
    
    }
  // put your main code here, to run repeatedly:

}

void loop(){
  
  received();
  if(value[0]==1){servoThumb.write(180);}else{servoThumb.write(0);}
  if(value[1]==1){servoindex.write(180);}else{servoindex.write(0);}
  if(value[2]==1){servomiddle.write(180);}else{servomiddle.write(0);}
  if(value[3]==1){servoring.write(180);}else{servoring.write(0);}
  if(value[4]==1){servopinky.write(180);}else{servopinky.write(0);}
  
  }
