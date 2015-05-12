#pragma once

#include "ofMain.h"
#include "dales.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    dales **dale;
    int nDales,daleSize;
    
    int h,w;
    int a;
    
    
    ofShader shader;
    
    ofImage backgroundImage;
    ofImage foregroundImage;
    ofImage brushImage;
    
    ofFbo maskFbo;
    ofFbo fbo;
};
