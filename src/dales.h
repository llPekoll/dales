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
    void rotationDale();
    
    int posX,posY,size,a;
    bool isRotating,fcountStart;
    
    dales(int x, int y,int daleSize);
    ofPlanePrimitive plane;
    ofVec3f angle;
 
    
private:
    
    
};

#endif /* defined(__Intercative_floor__dales__) */
