//
//  dales.cpp
//  Intercative_floor
//
//  Created by peko on 5/10/15.
//
//

#include "dales.h"


dales::dales(float xValue, float yValue)
{
    posX = xValue;
    posY = yValue;
    
}
void dales::setup(){
    ofSetupScreenOrtho();
    
    plane.set(100,100);
    plane.setResolution(10, 10);
    decalX=decalY=0;
    
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
   
    //ofRect(posX, posY, 30, 30);

    
    plane.rotate(1, 0, 1, 0);
    plane.setPosition(posX+100+decalX, posY+100+decalY, 0);
    plane.drawFaces();

}