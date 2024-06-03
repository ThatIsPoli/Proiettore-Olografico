#include <IRremote.h>
#define IR_RECV_PIN 2

void setup() {
  IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK);
  Serial.begin(9600);
  Serial.println("READY");
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  
  if(IrReceiver.decode()){
    unsigned long keycode = IrReceiver.decodedIRData.command;
    
      
    
    if(keycode == 68){
      digitalWrite(7, HIGH);
      delay(100);
      digitalWrite(7, LOW);
      Serial.println("4");
      
    }
    if(keycode == 67){
      digitalWrite(8, HIGH);
      delay(100);
      digitalWrite(8, LOW);
      Serial.println("6");
      
    }
    if(keycode == 69){
      digitalWrite(8, HIGH);
      digitalWrite(7, HIGH);
      delay(1000);
      digitalWrite(8, LOW);
      digitalWrite(7, LOW);
      Serial.println("1");
    }
    IrReceiver.resume();
  }
  
}

