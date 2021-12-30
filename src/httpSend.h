#include <Arduino.h>
#include <global.h>
#include <sensor.h>
#include <HTTPClient.h>

void httpClient()
{
// Send data to mysql start loop
unsigned long currentTime1 = millis();
if (currentTime1 - prevTime1 > 10000) 
{
  HTTPClient http;    // http object of clas HTTPClient
  
  // Convert integer variables to string
  sendtemp1 = String(temp1);  
  sendtemp2 = String(temp2);   
  sendhum1 = String(hum1); 
  sendhum2 = String(hum2);
  sendtemp3 = String(temp3);  
  sendtemp4 = String(temp4);   
  sendtemp5 = String(temp5); 
  sendtemp6 = String(temp6); 
  sendtemp7 = String(temp7); 
  sendtemp8 = String(temp8); 

  //compile all 
  postData = "sendtemp1=" + sendtemp1 + "&sendtemp2=" + sendtemp2 + "&sendtemp3=" + sendtemp3 + "&sendtemp4=" + sendtemp4 + "&sendtemp5=" + sendtemp5 + "&sendtemp6=" + sendtemp6 + "&sendtemp7=" + sendtemp7 + "&sendtemp8=" + sendtemp8 + "&sendhum1=" + sendhum1 + "&sendhum2=" + sendhum2;

  http.begin(client, "http://gingerwallop.com/dbwrite.php");             // Connect to host where MySQL databse is hosted
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //Specify content-type header

  int httpCode = http.POST(postData);   // Send POST request to php file and store server response code in variable named httpCode
 
  // if connection eatablished then do this
  if (httpCode == 200) 
  { 
    Serial.println("Values uploaded successfully."); Serial.println(httpCode); 
    String webpage = http.getString();    // Get html webpage output and store it in a string
    Serial.println(webpage + "\n"); 
  }

// if failed to connect then return and restart
  else 
  { 
    Serial.println(httpCode); 
    Serial.println("Failed to upload values. \n"); 
    http.end(); 
    return; 
  }

  prevTime1 = currentTime1;
  } // send data to mysql end loop
}
