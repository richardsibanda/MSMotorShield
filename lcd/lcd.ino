#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4); //set the LCD address to 0x3F for a 16 chars and 2 line display

void setup()
{
    lcd.init(); 
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Hello World!");
    lcd.setCursor(0, 1);
    lcd.print("This is Jing.");
    lcd.setCursor(0, 2);
    lcd.print("I am in.");
    lcd.setCursor(0, 3);
    lcd.print("Thank you!");    
}
void loop()
{
    int val;
    float temp;
    val=analogRead(0);
    temp=val/4.092;
    val=(int)temp;//
    lcd.setCursor(16, 1);
    //lcd.print(0x30+val/100,BYTE); 
    lcd.write(byte(0x30+val/100));
    //lcd.print(0x30+(val%100)/10,BYTE); 
    lcd.write(byte(0x30+(val%100)/10));
    lcd.print('.');
    //lcd.print(0x30+val%10,BYTE);
    lcd.write(byte(0x30+val%10));
    delay(1000);
    
}
