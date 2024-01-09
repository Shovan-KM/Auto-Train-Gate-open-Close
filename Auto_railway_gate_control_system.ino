#include <Servo.h>
Servo myservo; 
const int trigPin = 9;
const int echoPin = 8;
#define led 4
#define led1 5
#define buzzer 11
int sound = 250;
void setup() 
{
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(buzzer, OUTPUT);

myservo.attach(10);
}
void loop()

{

long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance < 5)

{
myservo.write(120);
digitalWrite(led,HIGH);
digitalWrite(led1,LOW);
sound = 250;
}

else
{
myservo.write(0);
digitalWrite(led,LOW);
digitalWrite(led1,HIGH);


}

if (distance > 60 || distance <= 0)

{

Serial.println("The distance is more than 60");

}

else

{

Serial.print(distance);

Serial.println(" cm");

}

delay(500);

}

