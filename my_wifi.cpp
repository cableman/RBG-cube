#include "my_wifi.h"

/**
 * Constructor.
 */
MyWifi::MyWifi(Adafruit_NeoMatrix* panel) 
{
  this->panel = panel;
}

/**
 * Connect to wifi network.
 * 
 * Creds should be set in wifi_creds.h.
 */
void MyWifi::connect()
{
  int active = 0;

  // Loop over creds until connection is established.
  while (!this->tryConnect(this->creds.ssid[active], this->creds.password[active], active)) {
    active++;
    //active = ((active + 1) % WifiCredsNumber);
  }
}

/**
 * Try to connect to a network.
 */
bool MyWifi::tryConnect(const char* ssid, const char* password, int active)
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  bool state = true;
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < maxAttempts) {    
    this->panel->clear();
    this->panel->setCursor(0, 4);
    this->panel->println("WIFI!");
    if (state) {
      this->panel->println("WAIT");
    }

    for (int i = 0; i < active+1; i++) {
      this->panel->drawPixel(i, 15, panel->Color(255, 0, 0));
    }
    
    this->panel->show();
    delay(800);

    state = !state;
    attempts += 1;
  }
  
  return WiFi.status() == WL_CONNECTED;
}
