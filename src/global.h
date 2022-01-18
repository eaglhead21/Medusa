#pragma once
// Define all the Global Variables of the Code Base below
#include <LiquidCrystal_I2C.h> 
#include <WiFi.h>

//WiFI Declarations
#define HOST "gingerwallop.com"  // Enter HOST URL without "http:// "  and "/" at the end of URL
#define WIFI_SSID "Redpoint"     // WIFI SSID here                                   
#define WIFI_PASSWORD "ilovefreebeer"  // WIFI password here
//#define DEBUG ;
//#define SENSOR ;  

WiFiClient client;

//LCD Config I2C Address and 20 lines 4 tall
LiquidCrystal_I2C lcd(0x27, 20, 4);  

//Page Scrolling
int WhichScreen =0;   // This variable stores the current Screen number
bool hasChanged = true;
const int buttonDownPin = 23;    // the number of the pushbutton pin
//const int buttonUpPin = 17;     // push button menu up pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//Pressure Sensor pin connection defintions
const int loPressurePin = 36;
const int hiPressurePin = 39;

//Pressure Sensor Variable Defintions
double loPressureValue;
double hiPressureValue;

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
long interval = 10000;           // interval at which to sample the data

long timeStart = millis();
long timeInterval = 0; 

//Used for LUT variable
//Array Declaration (PSIG)
const int PSIG [ ] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 
    36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 
    70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175, 180};

//Array Decleration (Temp in Celsius)
const double TEMP [ ] = {-19.46,-18.3,-17.19,-16.11,-15.07,-14.07,-13.1,-12.15,-11.23,-10.34,-9.47,-8.63,-7.8,-7,-6.21,-5.45,-4.69,-3.96,
    -3.24,-2.53,-1.84,-1.16,-0.5,0.15,0.79,1.42,2.04,2.65,3.25,3.83,4.42,4.99,5.55,6.11,6.65,7.19,7.72,8.25,8.76,9.27,9.78,10.28,10.77,
    11.25,11.73,12.21,12.67,13.13,13.6,14.05,14.5,14.93,15.37,15.81,16.23,16.66,17.08,17.5,17.91,18.32,18.72,19.12,19.52,19.91,20.3,20.68,
    22.56,24.36,26.1,27.76,29.37,30.36,32.42,33.88,35.29,36.66,38,39.27,40.55,41.77,43,44.16,45.33,46.44,47.55,48.66,49.72,50.72};

double loPressureTempLUT;
double hiPressureTempLUT;
double superheatTemp;
double subcoolingTemp;



