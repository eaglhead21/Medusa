#pragma once
#include <Arduino.h>
#include <DHT.h> 
#include <OneWire.h>
#include <DallasTemperature.h>
#include <global.h>

//Pressure Calculations
float loPressurePSI;
float hiPressurePSI;

//Temperature Sensor Variable Definitions
float temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;

//Humidity Sensor Variable Definitions
float hum1, hum2;

//Current Sensor Variable Definitions
bool isCompRunning;

//DHT22 : address ,  (temp1, temp2, hum1, hum2)
DHT sensor1(32, DHT22);
DHT sensor2(33, DHT22);
OneWire oneWire(4); // pin D4 (6 temp (temp 3,4,5,6,7,8 sensors parralled together)
DallasTemperature sensors(&oneWire);

void pressure()
{
    // Reading Lo Pressure
    loPressureValue = analogRead(loPressurePin);
    loPressurePSI = (loPressureValue/70.6);
    // Reading Hi Pressure
    hiPressureValue = analogRead(hiPressurePin);
    hiPressurePSI = (hiPressureValue/17.7);
}

void DHT_Temp()
{
    // Read DHT Temperature values
    temp1 = sensor1.readTemperature();
    temp2 = sensor2.readTemperature();
}

void DHT_Humidity()
{
    // Read DHT Humidity values
    hum1 = sensor1.readHumidity();
    hum2 = sensor2.readHumidity();
}

void DS_Temp()
{
    // Read DS18B20 values
    sensors.requestTemperatures();
    temp3 = sensors.getTempCByIndex(0);
    temp4 = sensors.getTempCByIndex(1);  
    temp5 = sensors.getTempCByIndex(2); 
    temp6 = sensors.getTempCByIndex(3); 
    temp7 = sensors.getTempCByIndex(4); 
    temp8 = sensors.getTempCByIndex(5);
}

void Current_Sensor()
{
    isCompRunning = digitalRead(currentSensorPin);
    if (isCompRunning == HIGH)
    {
        isRunning = "No";
    }
    else
    {
        isRunning = "Yes";
    }

    Serial.println(currentSensorPin);

}