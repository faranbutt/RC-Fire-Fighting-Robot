double ch1=2;
int a=4; int b=5;
 
double ch2=3;
int c=6; int d=7;
int FlamePin = 11;
int buzzer = 8 ;
int M1 = 12;
int M2=13;
int isFlame;
void setup()
{
  Serial.begin(9600);
  
  pinMode(2,INPUT);
  pinMode(4,OUTPUT); pinMode(5,OUTPUT);
  
  pinMode(3,INPUT);
  pinMode(6,OUTPUT); pinMode(7,OUTPUT);
  pinMode(FlamePin, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop()
{
ch1 = pulseIn(2,HIGH);
ch2 = pulseIn(3,HIGH);
//Serial.println(ch1);
//Serial.println(ch2);
//delay(5000);
isFlame = digitalRead(FlamePin);
if((ch1==0)&&(ch2==0))
{     
 digitalWrite(a,LOW); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,LOW);
}

else if((ch1>1530)&&(ch2>1530))
{     
digitalWrite(a,HIGH); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,HIGH);    
}

else if((ch1>1530)&&(ch2<1460))
{ 
   digitalWrite(a,HIGH); digitalWrite(b,LOW);
 digitalWrite(c,HIGH);digitalWrite(d,LOW);    

}

else if((ch1<1460)&&(ch2>1530))
{     
  digitalWrite(a,LOW); digitalWrite(b,HIGH);
 digitalWrite(c,LOW);digitalWrite(d,HIGH);
}

else if((ch1<1460)&&(ch2<1460))
{  digitalWrite(a,LOW); digitalWrite(b,HIGH);
 digitalWrite(c,HIGH);digitalWrite(d,LOW);
  

}

else
{     
 digitalWrite(a,LOW); digitalWrite(b,LOW);
 digitalWrite(c,LOW);digitalWrite(d,LOW);
}

if (isFlame== 1)  //if it is low
  {
    Serial.println("FLAME, FLAME, FLAME");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, LOW);
    digitalWrite(buzzer,HIGH);//Print Flame Flame
                                           //LED on
  }
else                           //if not
  {                               
    Serial.println("no flame"); //print no  flame
    digitalWrite(M1,LOW);
    digitalWrite(buzzer, LOW);
    //off the LED
  }
}
