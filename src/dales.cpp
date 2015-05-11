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
    isRotating = false;
    fcountStart = false;
    
    texture.loadImage("text.jpg");
    plane.mapTexCoords(0, 0, texture.getWidth(), texture.getHeight());
    
}
void dales::setup()
{
   
    
}

void dales::update(){
    
    if (ofGetMouseX() >posX -size-size/2 &&
        ofGetMouseX() <posX+ size*2 +size/2 &&
        ofGetMouseY() >posY -size - size/2&&
        ofGetMouseY() <posY+ size*2 +size/2)
    {
        
        fcountStart =true;
    }
    
    if (fcountStart)
    {
        rotationDale();
        a++;
    }
    
    if (a>=180){
        fcountStart = false;
        a =0;
    }
    
}

void dales::draw()
{
    texture.getTextureReference().bind();
    plane.setPosition(posX, posY, 0);
    plane.drawFaces();
    plane.drawWireframe();
    texture.getTextureReference().unbind();
}

void dales::rotationDale(){
    
        angle.y = a;
        plane.setOrientation(angle);
    
}