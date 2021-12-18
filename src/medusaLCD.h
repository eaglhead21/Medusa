#pragma once
#include <global.h>
#include <sensors.h>

void firstScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Box:");
  lcd.setCursor(4,0);
  lcd.print("99.9");
  lcd.setCursor(8,0);
  lcd.print("C");

  lcd.setCursor(10,0);
  lcd.print("Amb:");
  lcd.setCursor(14,0);
  lcd.print("99.9");
  lcd.setCursor(18,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Sup:");
  lcd.setCursor(4,1);
  lcd.print("99.9");
  lcd.setCursor(8,1);
  lcd.print("C");

  lcd.setCursor(10,1);
  lcd.print("Sub:");
  lcd.setCursor(14,1);
  lcd.print("99.9");
  lcd.setCursor(18,1);
  lcd.print("C");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Eva:");
  lcd.setCursor(4,2);
  lcd.print("99.9");
  lcd.setCursor(8,2);
  lcd.print("C");

  lcd.setCursor(10,2);
  lcd.print("Con:");
  lcd.setCursor(14,2);
  lcd.print("99.9");
  lcd.setCursor(18,2);
  lcd.print("C");

  lcd.setCursor(0,3); // Column, line
  lcd.print("Lo:");
  lcd.setCursor(4,3);
  lcd.print(potValue1/70);
  lcd.setCursor(8,3);
  lcd.print("G");

  lcd.setCursor(10,3);
  lcd.print("Hi:");
  lcd.setCursor(14,3);
  lcd.print(potValue2/17.65);
  lcd.setCursor(18,3);
  lcd.print("G");
}

void secondScreen()
{
  lcd.clear();
  lcd.setCursor(0,0); // Column, line
  lcd.print("Evap In :");
  lcd.setCursor(10,0);
  lcd.print("99.9");
  lcd.setCursor(14,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Evap Out:");
  lcd.setCursor(10,1);
  lcd.print("99.9");
  lcd.setCursor(14,1);
  lcd.print("C");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Cond In :");
  lcd.setCursor(10,2);
  lcd.print("99.9");
  lcd.setCursor(14,2);
  lcd.print("C");

  lcd.setCursor(0,3);
  lcd.print("Cond Out:");
  lcd.setCursor(10,3);
  lcd.print("99.9");
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
  lcd.print("9.9");
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
  lcd.print("99.9");
  lcd.setCursor(18,0);
  lcd.print("C");

  lcd.setCursor(0,1); // Column, line
  lcd.print("Box Humidity:");
  lcd.setCursor(14,1);
  lcd.print("99.9");
  lcd.setCursor(18,1);
  lcd.print("%");

  lcd.setCursor(0,2); // Column, line
  lcd.print("Amb Temp:");
  lcd.setCursor(14,2);
  lcd.print("99.9");
  lcd.setCursor(18,2);
  lcd.print("C");

  lcd.setCursor(0,3); // Column, line
  lcd.print("Amb Humidity:");
  lcd.setCursor(14,3);
  lcd.print("99.9");
  lcd.setCursor(18,3);
  lcd.print("%");
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
    
    case 0:
      {
      
      }
      break;
  }

  if (WhichScreen > 5)
  {
    WhichScreen = 1;
  }
}

