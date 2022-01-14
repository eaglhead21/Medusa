#pragma once
#include <Arduino.h>
#include <DHT.h> 
#include <OneWire.h>
#include <DallasTemperature.h>
#include <global.h>
#include <timer.h>

//Pressure Sensor Variable Defintions
float loPressureValue;
float hiPressureValue;

//Temperature Sensor Variable Definitions
float temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;

//Humidity Sensor Variable Definitions
float hum1, hum2;

//Current Sensor Variable Definitions
float comp_amps;

//DHT22 : address ,  (temp1, temp2, hum1, hum2)
DHT sensor1(32, DHT22);
DHT sensor2(33, DHT22);
OneWire oneWire(4); // pin D4 (6 temp (temp 3,4,5,6,7,8 sensors parralled together)
DallasTemperature sensors(&oneWire);

void pressure()
{
    #ifdef SENSOR
    {
        timerStart();
    }
    #endif

    // Reading Lo Pressure
    loPressureValue = analogRead(loPressurePin);
    // Reading Hi Pressure
    hiPressureValue = analogRead(hiPressurePin);
    
    #ifdef SENSOR
    {
        timeStop();
        Serial.print("Time inside pressure loop = ");
        Serial.print(timeInterval);
        Serial.print("\n");
    }
    #endif
}

void DHT_Temp()
{
    #ifdef SENSOR
    {
        timerStart();
    }
    #endif
    
    // Read DHT Temperature values
    temp1 = sensor1.readTemperature();
    temp2 = sensor2.readTemperature();

    #ifdef SENSOR
    {
        timeStop();
        Serial.print("Time inside DHT Temp loop = ");
        Serial.print(timeInterval);
        Serial.print("\n");
    }
    #endif
}

void DHT_Humidity()
{
    #ifdef SENSOR
    {
        timerStart();
    }
    #endif

    // Read DHT Humidity values
    hum1 = sensor1.readHumidity();
    hum2 = sensor2.readHumidity();

    #ifdef SENSOR
    {
        timeStop();
        Serial.print("Time inside DHT Humidity loop = ");
        Serial.print(timeInterval);
        Serial.print("\n");
    }
    #endif
}

void DS_Temp()
{
    #ifdef SENSOR
    {
        timerStart();
    }
    #endif
    
    // Read DS18B20 values
    sensors.requestTemperatures();
    temp3 = sensors.getTempCByIndex(0);
    temp4 = sensors.getTempCByIndex(1);  
    temp5 = sensors.getTempCByIndex(2); 
    temp6 = sensors.getTempCByIndex(3); 
    temp7 = sensors.getTempCByIndex(4); 
    temp8 = sensors.getTempCByIndex(5);

    #ifdef SENSOR
    {
        timeStop();
        Serial.print("Time inside Dallas Temp loop = ");
        Serial.print(timeInterval);
        Serial.print("\n");
    }
    #endif
}

void Current_Sensor()
{
    #ifdef SENSOR
    {
        timerStart();
    }
    #endif

    comp_amps = analogRead(currentSensorPin);

    #ifdef SENSOR
    {
        timeStop();
        Serial.print("Time inside Current Sense loop = ");
        Serial.print(timeInterval);
        Serial.print("\n");
    }
    #endif
}