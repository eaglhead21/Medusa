#include <Arduino.h>
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 
#include <WiFi.h>
#include <HTTPClient.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Wire.h>

//OTA Function
#include <AsyncElegantOTA.h>

//Include all functional code in seperate header files
#include <global.h>
#include <sensors.h>
#include <debounce.h>
#include <medusaLCD.h>
#include <debug.h>
#include <httpSend.h>
#include <timer.h>
#include <loPressureLUT.h>
#include <hiPressureLUT.h>
#include <superSub.h>

AsyncWebServer server(80);

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
  lcd.print("By Craftchill");

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

 server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) 
  {
    request->send(200, "text/plain", "Hi! I am ESP32 Uploaded via OTA.");
  });

  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();
  Serial.println("HTTP server started");

 delay(30);
 }

void loop() 
{ 
  debounceCheckState();
  if (hasChanged == true)
  {
    medusaLCD();
  }

  if(millis() - previousHTTPMillis > httpInterval)
  {
    previousHTTPMillis = millis();
    httpClient(); //Send all Data to Database
  }

  if(millis() - previousSensorMillis > sensorInterval) 
  {
    // save the last time we updated the data 
    previousSensorMillis = millis();
    pressure(); //Read Pressure Sensor Values
    loPressureLUT(); // LUT to map low pressure values to Temperature in Celsius
    hiPressureLUT(); // LUT to map hi pressure values to Temperature in Celsius
    superSubCalc(); // Calculate the Superheat and Subcooling values and check if in range
    DHT_Temp(); //Read Temp1 and Temp2 Values
    DHT_Humidity(); // Read Humidity1 and Humidity2 Values
    DS_Temp(); // Read DS18B20 Temp3,4,5,6,7,8 Values
    Current_Sensor(); // Read the current sensor values
    medusaLCD(); // Refresh the screen with new data

    #ifdef SENSOR
    {
      timerStart();
    }
    #endif

    #ifdef SENSOR
    {
        timeStop();
        Serial.print("Time inside http Client Loop = ");
        Serial.print(timeInterval);
        Serial.print("\n");
    }
    #endif

    #ifdef DEBUG
    {
      debug();
    }
    #endif
  }
}
   