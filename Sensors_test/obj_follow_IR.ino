//Object Following Robot using IR sensor
const int RightIR = 9;
const int LeftIR = 10;

const int RMF = 3;
const int RMB = 4;
const int LMF = 5;
const int LMB = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);
  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);

  pinMode(RightIR, INPUT);
  pinMode(LeftIR, INPUT);
}
void loop()
{
  int Right_Value = digitalRead(RightIR);
  int Left_Value = digitalRead(LeftIR);

  Serial.print("RIGHT");
  Serial.println(Right_Value);
  Serial.print("LEFT");
  Serial.println(Left_Value);

  //Moveforward
  if ((Right_Value == 0) && (Left_Value == 0) )
  {
    digitalWrite(RMF, HIGH);
    digitalWrite(RMB, LOW);
    digitalWrite(LMF, HIGH);
    digitalWrite(LMB, LOW);
  }

  //Left turn
  if ((Right_Value == 1) && (Left_Value == 0))
  {
    digitalWrite(RMF, HIGH);
    digitalWrite(RMB, LOW);
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, HIGH);
  }

  //Right turn
  if ((Right_Value == 0) && (Left_Value == 1))
  {
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, HIGH);
    digitalWrite(LMF, HIGH);
    digitalWrite(LMB, LOW);
  }

  //stop bot
  if ((Right_Value == 1) && (Left_Value == 1))
  {
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, LOW);
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, LOW);
  }
}
