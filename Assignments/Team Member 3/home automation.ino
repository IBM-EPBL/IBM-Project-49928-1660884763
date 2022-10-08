#include <Servo.h>
Servo myservo;
int led=3;
int pir=8;
int redLed = 13;
int greenLed = 11;
int orngeLed = 12;
int gasbuzzer = 4;
int concen = A1;
int buttonState = 0;

void setup()
{
   
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(orngeLed, OUTPUT);
  pinMode(gasbuzzer, OUTPUT);
  pinMode(concen, INPUT);
  pinMode(2, INPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  pinMode(pir,INPUT);
  pinMode(led,OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
  delay(500);
}

void loop()
{
  int val = digitalRead(pir);
  
  Serial.println("");
  if(val==HIGH)
  {
    digitalWrite(led,HIGH);
    Serial.println("Motion detected");
    myservo.write(70);
  }
  else
  {
    digitalWrite(led,LOW);
    myservo.write(10);
  }
  delay(10);
  
  buttonState = digitalRead(2);
  if (buttonState == LOW) 
  {
    digitalWrite(10, HIGH);
  } 
  else 
  {
    digitalWrite(10, LOW);
  }
  delay(10);
  
  
  //Temperature Sensor
  float temp = -40 + 0.488155 * (analogRead(A0) - 20);
  Serial.print("Temperature: ");
  Serial.println(temp);
  if (-40 + 0.488155 * (analogRead(A0) - 20) > 30)
  {
    digitalWrite(5, HIGH);
  } 
  else 
  {
    digitalWrite(5, LOW);
  }
  delay(10);
  
  //For Gas Sensor
  int smok = analogRead(concen);

  Serial.print("Gas Conc. Level: ");
  Serial.println(smok);
  // Checks if it has reached the threshold value
  if (smok > 682 && smok < 750)
  {
    digitalWrite(orngeLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    tone(gasbuzzer, 3000, 200);
  }
  else if(smok > 750)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(orngeLed, LOW);
    tone(gasbuzzer, 1000, 200);
  }
   
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(orngeLed, LOW);
    noTone(gasbuzzer);
  }
  delay(150);
}