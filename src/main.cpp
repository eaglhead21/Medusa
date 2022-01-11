#include <Arduino.h>
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 
#include <WiFi.h>
#include <HTTPClient.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Wire.h>

//Include all functional code in seperate header files
#include <global.h>
#include <sensors.h>
#include <debounce.h>
#include <medusaLCD.h>
#include <debug.h>
#include <httpSend.h>

void setup() {
  pinMode(buttonDownPin, INPUT);

  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  // Set Startup Screen
  lcd.setCursor(1,1);
  lcd.print("Welcome To Medusa");
  lcd.setCursor(8,2);
  lcd.print("2.0");
  lcd.setCursor(3,3);
  //lcd.print("By Craftchill");

//Look at the setup for these temp sensors and determine how it names each or addresses each
  sensors.begin(); //Ds18b20 initialise
  sensor1.begin(); //DHT Initialise
  sensor2.begin(); //DHT Initialise

 Serial.begin(115200); 
 Serial.println("Communication Started \n\n");  
 delay(1000);
  
 WiFi.mode(WIFI_STA);           
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
 Serial.print("Connecting to ");
 Serial.print(WIFI_SSID);
 while (WiFi.status() != WL_CONNECTED) 
 { Serial.print(".");
 delay(500); }

 Serial.println();
 Serial.print("Connected to ");
 Serial.println(WIFI_SSID);
 Serial.print("IP Address is : ");
 Serial.println(WiFi.localIP());    //print local IP address

 delay(30);
 }

void loop() { 

debounceCheckState();
if (hasChanged == true)
{
  medusaLCD();
}

if(millis() - previousMillis > interval) 
  {
    // save the last time we updated the data 
    previousMillis = millis();
    pressure(); //Read Pressure Sensor Values
    DHT_Temp(); //Read Temp1 and Temp2 Values
    DHT_Humidity(); // Read Humidity1 and Humidity2 Values
    DS_Temp(); // Read DS18B20 Temp3,4,5,6,7,8 Values
    Current_Sensor(); // Read the current sensor values
    httpClient(); //Send all Data to Database
    #ifdef DEBUG
    {
      debug();
    }
    #endif
  }
}
   