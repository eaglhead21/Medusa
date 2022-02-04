#pragma once
#include <Arduino.h>
#include <Wifi.h>
#include <global.h>
#include <medusaLCD.h>

void wifiCheck()
{
    if ((WiFi.status() != WL_CONNECTED) && (millis() - previousInternetMillis >= internetCheckInterval)) 
    {
        lcd.clear();
        lcd.setCursor(0,0); // Column, line
        lcd.print("Internet Lost");
        lcd.setCursor(0,1);
        lcd.print("Trying to Reconnect");
        lcd.setCursor(0,2);
        WiFi.disconnect();
        WiFi.reconnect();
        previousInternetMillis = millis();
        lcd.clear();
        lcd.setCursor(0,0); // Column, line
        lcd.print("Reconnected!");
        delay(3000);
        medusaLCD();
    }
}
