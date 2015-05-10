#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    fcount=0;
    
    ofBackground(0);
    ofSetVerticalSync(true);
    video1.loadMovie("video1.mov");
    video1.play();
    video2.loadMovie("video2.mov");
    video2.play();
    video3.loadMovie("video3.mov");
    video3.play();
    video4.loadMovie("video4.mov");
    video4.play();
    video5.loadMovie("video5.mov");
    video5.play();
    
    kinect.setRegistration(true);
    kinect.init();
    kinect.open();
    if(kinect.isConnected()) {
        ofLogNotice() << "sensor-emitter dist: " << kinect.getSensorEmitterDistance() << "cm";
        ofLogNotice() << "sensor-camera dist:  " << kinect.getSensorCameraDistance() << "cm";
        ofLogNotice() << "zero plane pixel size: " << kinect.getZeroPlanePixelSize() << "mm";
        ofLogNotice() << "zero plane dist: " << kinect.getZeroPlaneDistance() << "mm";
    }
    
    colorImg.allocate(kinect.width, kinect.height);
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    nearThreshold = 230;
    farThreshold = 70;
    bThreshWithOpenCV = true;
    
    ofSetFrameRate(60);
    
    angle = 0;
    kinect.setCameraTiltAngle(angle);
    scaleX = scaleY =1;
    
    
    
    
    // mesh, letters
    
    ofSetVerticalSync(true);
    mesh.load("lofi-bunny.ply");
    
    magnet  = 9000;
    elektrik = 0.9;
    elastik  = 0.4;
    forceX  = 0;
    forceY  = 0;
    
    Size = 1;
    
    for (int i=0; i<NUM_BILLBOARDS; i++) {
        pos[i].x = (ofGetHeight()/4)+i*170;
        pos[i].y = ofGetHeight()/2;
        home[i] = pos[i];
        home[i].z =0;
    }
    logo.loadImage("logo.png");
    bg.loadImage("_bg.png");
    b.loadImage("_b.png");
    l.loadImage("_l.png");
    v.loadImage("_v.png");
    d.loadImage("_d.png");
    club.loadImage("_club.png");
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    fcount++;
    video1.update();
    video2.update();
    video3.update();
    video4.update();
    video5.update();
    kinect.update();
    
    
    if(kinect.isFrameNew()) {
        
        grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
        
        
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        
        // update the cv images
        
        if(mirroX){
            grayImage.mirror(false, true);
        }
        
        grayImage.flagImageChanged();
        grayImage.resize(ofGetWidth(), ofGetHeight());
        grayImage.scale(1*scaleX, 1*scaleY);
        contourFinder.findContours(grayImage, 30, (kinect.width*kinect.height)/2, 20, false);
    }
    
    /// letters
    
    if (contourFinder.nBlobs==0)
        //    {
        //        for (int i=0; i<NUM_BILLBOARDS; i++) {
        //            float dX  =  9000+ home[i].x - pos[i].x;
        //            float dY  =  9000+ home[i].y - pos[i].y;
        //            int d  = sqrt(dX * dX + dY * dY);
        //
        //            int powerX  = pos[i].x  - (dX / d) * (magnet / d);
        //            int powerY  = pos[i].y  - (dY / d) * (magnet / d);
        //            forceX = (forceX*1.2 + (home[i].x - pos[i].x) / elektrik) * elastik;
        //            forceY = (forceY*1.2 + (home[i].y- pos[i].y) / elektrik) * elastik;
        //
        //            pos[i].x = powerX + forceX;
        //            pos[i].y = powerY + forceY;
        //            Size = (powerX * forceY) / 20000;}
        //    }
        //  else
    {
        for (int i=0; i<NUM_BILLBOARDS; i++) {
            // float dX  = contourFinder.blobs[0].centroid.x/8 -ofGetWidth()/20 + home[i].x - pos[i].x;
            // float dY  = contourFinder.blobs[0].centroid.y/2 -ofGetHeight()/5 + home[i].y - pos[i].y;
            float dX  = mouseX/16 -ofGetWidth()/20 + home[i].x - pos[i].x;
            float dY  = mouseY/1.5 -ofGetHeight()/4 + home[i].y - pos[i].y;
            int d  = sqrt(dX * dX + dY * dY);
            
            int powerX  = pos[i].x  - (dX / d) * (magnet / d);
            int powerY  = pos[i].y  - (dY / d) * (magnet / d);
            forceX = (forceX*1.2 + (home[i].x - pos[i].x) / elektrik) * elastik;
            forceY = (forceY*1.2 + (home[i].y- pos[i].y) / elektrik) * elastik;
            
            pos[i].x = powerX + forceX;
            pos[i].y = powerY + forceY;
            Size = (powerX * forceY) / 20000;
            
        }
        
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
    if (fcount>0)
        video1.draw(0,0,ofGetWidth(),ofGetHeight());
    
    if(fcount>300)
        video2.draw(0,0,ofGetWidth(),ofGetHeight());
    
    if(fcount>600)
        video3.draw(0,0,ofGetWidth(),ofGetHeight());
    if(fcount>900)
        video4.draw(0,0,ofGetWidth(),ofGetHeight());
    if(fcount>1200)
        video5.draw(0,0,ofGetWidth(),ofGetHeight());
    
    ofSetColor(255, 255, 255,200);
    bg.draw(ofGetWidth()/2-bg.width/2, ofGetHeight()/2-bg.height/2);
    ofSetColor(255, 255, 255,255);
    
    if(fcount>1500){
        ofSetColor(0);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
        cam.begin();
        ofPushMatrix();
        
        
        ofSetColor(ofColor::gray);
        
        ofRotate(ofGetElapsedTimef()*10, 0, 1, 0);
        ofScale(1.5, 1.5,1.5);
        ofTranslate(0, +30,0);
        mesh.drawWireframe();
        
        glPointSize(2);
        ofSetColor(ofColor::white);
        mesh.drawVertices();
        ofPopMatrix();
        cam.end();
        
    }
    
    if (fcount>1800) {
        fcount =0;
    }
    
    b.draw(pos[0].x-b.width/2, pos[0].y-b.height/2);
    l.draw(pos[1].x-l.width/2, pos[1].y-l.height/2);
    v.draw(pos[2].x-v.width/2, pos[2].y-v.height/2);
    d.draw(pos[3].x-d.width/2, pos[3].y-d.height/2);
    
    
    
    ofSetColor(255);
    club.draw(pos[4].x-club.width/2, pos[4].y-club.height/2);
    
    logo.draw(ofGetWidth()-150, ofGetHeight()-200,logo.width/2.5,logo.height/2.5);
    
    
    ofDrawBitmapString(ofToString(contourFinder.nBlobs) , 20, 20);
    
    if(dispHelp){
        ofSetColor(255);
        kinect.drawDepth(10, 10, 400*scaleX, 300*scaleY);
        kinect.draw(420, 10, 400*scaleX, 300*scaleY);
        ofSetColor(123, 234, 255,125);
        ofFill();
        ofRect(420, 10, 400, 300);
        ofNoFill();
        ofSetColor(255);
        grayImage.draw(10, 320, 400, 300);
        contourFinder.draw(10, 320, 400, 300);
        
        for (int i = 0; i < contourFinder.nBlobs; i++){
            contourFinder.blobs[i].draw(0,0);
        }
        
        ofSetColor(0);
        stringstream reportStr;
        reportStr << "Welcome to smile World" << endl
        << "bg subtraction and blob detection" << endl
        << "press ' f ' to fullscreen" << endl
        << "press ' SPACE ' to capture bg" << endl
        << "press ', ' and '.' to scale the camera " << endl
        << "press Arrows to move the camera " << endl
        << "threshold " << threshold << " (press: +/-)" << endl
        << ", fps: " << ofGetFrameRate();
        ofDrawBitmapString(reportStr.str(), 20, 20);
        ofSetColor(255);
        
        
    }
}

void ofApp::exit() {
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if( key == 'h' ){
        dispHelp = !dispHelp ;
    }
    if( key == 'm' ){
        mirroX = !mirroX ;
    }
    if ( key == 'f'){
        ofToggleFullscreen();
    }
    
    switch (key){
        case ' ':
            bLearnBakground = true;
            break;
            
        case '1':
            farThreshold ++;
            if (farThreshold > 255) farThreshold = 255;
            break;
            
        case '2':
            farThreshold --;
            if (farThreshold < 0) farThreshold = 0;
            break;
            
        case 'q':
            nearThreshold ++;
            if (nearThreshold > 255) nearThreshold = 255;
            break;
            
        case 'w':
            nearThreshold --;
            if (nearThreshold < 0) nearThreshold = 0;
            break;
            
        case 'o':
            kinect.setCameraTiltAngle(angle); // go back to prev tilt
            kinect.open();
            break;
            
        case 'c':
            kinect.setCameraTiltAngle(0); // zero the tilt
            kinect.close();
            break;
            
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case 't':
            kinect.enableDepthNearValueWhite(!kinect.isDepthNearValueWhite());
            break;
            
        case'-':
            scaleY -=.01;
            break;
        case '=':
            scaleY +=.01;
            break;
        case'[':
            scaleX -=.01;
            break;
        case ']':
            scaleX +=.01;
            break;
    }
    
}


