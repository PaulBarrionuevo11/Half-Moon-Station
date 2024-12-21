#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DS3231.h>
#include <SPI.h>
#include <SD.h>

// DHT Sensor Configuration
#define DHTPIN 4         // GPIO pin connected to DHT sensor
#define DHTTYPE DHT22    // DHT sensor type (DHT22)

// LED Configuration
#define LED_PIN 2        // General status LED
#define RED_LED 15       // LED for cold temperatures
#define BLUE_LED 19      // LED for hot temperatures

// SD Card Configuration
const int chipSelect = 10; // Chip Select pin for SD module

// String messages for temperature ranges
String dataCold = "Temperature below 17°C";
String dataHot = "Temperature above 20°C";

// LCD Configuration
LiquidCrystal_I2C lcd(0x27, 20, 4); // 20x4 LCD
DHT dht(DHTPIN, DHTTYPE);           // Initialize DHT sensor
RTClib myRTC;                       // Real-Time Clock (RTC)

// Function to log data to SD card
void logDataToSD(const String &message, float temperature, float humidity, DateTime now) {
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
    dataFile.print("°C, Humid = ");
    dataFile.print(humidity);
    dataFile.println("%");
    dataFile.close();

    // Log success to Serial Monitor
    Serial.println("Data logged: " + message);
  } else {
    // Handle file error
    Serial.println("Error opening datalog.txt");
  }
}

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  Serial.println("DHT sensor with LCD and SD card example");

  // Initialize LEDs
  pinMode(LED_PIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  // Initialize DHT sensor
  dht.begin();

  // Initialize I2C and LCD
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);

// 
}

void loop() {
  // Get current time
  DateTime now = myRTC.now();

  // Read temperature and humidity
  float temperature = dht.readTemperature();    // Celsius
  float humidity = dht.readHumidity();

//  // Check for sensor errors
//  if (isnan(temperature) || isnan(humidity)) {
//    Serial.println("Failed to read from DHT sensor!");
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.print("Sensor Error!");
//    delay(2000);
//    return;
//  }

  // Display values on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humidity);
  lcd.print(" %");

//  lcd.setCursor(0, 2);
//  lcd.print("Date: ");
//  lcd.print(now.year());
//  lcd.print('/');
//  lcd.print(now.month());
//  lcd.print('/');
//  lcd.print(now.day());
//
  lcd.setCursor(0, 2);
  lcd.print("Time: ");
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());

  // LED indicators and SD card logging
  if (temperature < 17.0) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW); // Turn off the other LED
    logDataToSD(dataCold, temperature, humidity, now);
  } else if (temperature > 20.0) {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(RED_LED, LOW); // Turn off the other LED
    logDataToSD(dataHot, temperature, humidity, now);
  }

//  // Blink status LED
//  digitalWrite(LED_PIN, HIGH);
//  delay(500);
//  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
