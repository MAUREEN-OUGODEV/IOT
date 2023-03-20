// C++ code
//
int distanceThershold=0;
int cm=0;
int inches =0 ;

 long readUltrasonicDistance(int triggerPin, int echoPin){
  pinMode( triggerPin,OUTPUT);//clears the trigger
  digitalWrite(triggerPin,LOW);
  delay(2000);
  pinMode(triggerPin,OUTPUT);//set trigger pin to high state
  digitalWrite(triggerPin,HIGH);
  delay(10000);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin,LOW);
  return pulseIn(echoPin,HIGH);
  
}

void setup()
{
  Serial.begin(9600);
  
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  distanceThershold = 350;
   cm = 0.01723 * readUltrasonicDistance(7,6);
   inches=(cm/2.54);
    Serial.print(cm);
    Serial.print("cm, ");
    Serial.print(inches);
    Serial.println("in");
      
      if(cm < distanceThershold){
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
        
      }
      
      if(cm < distanceThershold && cm > distanceThershold-100){
        
      digitalWrite(3,HIGH);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
        
      }
        
    if(cm < distanceThershold -100 && cm > distanceThershold-250){
        
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,LOW);
      
    }
      if(cm < distanceThershold-250 && cm > distanceThershold-300){
        
      digitalWrite(3,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(5,HIGH);
      }
   delay(100);


}
