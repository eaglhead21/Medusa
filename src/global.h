#pragma once
// Define all the Global Variables of the Code Base below
#include <LiquidCrystal_I2C.h> 
#include <WiFi.h>

//WiFI Declarations
#define HOST "gingerwallop.com"  // Enter HOST URL without "http:// "  and "/" at the end of URL
#define WIFI_SSID "eaglhead"     // WIFI SSID here                                   
#define WIFI_PASSWORD "ilovefreebeer"  // WIFI password here
#define DEBUG 0; //Debug Statements; 0 = OFF ; 1 = ON

WiFiClient client;

//LCD Config I2C Address and 20 lines 4 tall
LiquidCrystal_I2C lcd(0x27, 20, 4);  

//Page Scrolling
int WhichScreen =1;   // This variable stores the current Screen number
bool hasChanged = true;
const int buttonPin = 23;    // the number of the pushbutton pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//Pressure Sensor pin connection defintions
const int potPin1 = 33;
const int potPin2 = 25;

//Define all variables that will be used in functions below
float temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, hum1, hum2, hi_press, lo_press, comp_amps;

// Declare global variables which will be uploaded to server
String sendtemp1, sendtemp2, sendtemp3, sendtemp4, sendtemp5, sendtemp6, sendtemp7, sendtemp8, sendhum1, sendhum2, postData;

//Declare other global variables used
//Debounce
unsigned long prevTime1 = millis();



