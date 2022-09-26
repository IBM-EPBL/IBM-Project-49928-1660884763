// C++ code
//
int GasSensor = 0;

int TempSensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A5, INPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  TempSensor = (-40 + 0.488155 * (analogRead(A0) - 20));
  GasSensor = analogRead(A5);
  if (TempSensor < 20) {
    analogWrite(3, 80);
  } else {
    digitalWrite(3, LOW);
  }
  if (TempSensor > 25) {
    analogWrite(5, 80);
  } else {
    digitalWrite(5, LOW);
  }
  if (GasSensor > 350) {
    analogWrite(6, 80);
  } else {
    digitalWrite(6, LOW);
  }
  if (GasSensor > 600 && TempSensor > 40) {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    tone(7, 523, 300); // play tone 60 (C5 = 523 Hz)
    delay(1000); // Wait for 1000 millisecond(s)
  }
  Serial.print(GasSensor);
  Serial.print(", ");
  Serial.println(TempSensor);
}