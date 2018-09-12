int l1 = 8;
int l2 = 9;
int m1a = 10;
int m1b = 11;
int m2a = 12;
int m2b = 13;
char value;

void setup()
{ 
pinMode(l1, OUTPUT);   // Digital pin 8 set as output Pin
pinMode(l2, OUTPUT);   // Digital pin 9 set as output Pin
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 13 set as output Pin
Serial.begin(9600);
}

void loop()
{
  while (Serial.available() > 0)
  {
  valueue = Serial.read();
  Serial.println(value);
  }


  if( valueue == 'F') // Forward
    {
      digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);
    }
  else if(value == 'B') // Backward
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
    }
 
    else if(value == 'L') //Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
    else if(value == 'R') //Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
   
  else if(value == 'S') //Stop
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(value == 'I') //Forward Right
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
  else if(value == 'J') //Backward Right
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, HIGH);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    }
   else if(value == 'G') //Forward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }
  else if(value == 'H') //Backward Left
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, HIGH);
    }
   else if( value == 'W' ) // Lights on
    {
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
    }
   else if( value == 'w' ) // Lights off
    {
    digitalWrite(l1,LOW);
    digitalWrite(l2 ,LOW);
    }
      
}

