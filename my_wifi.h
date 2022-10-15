#include <ESP8266WiFi.h>
#include "wifi_creds.h"

#include <Adafruit_NeoMatrix.h>

#ifndef __my_wifi_h
#define __my_wifi_h

#define maxAttempts 10

class MyWifi
{
  private:
    Adafruit_NeoMatrix* panel;
    WifiCreds creds;
    bool tryConnect(const char* ssid, const char* password, int active);
  
  public:
    // Constructor(s)
    MyWifi(Adafruit_NeoMatrix* panel);

    void connect();
};

#endif
