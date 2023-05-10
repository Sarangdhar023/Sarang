int A=9;
int B=5;
int speed;

int x;
int y;

char input;     // to store input character received via BT.

void setup()
{
  Serial.begin(9600);  
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  pinMode(A0,INPUT);
  pinMode(9, OUTPUT); 
  pinMode(5,OUTPUT); 
}

void loop()
{
  speed = analogRead(A0);
  speed = speed * 0.249;
  analogWrite(A,speed);
  analogWrite(B,speed);

  //speed = 255;
  while(Serial.available())
  {
    
    input = Serial.read();
    
    if(input == 'F')
    {
      forward();
    }

    else if (input == 'R')
    {
      right();  
    }

    else if (input == 'L')
    {
      left();
    }  

    else if (input == 'G')
    {
      backward();
    }  
    else if (input == 'S')
    {
      stop();
    }
 
  } 
}  
void forward()
  {
  digitalWrite(4, LOW	);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(4, LOW	);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backward()
  {
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void left()
  {
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void right()
  {
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}