
#include <IRremote.h>
#define IR_RECEIVE_PIN 11

#define IR_BUTTON_2 70
#define IR_BUTTON_3 71
#define IR_BUTTON_4 68
#define IR_BUTTON_5 64
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.begin(9600);
  if (IrReceiver.decode()) 
  {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    
    switch (command) 
    {
      case IR_BUTTON_2: 
      {
        digitalWrite(8,HIGH);
     
        delay(500);
        break;
      }
      case IR_BUTTON_3: 
      {
        digitalWrite(8,LOW);
       
        break;
      }
      case IR_BUTTON_4: 
      {
       digitalWrite(7,HIGH);
      
       delay(500);
        break;
      }
      case IR_BUTTON_5:
      {
        digitalWrite(7,LOW);
       
        break;
      }
      default: {
        Serial.println("Button not recognized");
      }
    }
  }
}
