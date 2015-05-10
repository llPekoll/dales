//
//  dales.cpp
//  Intercative_floor
//
//  Created by peko on 5/10/15.
//
//

#include "dales.h"


dales::dales()
{
    
    
}
void dales::setup(int x, int y){
    
    posX = x;
    posY =y;
    plane.set(100,100);
    plane.setResolution(10, 10);
}

void dales::update(){
    
    
}

void dales::draw()
{

    ofRect(posX, posY, 30, 30);

    
    
    plane.setPosition(posX+100, posY+100, 0);
    plane.drawFaces();

}