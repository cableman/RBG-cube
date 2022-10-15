#include "my_wifi.h"
#include <ezTime.h>

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#include "fonts/Picopixel.h"

#include "lemming_frames.h"
LemmingFrames lemming1;

#define PIN D1

Adafruit_NeoMatrix panel = Adafruit_NeoMatrix(16, 16, PIN,
  NEO_MATRIX_TOP + NEO_MATRIX_RIGHT +
  NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

/**
 * Connect to NTP time server.
 */
Timezone myTZ;
void connectTime() 
{
  panel.clear();
  panel.setCursor(0, 4);
  panel.print("TIME");
  panel.show();
  delay(1000);

  myTZ.setLocation("Europe/Copenhagen");
  waitForSync();
}

/**
 * Simple time.
 */
void simpleTime()
{
  panel.setFont();
  panel.clear();

  String hour = myTZ.dateTime("H");
  hour.replace("0", "O");

  panel.setTextColor(panel.Color(random(255), random(255), random(255)));
  panel.setCursor(0, 0);
  panel.print(hour);

  panel.setTextColor(panel.Color(random(255), random(255), random(255)));
  panel.setCursor(4, 8);
  panel.print(myTZ.dateTime("i"));
 
  // Refreshes display.
  panel.show();

  delay(500);

  panel.setFont(&Picopixel);
}

/**
 * Display time and working lemming.
 */
void lemmingWalkWithTime()
{
  int offsetRows = 6;
  int speed = 150;
 
  for (int offsetCols = -6; offsetCols < 16+8; ++offsetCols) {
    panel.clear();

    panel.setCursor(0, 4);
    panel.print(myTZ.dateTime("H"));

    panel.setCursor(9, 4);
    panel.print(myTZ.dateTime("i"));
   
    lemming1.nextFrame(&panel, offsetRows, offsetCols);

    // Refreshes display.
    panel.show();
  
    delay(speed);
  }

}

void setup() {
  panel.begin();
  panel.setBrightness(20);
  panel.clear();

  panel.setFont(&Picopixel);
  panel.setTextSize(1);

  panel.println("INIT");
  panel.show();
  delay(500);
  panel.clear();

  // Connect to WIFI.
  MyWifi* myWifi = new MyWifi(&panel);
  myWifi->connect();

  // Connect to time servers.
  connectTime();
}

void loop() {
  lemmingWalkWithTime();
}
