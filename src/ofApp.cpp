#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
     ofSetupScreenOrtho();
    
 
    nDales =4;
    daleSize = 30;
    dale = new dales*[nDales];
    
    a =0;
    for( int i =0; i<nDales;i++)
    {
        for( int j =1; j<nDales;j++ )
        {
        dale[j*i] = new dales(i*daleSize+200,j*daleSize+200,daleSize+ofRandom(10));

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
