//
//  dales.cpp
//  Intercative_floor
//
//  Created by peko on 5/10/15.
//
//

#include "dales.h"


dales::dales(float xValue, float yValue, int daleSize)
{
    posX = xValue;
    posY = yValue;
    plane.set(daleSize,daleSize);
    
   
    
    
    plane.setResolution(2, 2);
    decalX=decalY=0;
    
}
void dales::setup(){
   
    
}

void dales::update(){
    
    if (ofGetMouseX() <posX+100 ) {
        decalX=decalY =20;
    }
    else{
        decalX=decalY =0;
    }
   
    
}

void dales::draw()
{
    
    plane.rotate(1, 0, 1, 0);
    plane.setPosition(posX+decalX, posY+decalY, 0);
    plane.drawWireframe();

}