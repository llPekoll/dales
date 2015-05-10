//
//  dales.h
//  Intercative_floor
//
//  Created by peko on 5/10/15.
//
//

#ifndef __Intercative_floor__dales__
#define __Intercative_floor__dales__

#include <stdio.h>
#include "ofMain.h"

class dales {
public:
    
    void update();
    void draw();
    void setup();
    
    int posX,posY,decalX,decalY;
    
    dales(int x, int y,int daleSize);
    ofPlanePrimitive plane;
 
    
private:
    
    
};

#endif /* defined(__Intercative_floor__dales__) */
