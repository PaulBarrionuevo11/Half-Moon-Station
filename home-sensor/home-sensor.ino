#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4); // 20x4 LCD
#include "RTClib.h"
RTC_DS3231 rtc;

#include <SPI.h>
#include <SD.h>


// SD Card Configuration
const int chipSelect = 27; // Chip Select pin for SD module
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

/******* Function to log data to SD card ******/
void logDataToSD(const String &message, float temperature, DateTime now) {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    // Log timestamp, temperature, and humidity
    dataFile.print(now.year());
    dataFile.print('/');
    dataFile.print(now.month());
    dataFile.print('/');
    dataFile.print(now.day());
    dataFile.print(" ");
    dataFile.print(now.hour());
    dataFile.print(':');
    dataFile.print(now.minute());
    dataFile.print(':');
    dataFile.print(now.second());
    dataFile.print(" - ");
    dataFile.print(message);
    dataFile.print(": Temp = ");
    dataFile.print(temperature);

    dataFile.close();

    // Log success to Serial Monitor
    Serial.println("Data logged: " + message);
  } else {
    // Handle file error
    Serial.println("Error opening datalog.txt");
  }
}

void setup () {
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

}

void loop () {
    DateTime now = rtc.now();

    lcd.setCursor(7, 0);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
//    lcd.print(':');
//    lcd.print(now.second(), DEC);
    lcd.setCursor(0, 1);        
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    
    lcd.print(' ');
    lcd.print(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
//    // calculate a date which is 7 days, 12 hours, 30 minutes, 6 seconds into the future
//    DateTime future (now + TimeSpan(7,12,30,6));

    float temperature = rtc.getTemperature();
    lcd.setCursor(0, 2);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print(" C");

  if (temperature < 17.0) {
    logDataToSD("too cold", temperature, now);
  } else if (temperature > 20.0) {
    logDataToSD("too hot", temperature, now);
  }
    delay(23000);
}
