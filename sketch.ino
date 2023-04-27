#include <Servo.h>
Servo myservo;
int pos=0;
int ledPin=12;
int inputPin=2;
int pirState=LOW;
int val=0;
int buzzer = 10;
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(inputPin, INPUT);   
  myservo.attach(9);  
 pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  val = digitalRead(inputPin);  
  if (val == HIGH) {            
    digitalWrite(ledPin, HIGH);  
    tone(buzzer, 1000); 
    if (pirState == LOW) {
      
      pirState = HIGH;
      Serial.println("Motion detected!");
      for (pos = 0; pos <= 180; pos += 1) { 
    
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);              
    delay(15);                       
  }
    }
  } else {
    digitalWrite(ledPin, LOW); 
    if (pirState == HIGH){
      
      pirState = LOW;
      Serial.println("Motion ended!");
    }
  }
  
  delay(1000);        
  noTone(buzzer);     
  delay(1000); 
}
