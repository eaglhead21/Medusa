// Outside Library Includes
#include <Arduino.h>
#include <LiquidCrystal_I2C.h> 
#include <DHT.h> 
#include <WiFi.h>
#include <HTTPClient.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Wire.h>
#include <AsyncElegantOTA.h>
#include <Arduino_JSON.h>

//Include all internally created functional code in seperate header files
#include <global.h>
#include <sensors.h>
#include <medusaLCD.h>
#include <debug.h>
#include <httpSend.h>
#include <loPressureLUT.h>
#include <hiPressureLUT.h>
#include <superSub.h>
#include <internet.h>
#include <remote_control.h>
//#include <debounce.h>

AsyncWebServer server(80);

void setup() {
  pinMode(buttonDownPin, INPUT);
  pinMode(remoteRelayPin, OUTPUT);
  pinMode(currentSensorPin, INPUT);
  //digitalWrite(remoteRelayPin, HIGH);

  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

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
 { 
  // Set Startup Screen and WiFi Connecting Info
  lcd.setCursor(0,1);
  lcd.print("Craftchill's Medusa");
  lcd.setCursor(0,2);
  lcd.print("Connecting...");
  Serial.print(".");
  delay(500); 
}

 Serial.println();
 Serial.print("Connected to ");
 Serial.println(WIFI_SSID);
 Serial.print("IP Address is : ");
 Serial.println(WiFi.localIP());    //print local IP address
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Craftchill's Medusa");
  lcd.setCursor(0,1);
  lcd.print("Connected!");
  lcd.setCursor(0,2); // Column, line
  lcd.print("SSID: ");
  lcd.setCursor(7,2); // Column, line
  lcd.print(WIFI_SSID);

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
  if (digitalRead(buttonDownPin) == true)
  {
    hasChanged == true;
    WhichScreen++;
    medusaLCD();
  }
  else 
  {
    hasChanged == false;
  }

  if(millis() - previousHTTPMillis > screenInterval)
  {
    previousScreenMillis = millis();
    medusaLCD(); // Refresh the screen with new data
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
    remoteControl(); // Check for remote bit toggle
    
    #ifdef DEBUG
    {
      debug();
    }
    #endif
  }
  wifiCheck();
}
   