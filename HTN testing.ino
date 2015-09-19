
// character LCD example code
// www.hacktronics.com

#include <LiquidCrystal.h>
#include "SparkFunHTU21D.h"
#include <Wire.h>

HTU21D data;
// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13;    // pin 13 will control the backlight

void setup()
{
  Serial.begin(9600);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16,2);              // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();                  // start with a blank screen
  lcd.setCursor(1,0);           // set cursor to column 0, row 0 (the first row)
  
  // print data
  lcd.print("Smart Shovel");
  delay(1000);
  lcd.print("Starting data printing");
  
  data.begin();
 
}

void loop()
{
  int temperature = data.readTemperature();
  int humidity = data.readHumidity();
  delay(1000);
   lcd.print("Temperature: " + temperature);
   delay(5000);
   lcd.print("Humidity: " +  humidity);
   delay(5000);
}
