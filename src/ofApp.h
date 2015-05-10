#pragma once

#include "ofMain.h"

#include "ofxOpencv.h"
#include "ofxKinect.h"



#define NUM_BILLBOARDS 5

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    
    
    
    //kinect
    ofxCvColorImage			colorImg;
    ofxCvGrayscaleImage 	grayImage;
    ofxCvGrayscaleImage 	grayBg;
    ofxCvGrayscaleImage 	grayDiff;
    
    ofxCvContourFinder 	contourFinder;
    
    float w,h;
    
    int 				threshold;
    bool				bLearnBakground;
    
    ofxKinect kinect;
    
    
    ofxCvGrayscaleImage grayThreshNear;
    ofxCvGrayscaleImage grayThreshFar;
    
    float scaleY,scaleX;
    
    
    bool bThreshWithOpenCV;
    bool bDrawPointCloud;
    
    int nearThreshold;
    int farThreshold;
    
    int angle;
    
    bool dispHelp;
    int fcount;
    
    
    // logo , system letters , mesh
    float magnet  = 50000;
    float elektrik = 15;
    float elastik  = 0.5;
    float forceX  = 0;
    float forceY  = 0;
    
    float Size ;
    ofImage logo,b,bg,l,v,d,club;
    
    ofMesh mesh;
    ofEasyCam cam;
    
    ofPoint pos[NUM_BILLBOARDS];
    
    ofPoint home[NUM_BILLBOARDS];
    bool mirroX;
    
    
    
    
    ofVideoPlayer 		video1,video2,video3,video4,video5;
};
