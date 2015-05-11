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
    a=0;
    
    
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
        
        
     
        if(a<180){
            a+=4;
            angle.y = a;
            plane.setOrientation(angle );
        
        }
    }

   
}

void dales::draw()
{
    
    plane.setPosition(posX, posY, 0);
    plane.drawFaces();

}