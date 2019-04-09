/*
  UDPSendReceive.pde:
  This sketch receives UDP message strings, prints them to the serial port
  and sends an "acknowledge" string back to the sender

  A Processing sketch is included at the end of file that can be used to send
  and received messages for testing with a computer.

  created 21 Aug 2010
  by Michael Margolis

  This code is in the public domain.

  adapted from Ethernet library examples
*/


#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

#ifndef STASSID
#define STASSID "MJC"
#define STAPSK  "321321321"
#endif

unsigned int port = 203;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[128]; //buffer to hold incoming packet,

WiFiUDP Udp;

uint32_t previous_time ;

//IPAddress local_IP(192,168,1,1);
//IPAddress gateway(192,168,0,1);
//IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(9600);
  Serial.swap();
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);

//Serial.println();

    while (WiFi.status() != WL_CONNECTED) 
    {
    //+Serial.print('No Connected');
    delay(500);
  }
  
//  Serial.print("Connected! IP address: ");
//  Serial.println(WiFi.localIP());
//  Serial.printf("UDP server on port %d\n", port);
  Udp.begin(port);
}

void sentMIDI(uint8_t channel, uint8_t note, uint8_t velocity)
{
  byte midipacket[3] = {channel, note, velocity};
  Serial.write(midipacket,3);
  sentPacket(channel, note, velocity);
}

void readMIDI()
{
  if(Serial.available())
  {
    byte midipacket[3];
    Serial.readBytes(midipacket,3);
    sentPacket(midipacket[0],midipacket[1],midipacket[2]);
  }
}

void sentPacket(uint8_t channel, uint8_t key, uint8_t velocity)
{
  OSCMessage msg("/midi");
  uint32_t midipacket = channel*0x10000 + key*0x100 + velocity;
    msg.add(midipacket);
    Udp.beginPacket(Udp.remoteIP(), port);
    msg.send(Udp);
    Udp.endPacket();
}

bool readPacket()
{
    if (Udp.parsePacket()) 
    {
      uint8_t packetsize = Udp.read(packetBuffer, 128);
//      Serial.print(packetBuffer[packetsize - 3], DEC);
//      Serial.print(' ');
//      Serial.print(packetBuffer[packetsize - 2], DEC);
//      Serial.print(' ');
//      Serial.print(packetBuffer[packetsize - 1], DEC);
//      Serial.println();
        sentMIDI(
          packetBuffer[packetsize - 3],
          packetBuffer[packetsize - 2],
          packetBuffer[packetsize - 1]);
      return true;
    }
   return false;
}

void heartbeat()
{
//    Udp.beginPacket(Udp.remoteIP(), port);
//    Udp.write(203);
//    Udp.write(203);
//    Udp.write(203);
//    Udp.write(203);
//    Udp.endPacket();
    Serial.print("Heartbeat \t");
    Serial.println(Udp.remoteIP());
}

void loop() 
{
  readPacket();
  uint32_t current_time = millis();
  if(current_time - previous_time >= 5000) 
  {
    previous_time = current_time;
    //heartbeat();
}
}
