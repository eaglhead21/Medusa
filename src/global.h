#pragma once
// Define all the Global Variables of the Code Base below
#include <LiquidCrystal_I2C.h> 
#include <WiFi.h>

//WiFI Declarations
#define HOST "gingerwallop.com"  // Enter HOST URL without "http:// "  and "/" at the end of URL
#define WIFI_SSID "Redpoint"     // WIFI SSID here                                   
#define WIFI_PASSWORD "ilovefreebeer"  // WIFI password here
#define DEBUG;
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
const int loPressurePin = 33;
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
long interval = 10000;           // interval at which to sample the data

long timeStart = millis();
long timeInterval = 0; 

//Used for LUT variable
//Array Declaration (PSIG [143])
const int PSIG [ ] = {-22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
    22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
    59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140, 145, 150, 155, 160, 165, 170, 175,
    180, 185, 190, 195, 200, 205, 210, 215, 220, 225, 230, 235, 240, 245, 250, 255, 260, 265, 270, 275, 280, 285, 290, 295, 300, 305, 310, 315, 320, 325,
    330, 335, 340, 345, 350, 355, 360, 365, 370, 375, 380};

//Array Decleration (Temp in Celsius [143])
const double TEMP [ ] = {-52.4,-48.3,-44.9,-41.9,-39.3,-36.9,-34.8,-32.8,-30.9,-29.2,-27.6,-26.1,-24.6,-23.2,-21.9,-20.7,-19.5,-18.3,-17.2,-16.1,-15.1,-14.1,
    -13.1,-12.2,-11.2,-10.3,-9.5,-8.6,-7.8,-7,-6.2,-5.5,-4.7,-4,-3.2,-2.5,-1.8,-1.2,-0.5,0.2,0.8,1.4,2,2.7,3.3,3.8,4.4,5,5.6,6.1,6.7,7.2,7.7,8.3,8.8,9.3,
    9.8,10.3,10.8,11.3,11.7,12.2,12.7,13.1,13.6,14.1,14.5,14.9,15.4,15.8,16.2,16.7,17.1,17.5,17.9,18.3,18.7,19.1,19.5,19.9,20.3,20.7,22.6,24.4,26.1,27.8,
    29.4,30.4,32.4,33.9,35.3,36.7,38,39.3,40.6,41.8,43,44.2,45.3,46.4,47.6,48.7,49.7,50.7,51.8,52.7,53.7,54.7,55.6,56.6,57.5,58.4,59.3,60.1,61,61.8,62.7,
    63.5,64.3,65.1,65.9,66.7,67.4,68.2,68.9,69.7,70.4,71.1,71.8,72.5,73.2,73.9,74.6,75.2,75.9,76.6,77.2,77.8,78.5,79.1,79.7,80.2,80.7,81.2};

double loPressureTempLUT;
double hiPressureTempLUT;
double superheatTemp;
double subcoolingTemp;



