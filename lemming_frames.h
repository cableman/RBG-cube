#include <Arduino.h>

#include <Adafruit_NeoMatrix.h>

#ifndef __lemming_frames_h
#define __lemming_frames_h

#define FRAMES 4
#define ROWS 10
#define COLUMNS 6

class LemmingFrames 
{
  private:
    int current;
    static int f1[FRAMES][ROWS][COLUMNS];
  
  public:
    LemmingFrames();
    void nextFrame(Adafruit_NeoMatrix pane, int offsetRows, int offsetCols);
};

#endif // __lemming_frames_h
