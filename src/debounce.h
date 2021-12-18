#include <Arduino.h>
#include <global.h>

void debounceCheckState() 
{ 
//BEGIN of the switch debouncing code
    int reading = digitalRead(buttonPin);
    if (reading != lastButtonState) 
    {
        //Reset the debouncing timer
        lastDebounceTime = millis();
    }
    
    // Whatever the reading is accept as the Current State
    if ((millis() - lastDebounceTime) > debounceDelay) 
    {
    // If the button state has changed:
        if (reading != buttonState) {
        buttonState = reading;
    
        // only toggle the LCD if the new button state is HIGH
        if (buttonState == HIGH) {
            hasChanged = true;
            WhichScreen++;     
        }
    }  
    else 
    {
      hasChanged = false;
    }
    
    #ifdef DEBUG
        Serial.print("Button State is: ");
        Serial.print(buttonState);
    #endif
  }
lastButtonState = reading;
// END of the switch Debouncing code
}
