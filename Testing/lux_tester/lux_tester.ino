// NTP Code from MoThunderz: https://www.youtube.com/watch?app=desktop&v=0AlATlN95Y0

#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <LittleFS.h>
#include <SPI.h>


#define UTC_OFFSET_IN_SECONDS -25200  // offset from greenwich time
/* You can also manually set the gain or enable auto-gain support */
// tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
// tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */

/* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
// tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
// tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */





char daysOfWeek[7][12] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

// Define NTP client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "us.pool.ntp.org", UTC_OFFSET_IN_SECONDS, 6000);

void setup(){
Serial.begin(9600);
  timeClient.begin();

  // Optional: Check if file exists and create if not
}

void loop() {
  timeClient.update();
  Serial.println(daysOfWeek[timeClient.getDay()]);
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());


}
