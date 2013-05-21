#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4); //set the LCD address to 0x3F for a 16 chars and 2 line display

#define trigPin 13
#define echoPin 12
#define redled 11
#define greenled 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
    lcd.init(); 
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Distance is: ");
    lcd.setCursor(17, 0);
    lcd.print("CM.");   
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
    int val;
    float temp;
    val=analogRead(0);
    temp=val/4.092;

    int dis;
    dis = int(distance);
    lcd.setCursor(13, 0);
    lcd.write(byte(0x30+dis/100));
    lcd.write(byte(0x30+(dis%100)/10));
    lcd.write(byte(0x30+(dis%10)));    
    //lcd.write(byte(0x30+dis%100));    
    //lcd.write(byte(0x30+dis/100));    
    delay(1000);  

  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(redled,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(greenled,LOW);
}
  else {
    digitalWrite(redled,LOW);
    digitalWrite(greenled,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");

  }
  delay(500);
}


