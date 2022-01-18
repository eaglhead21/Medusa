#pragma once
#include <global.h>
#include <sensors.h>
#include <WiFi.h>
#include <HTTPClient.h>

void firstScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Box:");
  lcd.setCursor(4,0);
  lcd.print(temp1);
  lcd.setCursor(8,0);
  lcd.print("C");

  lcd.setCursor(10,0);
  lcd.print("Amb:");
  lcd.setCursor(14,0);
  lcd.print(temp2);
  lcd.setCursor(18,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Sup:");
  lcd.setCursor(4,1);
  lcd.print(superheatTemp);
  lcd.setCursor(8,1);
  lcd.print("C");

  lcd.setCursor(10,1);
  lcd.print("Sub:");
  lcd.setCursor(14,1);
  lcd.print(subcoolingTemp);
  lcd.setCursor(18,1);
  lcd.print("C");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Eva:");
  lcd.setCursor(4,2);
  lcd.print(temp3);
  lcd.setCursor(8,2);
  lcd.print("C");

  lcd.setCursor(10,2);
  lcd.print("Con:");
  lcd.setCursor(14,2);
  lcd.print(temp4);
  lcd.setCursor(18,2);
  lcd.print("C");

  lcd.setCursor(0,3); // Column, line
  lcd.print("Lo:");
  lcd.setCursor(4,3);
  lcd.print(loPressureValue/70);
  lcd.setCursor(8,3);
  lcd.print("G");

  lcd.setCursor(10,3);
  lcd.print("Hi:");
  lcd.setCursor(14,3);
  lcd.print(hiPressureValue/17.65);
  lcd.setCursor(18,3);
  lcd.print("G");
}

void secondScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Evap In :");
  lcd.setCursor(10,0);
  lcd.print(temp5);
  lcd.setCursor(14,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Evap Out:");
  lcd.setCursor(10,1);
  lcd.print(temp6);
  lcd.setCursor(14,1);
  lcd.print("C");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Cond In :");
  lcd.setCursor(10,2);
  lcd.print(temp7);
  lcd.setCursor(14,2);
  lcd.print("C");

  lcd.setCursor(0,3);
  lcd.print("Cond Out:");
  lcd.setCursor(10,3);
  lcd.print(temp8);
  lcd.setCursor(14,3);
  lcd.print("C");
}
  
void thirdScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Comp Delta T:");
  lcd.setCursor(14,0);
  lcd.print("99.9");
  lcd.setCursor(18,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Cond Delta T:");
  lcd.setCursor(14,1);
  lcd.print("99.9");
  lcd.setCursor(18,1);
  lcd.print("C");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Evap Delta T:");
  lcd.setCursor(14,2);
  lcd.print("99.9");
  lcd.setCursor(18,2);
  lcd.print("C");

  lcd.setCursor(0,3); // Column, line
  lcd.print("Cap  Delta T:");
  lcd.setCursor(14,3);
  lcd.print("99.9");
  lcd.setCursor(18,3);
  lcd.print("C");
}

  void forthScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Comp Current:");
  lcd.setCursor(14,0);
  lcd.print(currentSensorPin);
  lcd.setCursor(18,0);
  lcd.print("A");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Conp Temp:");
  lcd.setCursor(14,1);
  lcd.print("99.9");
  lcd.setCursor(18,1);
  lcd.print("C");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Comp Run:");
  lcd.setCursor(14,2);
  lcd.print("Yes");

  lcd.setCursor(0,3); // Column, line
  lcd.print("Tower Temp:");
  lcd.setCursor(14,3);
  lcd.print("99.9");
  lcd.setCursor(18,3);
  lcd.print("C");
}

void fifthScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Box Temp:");
  lcd.setCursor(14,0);
  lcd.print(temp1);
  lcd.setCursor(18,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Box Humidity:");
  lcd.setCursor(14,1);
  lcd.print(hum1);
  lcd.setCursor(18,1);
  lcd.print("%");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Amb Temp:");
  lcd.setCursor(14,2);
  lcd.print(temp2);
  lcd.setCursor(18,2);
  lcd.print("C");

  lcd.setCursor(0,3); // Column, line
  lcd.print("Amb Humidity:");
  lcd.setCursor(14,3);
  lcd.print(hum2);
  lcd.setCursor(18,3);
  lcd.print("%");
}

void sixthScreen()
{
  if (WiFi.status() == WL_CONNECTED) 
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("IP Address: ");

    lcd.setCursor(0,1); // Column, line
    lcd.print(WiFi.localIP());

    lcd.setCursor(0,2); // Column, line
    lcd.print("SSID: ");

    lcd.setCursor(0,3); // Column, line
    lcd.print(WIFI_SSID);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0); // Column, line
    lcd.print("Internet Not Connected");
  }
}
   

void medusaLCD()
{
  switch(WhichScreen) 
  {
    case 1:
    {
      firstScreen();
    }
      break;
  
    case 2:
      {
        secondScreen();
      }
      break;
  
    case 3:
      {
        thirdScreen();
      }
      break;

    case 4:
      {
        forthScreen();
      }
      break;

    case 5:
      {
        fifthScreen();
      }
      break;

    case 6:
      {
        sixthScreen();
      }
      break;
    
    case 0:
      {
      
      }
      break;
  }

  if (WhichScreen == 6)
  {
    WhichScreen = 0;
  }
}

