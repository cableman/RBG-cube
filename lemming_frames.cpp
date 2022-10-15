#include "lemming_frames.h"

int LemmingFrames::f1[FRAMES][ROWS][COLUMNS]= {
  { 
    { 0, 0, 0, 0, 0, 0 },
    { 0, 2, 2, 2, 2, 0 }, 
    { 0, 2, 2, 1, 0, 0 }, 
    { 0, 0, 1, 1, 1, 0 }, 
    { 0, 0, 1, 3, 0, 0 }, 
    { 0, 0, 1, 3, 0, 0 }, 
    { 0, 0, 1, 3, 0, 0 }, 
    { 0, 0, 3, 3, 0, 0 }, 
    { 0, 1, 3, 3, 0, 0 }, 
    { 0, 0, 1, 1, 0, 0 }
  },
  { 
    { 0, 0, 2, 0, 2, 0 }, 
    { 0, 2, 2, 2, 0, 0 }, 
    { 0, 2, 2, 1, 0, 0 }, 
    { 0, 0, 1, 1, 1, 0 }, 
    { 0, 0, 1, 3, 0, 0 }, 
    { 0, 1, 3, 3, 0, 0 }, 
    { 0, 1, 3, 3, 0, 1 }, 
    { 0, 0, 3, 3, 0, 1 }, 
    { 0, 3, 3, 0, 1, 0 }, 
    { 0, 1, 1, 0, 0, 0 }
  },
  { 
    { 0, 0, 0, 0, 0, 0 }, 
    { 0, 2, 0, 2, 0, 0 }, 
    { 0, 2, 2, 2, 0, 0 }, 
    { 0, 0, 2, 1, 0, 0 }, 
    { 0, 0, 1, 1, 1, 0 }, 
    { 0, 1, 1, 3, 0, 0 }, 
    { 0, 1, 3, 3, 0, 0 }, 
    { 1, 1, 3, 3, 3, 0 }, 
    { 0, 3, 3, 3, 3, 0 }, 
    { 1, 1, 0, 0, 1, 1 }
  },
  { 
    { 0, 0, 0, 0, 0, 0 }, 
    { 0, 0, 2, 2, 0, 0 }, 
    { 0, 2, 2, 1, 2, 0 }, 
    { 0, 2, 1, 1, 1, 0 }, 
    { 0, 0, 1, 3, 0, 0 }, 
    { 0, 0, 1, 3, 0, 0 }, 
    { 0, 1, 3, 3, 0, 0 }, 
    { 0, 0, 3, 3, 0, 0 }, 
    { 1, 3, 3, 3, 3, 0 }, 
    { 1, 0, 0, 1, 1, 0 }
  }  
};

/**
 * Constructor.
 */
LemmingFrames::LemmingFrames() {
  this->current = 0;
}

void LemmingFrames::nextFrame(Adafruit_NeoMatrix* panel, int offsetRows, int offsetCols) {
  // loop through array's rows
  for ( int i = 0; i < ROWS; ++i ) {
    // loop through columns of current row
    for ( int j = 0; j < COLUMNS; ++j ) {
      switch (this->f1[this->current][ i ][ j ]) {
        case 1:
          // White.
          panel->drawPixel(j + offsetCols, i + offsetRows, panel->Color(255, 209, 170));
          break;

        case 2:
          // Green.
          panel->drawPixel(j + offsetCols, i + offsetRows, panel->Color(0, 255, 0));
          break;

        case 3:
          // Blue.
          panel->drawPixel(j + offsetCols, i + offsetRows, panel->Color(0, 0, 255));
          break;
      }
    }
  } 
  
  this->current++;
  if (this->current > 3) {
    this->current = 0;
  }
}
