const int trigPin = 11 ;
const int echoPin = 12;

const int RMF = 3;
const int RMB = 4;
const int LMF = 5;
const int LMB = 6;

long duration; 
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode (RMF, OUTPUT);
  pinMode (RMB, OUTPUT);
  pinMode (LMF, OUTPUT);
  pinMode (LMB, OUTPUT);

  Serial.begin(9600);
}


void loop()
{     
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*0.034/2);
  //Serial.print("Distance: ");
  //Serial.println(distance);
 
  if(distance<40)
    { 
      Serial.print("Distance: ");
      Serial.println(distance);
  
      digitalWrite(RMF, HIGH); 
      digitalWrite(RMB, LOW); 
      digitalWrite(LMF, HIGH); 
      digitalWrite(LMB, LOW);
      delay(1200);
    }
    
  else
    {
      digitalWrite(RMF, LOW); 
      digitalWrite(RMB, LOW); 
      digitalWrite(LMF, LOW); 
      digitalWrite(LMB, LOW);
    }  
  delay(0);
}
