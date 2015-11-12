#include <Bridge.h>
#include <Console.h>
#include <FileIO.h>
#include <HttpClient.h>
#include <Mailbox.h>
#include <Process.h>
#include <BridgeClient.h>
#include <BridgeServer.h>

#include <SPI.h>

// http://54.83.205.153/
IPAddress server(54,83,205,153); // your static IP goes here
BridgeClient client;

// some sensor value we want to store; for example, temperature
// static here, but would be changing based on a sensor
int temperature = 64;

void setup()
{

  Bridge.begin();
  Serial.begin(9600);
  String parameter ="";
  //delay(5000);
  Serial.println("XXXXXXXXX");

  delay(2500);
  Serial.println("connecting...");

  if (client.connect(server, 80)) 
  {
    Serial.println("connected");
    delay(2500);
    // replace temperature with your parameter
    parameter="temperature="+String(temperature);

    // put your API route here
    client.println("POST /api/sensor/write HTTP/1.1");
    client.print("Content-length:");
    client.println(parameter.length());
    Serial.println(parameter.length());
    Serial.println(parameter);
    client.println("Connection: Close");
    // put your IP here
    //client.println("Host:54.83.205.153");
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println();
    client.println(parameter); 
  } 
    else 
    {
    Serial.println("connection failed");
    }
}
void loop()
{
  if (client.available()) {
    char c = client.read();
    Serial.print(c);  
  }
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
  ;
  }
}