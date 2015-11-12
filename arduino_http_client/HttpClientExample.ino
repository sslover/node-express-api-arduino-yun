/*
  Yún HTTP Client

 This example for the Arduino Yún shows how create a basic
 HTTP client that connects to the internet and downloads
 content. In this case, you'll connect to your server (Heroku app)
 website and get the latest status (or whatever data you want).

 based on example by Tom igoe
 May 2013

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/HttpClient

 */

#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  // Bridge takes about two seconds to start up
  // it can be helpful to use the on-board LED
  // as an indicator for when it has initialized
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(9600);
  while (!Serial); // wait for a serial connection
}

void loop() {
  // Initialize the client library
  HttpClient client;

  // Make a HTTP request
  // Your URL route goes here
  client.get("https://twilio-sms-example.herokuapp.com/api/get/latest");

  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.print(c);

    // can do logic here based on what is read from the serial monitor
    // if c = "sleepy", do this
    // if c = "happy", do this
    // if c =  "sad", do this
    
  }
  Serial.flush();

  delay(5000);
}


