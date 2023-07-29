#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3
#define t1 4
#define t2 5
#define t3 6
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C 

int smokeA0 = A3;
int temp = A2;
int rain = A1;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(t1,OUTPUT);
  pinMode(t2,OUTPUT);
  pinMode(t3,OUTPUT);
  pinMode(rain,INPUT);
  pinMode(temp,INPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(t1,LOW);
  digitalWrite(t2,LOW);
  digitalWrite(t3,LOW);
  
 
   display.clearDisplay();
       display.setTextSize(2);         
       display.setTextColor(WHITE);
      // display.setCursor(0, 10);
       display.setCursor(0, 10);
       display.print("System    initiated");
       display.display();
       delay(3000);
}

void loop() 
{

      
  int sensorThres = 400;
  int analogSensor = analogRead(smokeA0);
  if (analogSensor > sensorThres)
  {
    digitalWrite(t1,HIGH);
//    Serial.println(i);
        display.clearDisplay();
        //display.setTextSize(2);         
        //display.setTextColor(WHITE);
        display.setCursor(0, 10);
        display.print("Smoke     detected..");
        display.setCursor(0, 40);
        display.print("GAS       Leaking..");
        display.display();
        delay(3000);
        digitalWrite(t1,LOW);
         
   
  }
  int sensorValue1 = digitalRead(temp);
  if (sensorValue1 == LOW)
  {
    digitalWrite(t2,HIGH);
        //Serial.println(i);
        display.clearDisplay();
        //display.setTextSize(2);         
        //display.setTextColor(WHITE);
        display.setCursor(0, 10);
       
        display.print("Temp rise..");
        display.display();
        delay(3000);
        digitalWrite(t2,LOW); 
    
  }
  int sensorValue2 = digitalRead(A1);
  if (sensorValue2 == LOW)
  {
    digitalWrite(t3,HIGH);
    display.clearDisplay();
     //display.setTextSize(2);         
     //display.setTextColor(WHITE);
     display.setCursor(0, 10);
     display.print("Raining...");
     display.display();
     delay(3000);
     digitalWrite(t3,LOW); 
  }
  
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
   duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration/2) / 29.1;
  int new_delay= (distance *3) +30;
  if (distance < 50)
  {
   digitalWrite(10,HIGH);
   //delay(new_delay);
   delay(1000);
   digitalWrite(10,LOW);
   
   display.clearDisplay();
        //display.setTextSize(2);         
        //display.setTextColor(WHITE);
        display.setCursor(0, 10);
        display.print("Area      breached..");
        display.display();
        delay(3000);
  }
  else
  {
     digitalWrite(10,LOW);
    // Serial.println(i);
     display.clearDisplay();
     //display.setTextSize(1);         
    // display.setTextColor(WHITE);
     display.setCursor(0, 10);
     display.print("Perimeter secured..");
     display.display();
     delay(3000); 
  } 
}
