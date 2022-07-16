//Object follower bot test 1
const int trigPin = 11;
const int echoPin = 12;

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
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin,HIGH);
  delay(2);
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin,HIGH);
  distance = (duration*0.034/2);
  Serial.print("Distance: ");
  Serial.println(distance);

  int Right_Value = digitalRead(RightIR);
  int Left_Value = digitalRead(LeftIR);

  Serial.print("RIGHT");
  Serial.println(Right_Value);
  Serial.print("LEFT");
  Serial.println(Left_Value);

//Move forward
  if ((Right_Value == LOW) && (Left_Value == LOW) && (distance<=50))
  {
    if(distance>10)
    move_forward();
  }
 
//Right turn
  if ((Right_Value == LOW) && (Left_Value == HIGH))
  right_turn();
  delay(10);
  
//Left turn
  if ((Right_Value == HIGH) && (Left_Value == LOW))
  left_turn();
  delay(10);

//Move backward
  if ((Right_Value == HIGH) && (Left_Value == HIGH))
  {
    if(distance == 10)
    Stop_bot();

    else if(distance<10)
    move_back();
  }

}


//Move forward function
void move_forward()
{
  digitalWrite(RMF,HIGH);
  digitalWrite(RMB,LOW);
  digitalWrite(LMF,HIGH);
  digitalWrite(LMB,LOW); 
}

//turn right function
void right_turn()
{
  digitalWrite(RMF,LOW);
  digitalWrite(RMB,HIGH);
  digitalWrite(LMF,HIGH);
  digitalWrite(LMB,LOW);
}

//turn left function
void left_turn()
{
  digitalWrite(RMF,HIGH);
  digitalWrite(RMB,LOW);
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,HIGH);
}

//Move backward function
void move_back()
{
  digitalWrite(RMF,LOW);
  digitalWrite(RMB,HIGH);
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,HIGH);
}

//stop function
void Stop_bot()
{
  digitalWrite(RMF,LOW);
  digitalWrite(RMB,LOW);
  digitalWrite(LMF,LOW);
  digitalWrite(LMB,LOW);
}
