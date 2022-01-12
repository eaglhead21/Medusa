#pragma once
// Define all the Global Variables of the Code Base below
#include <LiquidCrystal_I2C.h> 
#include <WiFi.h>

//WiFI Declarations
#define HOST "gingerwallop.com"  // Enter HOST URL without "http:// "  and "/" at the end of URL
#define WIFI_SSID "Redpoint"     // WIFI SSID here                                   
#define WIFI_PASSWORD "ilovefreebeer"  // WIFI password here
//#define DEBUG;
#define SENSOR ;  

WiFiClient client;

//LCD Config I2C Address and 20 lines 4 tall
LiquidCrystal_I2C lcd(0x27, 20, 4);  

//Page Scrolling
int WhichScreen =0;   // This variable stores the current Screen number
bool hasChanged = true;
const int buttonDownPin = 16;    // the number of the pushbutton pin
const int buttonUpPin = 17;     // push button menu up pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//Pressure Sensor pin connection defintions
const int loPressurePin = 36;
const int hiPressurePin = 39;

//Current Sensor
const int currentSensorPin = 34;

//On/Off Remote Relay
const int remoteRelayPin = 13;

// Declare global variables which will be uploaded to server
String sendtemp1, sendtemp2, sendtemp3, sendtemp4, sendtemp5, sendtemp6, sendtemp7, sendtemp8, sendhum1, sendhum2, postData;

//Declare other global variables used
//Debounce
unsigned long prevTime1 = millis();

//Define timing for loops
// the following variables are a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long previousMillis = 0;        // will store last period time was updated
long interval = 10000;           // interval at which to blink (milliseconds)

long timeStart = millis();
long timeInterval = 0; 



