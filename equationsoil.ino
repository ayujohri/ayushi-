#include <Wire.h>
#include <LiquidCrystal.h>
#include <SD.h>
#include <SPI.h>
#include "RTClib.h"
File myFile;
RTC_DS1307 RTC;
LiquidCrystal lcd(10, 9, 8, 7, 6, 5);
int sensor_pin = A0;
int var;

int output_value=0 ;
int x=0,y=0;


void setup () {

  RTC.begin();
   Wire.begin();
  lcd.begin(20,4); 
    Serial.begin(9600);
     while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

 
  
  if (! RTC.isrunning()) {
    lcd.println("RTC is NOT running!");
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
    
    DateTime now = RTC.now();
   
    lcd.setCursor(0,0);
   lcd.print("DATE:");
     myFile.print("DATE:");
  lcd.print(now.year(), DEC);
     myFile.print(now.year(), DEC);
  lcd.print('/');
   myFile.print('/');
  lcd.print(now.month(), DEC);
  myFile.print(now.month(), DEC);
  lcd.print('/');
   myFile.print('/');
  lcd.print(now.day(), DEC);
   myFile.print(now.day(), DEC);
    lcd.print(' ');
      myFile.println(' ');
   // delay(1000);
    lcd.setCursor(0,1);
   lcd.print("TIME:");
  myFile.print("TIME:");
    lcd.print(now.hour(), DEC);
      myFile.print(now.hour(), DEC);
    lcd.print(':');
    myFile.print(':');
  lcd.print(now.minute(), DEC);
    myFile.print(now.minute(), DEC);
    lcd.print(':');
      myFile.print(':');
     lcd.print(now.second(), DEC);
    myFile.print(now.second(), DEC);
    lcd.print(' ');
        myFile.println(' ');
}
void loop () {
  
   myFile = SD.open("test.txt", FILE_WRITE);
output_value=0;
     lcd.clear();
    DateTime now = RTC.now();
    lcd.setCursor(0,0);
   lcd.print("DATE:");
     //myFile.print("DATE:");
  lcd.print(now.year(), DEC);
    // myFile.print(now.year(), DEC);
  lcd.print('/');
  // myFile.print('/');
  lcd.print(now.month(), DEC);
 // myFile.print(now.month(), DEC);
  lcd.print('/');
  // myFile.print('/');
  lcd.print(now.day(), DEC);
  // myFile.print(now.day(), DEC);
    lcd.print(' ');
      //myFile.println(' ');
   // delay(1000);
    lcd.setCursor(0,1);
   lcd.print("TIME:");
   //myFile.print("TIME:");
    lcd.print(now.hour(), DEC);
     // myFile.print(now.hour(), DEC);
    lcd.print(':');
   // myFile.print(':');
  lcd.print(now.minute(), DEC);
   // myFile.print(now.minute(), DEC);
    lcd.print(':');
    //  myFile.print(':');
     lcd.print(now.second(), DEC);
   // myFile.print(now.second(), DEC);
    lcd.print(' ');
      //  myFile.println(' ');
    
   //lcd.println();
   // delay(1000);
   
    for(int i=1;i<=10;i++)
  {
    var=analogRead(sensor_pin);
    output_value=output_value+var;
 //   lcd.println(output_value);


    //delay(100);
  }

 output_value=output_value/10;
 y=output_value;
 x=-((y-(1e+03))/26);

  
  // output_value = map(output_value,1023,0,0,100);
  lcd.setCursor(0,2);
   lcd.print("Mositure : ");
    //myFile.print("Mositure : ");

   //  myFile.println(now.minute());
   //lcd.print(output_value);
  // myFile.println(output_value);
  lcd.print(x);
  myFile.println(x);
  myFile.close();
  // lcd.println("%");

   delay(100);
}
  
