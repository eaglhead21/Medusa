#include <HTTPClient.h>
#include <Arduino_JSON.h>

String outputsState;
const char* serverName = "http://gingerwallop.com/esp-outputs-action.php?action=outputs_state&board=1";

String httpGETRequest(const char* serverName) 
{
    WiFiClient client;
    HTTPClient http;
    
  // Your IP address with path or Domain name with URL path 
  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) 
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else 
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  
  // Free resources
  http.end();
  return payload;
}

void remoteControl()
{
    if(WiFi.status()== WL_CONNECTED )
    { 
        outputsState = httpGETRequest(serverName);
        Serial.println(outputsState);
        JSONVar myObject = JSON.parse(outputsState);

        // JSON.typeof(jsonVar) can be used to get the type of the var
        if (JSON.typeof(myObject) == "undefined") 
        {
        Serial.println("Parsing input failed!");
        return;
        }

        Serial.print("JSON object = ");
        Serial.println(myObject);

        // myObject.keys() can be used to get an array of all the keys in the object
        JSONVar keys = myObject.keys();

        for (int i = 0; i < keys.length(); i++) 
        {
        JSONVar value = myObject[keys[i]];
        Serial.print("GPIO: ");
        Serial.print(keys[i]);
        Serial.print(" - SET to: ");
        Serial.println(value);
        pinMode(atoi(keys[i]), OUTPUT);
        digitalWrite(atoi(keys[i]), atoi(value));
        }
    }
}

