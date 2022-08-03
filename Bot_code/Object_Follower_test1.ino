//Object follower bot test 1
const int trigPin = 1;
const int echoPin = 2;

const int RightIR = 9;
const int LeftIR = 10;

const int RMF = 3;
const int RMB = 4;
const int LMF = 5;
const int LMB = 6;

float duration;
int distance;

void setup()
{
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);

  pinMode(RightIR, INPUT);
  pinMode(LeftIR, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, HIGH);
  delay(2);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034 / 2);
  Serial.print("Distance: ");
  Serial.println(distance);

  int Right_Value = digitalRead(RightIR);
  int Left_Value = digitalRead(LeftIR);

  Serial.print("RIGHT");
  Serial.println(Right_Value);
  Serial.print("LEFT");
  Serial.println(Left_Value);

  //MoveForward
  if ((Right_Value == LOW)&& (distance>=5 && distance<=30) && (Left_Value == LOW))
  {
    //if (distance >= 5 && distance <= 30)
   // {
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
   // }
  }
  //delay(3);
  //  Right Turn
  if ((Right_Value == LOW) && (Left_Value == HIGH))
  {
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, HIGH);
    digitalWrite(LMF, HIGH);
    digitalWrite(LMB, LOW);
  }
  //delay(3);
  // Left Turn
  if ((Right_Value == HIGH) && (Left_Value == LOW))
  {
    digitalWrite(RMF, HIGH);
    digitalWrite(RMB, LOW);
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, HIGH);
  }
  //delay(3);
  //stop
  // else if(distance > 1 && distance < 10)
  if (distance < 5)
  {
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, LOW);
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, LOW);
  }

}
