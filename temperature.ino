#include <Servo.h>



// C++ code
//

#define temperature A0
#define ledIndictor 2
# define servoPin 3

Servo mainServo;
int position =0;
int previousPosition;
void setup()
{
  pinMode(A0,INPUT);
  pinMode(2, OUTPUT);
  mainServo.attach(3);
  Serial.begin(9600);
  
}

void loop()
{
 int tempReading = analogRead(A0);
    float voltage = tempReading * 5.0;
  voltage /=1024.0;
    float tempC = (voltage - 0.5) *100 ;
  int position = map(tempC,0,30,0,90);
  if(previousPosition != position){
    Serial.println("New position: ");
    Serial.print(position);
   
    mainServo.write(position);
    digitalWrite(2,HIGH);
    delay(1000);
}
  digitalWrite(2,HIGH);
}