#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
     ofSetupScreenOrtho();
    
 
    nDales =10;
    daleSize = 30;
    dale = new dales*[nDales];
    
    for( int i =0; i<nDales;i++)
    {
        for( int j =0; j<nDales;j++)
        {
        dale[j] = new dales(daleSize/2+i*daleSize,10+j*daleSize,daleSize);
        
        }
    }
 

}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i =0; i<nDales;i++)
    {
        dale[i]->update();
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    for( int i =0; i<nDales;i++)
    {
        dale[i]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
