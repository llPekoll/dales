//
//  dales.cpp
//  Intercative_floor
//
//  Created by peko on 5/10/15.
//
//

#include "dales.h"


dales::dales(int xValue, int yValue, int daleSize)
{
    posX = xValue;
    posY = yValue;
    plane.set(daleSize,daleSize);
    size = daleSize;
    plane.setResolution(2, 2);
   
    
}
void dales::setup()
{
   
    
}

void dales::update(){
    
    if (ofGetMouseX() >posX &&
        ofGetMouseX() <posX+ size &&
        ofGetMouseY() >posY &&
        ofGetMouseY() <posY+ size)
    {
        
        plane.rotate(1, 0, 1, 0);
    }

   
}

void dales::draw()
{
    
   
    plane.setPosition(posX, posY, 0);
    plane.drawFaces();

}