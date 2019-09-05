/*
Code by: www.munphurid.com
Syed Rafay Hashmi and Wardah Arshad

This is a code for Line following Robot

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-Motor driver module L298N
-Munphurid Chassis MN CS01 (Light weight 3 wheeler chassis can also be used)
-4 IR Sensor
-7V to 12V battery
-10 male to female wires

Connections:
Motor driver module and Arduino
-Connect IN1 to pin 8 of Arduino
-Connect IN2 to pin 13 of Arduino
-Connect IN3 to pin 9 of Arduino
-Connect IN4 to pin 6 of Arduino
-Connect ENA to pin 2 of Arduino
-Connect ENB to pin 7 of Arduino
-Connect 5V of module to 5V of Arduino
-Connect GND of module to GND of Arduino


IR sensor and Arduino
-Connect OUT of IR sensor to pin 13,2,3,4 of Arduino respectively
-Connect VCC of IR sensor to 5V of Arduino
-Connect GND of IR sensor to GND of Arduino

Motors
Connect motors to motor driver module

Battery and all circuits
-Connect +ve wire of battery to 12V of motor driver module
-Connect -ve wire of battery to GND of motor driver module
*/

void forward();       //Forward Function
void right();         // Right Function
void left();          // Left Function
void halt();          //Stop Function

int ENA=9;            //Connect pin of ENA to pin 9
int ENB=10;            //Connect pin of ENB to pin 10

int IN1=5;            //Connect pin of IN1 to pin 5
int IN2=6;            //Connect pin of IN2 to pin 6
int IN3=7;            //Connect pin of IN3 to pin 7
int IN4=8;            //Connect pin of IN4 to pin 8

int ir1,ir2,ir3,ir4;  //defining Variables for IR Sensor

int leftir1 =13;      //MOST LEFT IR SENSOR
int leftir2=2;        // MIDDLE LEFT IR SENSOR
int rightir1=3;       // MIDDLE RIGHT IR SENSOR
int rightir2=4;       // MOST RIGHT IR SENSOR

void forward()        //Forward Function
{
  analogWrite(ENA,200);  
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  analogWrite(ENB,200);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);


}
void right()          // Right Function
{
   analogWrite(ENA,180);
   digitalWrite(IN1,HIGH);
   digitalWrite(IN2,LOW);
   analogWrite(ENB,180);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,HIGH);
}
void left()           // Left Function
{
    analogWrite(ENB,180);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    analogWrite(ENA,180);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);


}

 void halt()          // Stop Function
 {
   analogWrite(ENB,0);
   digitalWrite(IN3,LOW);
   digitalWrite(IN4,LOW);
   analogWrite(ENA,0);
   digitalWrite(IN1,LOW);
   digitalWrite(IN2,LOW); 
 }






void setup() {
  Serial.begin(9600);
  pinMode(leftir1,INPUT);
  pinMode(leftir2,INPUT);
  pinMode(rightir1,INPUT);
  pinMode(rightir2,INPUT);
  
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);

}

void loop() {
  ir1=digitalRead(leftir1);
  ir2=digitalRead(leftir2);
  ir3=digitalRead(rightir1);
  ir4=digitalRead(rightir2);
  
  Serial.println(ir1);
  Serial.println("\t");
  Serial.println(ir2);
  Serial.println("\t");
  Serial.println(ir3);
  Serial.println("\t");
  Serial.println(ir4);
  

if(ir1==0 && ir2==1 && ir3==1 && ir4==0)
{
  forward();
  delay(75);
  halt();
}
else if(ir1==1 && ir2==1 && ir3==1 && ir4==0)
{
  left();
  delay(50);
  halt();
}
else if(ir1==1 && ir2==0 && ir3==0 && ir4==0)
{
  left();
  delay(75);
  halt();
}
else if(ir1==1 && ir2==1 && ir3==0 && ir4==0)
{
  left();
  delay(50);
  halt();
}
else if(ir1==1 && ir2==1 && ir3==1 && ir4==0)
{
  forward();
  delay(75);
  halt();
}
else if(ir1==0 && ir2==0 && ir3==0 && ir4==1)
{
  right();
  delay(75);
  halt();
}
else if(ir1==0 && ir2==0 && ir3==1 && ir4==1)
{
  right();
  delay(50);
  halt();
}
else if(ir1==0 && ir2==1 && ir3==1 && ir4==1)
{
  forward();
  delay(75);
  halt();
}
else if(ir1==0 && ir2==1 && ir3==0 && ir4==0)
{
  forward();
  delay(75);
  halt();
}
else if(ir1==0 && ir2==0 && ir3==1 && ir4==0)
{
  forward();
  delay(75);
  halt();
}

else if(ir1==0 && ir2==0 && ir3==0 && ir4==0)
{
  left();
  delay(100);
  right();
  delay(100);
  halt();
}
else if(ir1==1 && ir2==1 && ir3==1 && ir4==1)
{
  right();
  delay(100);
  left();
  delay(100);
  halt();  
}
else if(ir1==1 && ir2==0 && ir3==1 && ir4==0)
{
  left();
  delay(100);
  halt();
}
else if(ir1==1 && ir2==0 && ir3==1 && ir4==1)
{
  left();
  delay(100);
  halt();
}
else if(ir1==1 && ir2==0 && ir3==0 && ir4==1)
{
  left();
  delay(100);
  halt();
}
else if(ir1==1 && ir2==1 && ir3==0 && ir4==1)
{
  right();
  delay(100);
  halt();
}

delay(50);
}
