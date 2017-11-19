#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <neotimer.h>
//10 minutes timer
Neotimer timer = Neotimer(600000);

int in1 = 7;
RCSwitch signalReciever = RCSwitch();
int onValue = 1111;
int offValue = 9999;
int relayOn = 0;
int debug = 1;
  
void setup() {
  //init relay pin
  pinMode(in1, OUTPUT);
  digitalWrite(in1, HIGH);

 
  Serial.begin(9600);

  //init FM receiver
  signalReciever.enableReceive(0);  // Receiver on inerrupt 0 =&gt; that is pin #2

  
}
 
void loop() {
  //if timer done, but the relay is still on, swtich the relay off
  if(timer.done() && relayOn==1){
    digitalWrite(in1, HIGH);
    relayOn = 0;
  }

  if (signalReciever.available()) {   
    int value = signalReciever.getReceivedValue();
//    Serial.println("Received:");
//    Serial.println(value);
//    Serial.println(relayOn);
//    
    if (value == offValue && relayOn ==1) {
      //switch relay off
      digitalWrite(in1, HIGH);
      relayOn = 0;
      timer.stop();
      Serial.println("Relay off");
      delay(3000);
      
    }
    if(value == onValue && relayOn==0)  {
      //switch relay on
       digitalWrite(in1, LOW);
       relayOn = 1;
       timer.start();
       Serial.println("Relay on");
       delay(3000);
    }
    signalReciever.resetAvailable();
  }
}
