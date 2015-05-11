#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
     ofSetupScreenOrtho();
    
 
    nDales =10;
    daleSize = 50;
    dale = new dales*[nDales*nDales];
    
    a =0;
    for( int i =0; i<nDales;i++)
    {
        
        
        for( int j =0; j<nDales;j++ )
        {
            dale[a] = new dales(j*daleSize,i*daleSize,daleSize+ofRandom(10));
            a++;
        }
    }
 

}

//--------------------------------------------------------------
void ofApp::update(){
    for( int i =0; i<nDales*nDales;i++)
    {
        dale[i]->update();
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    for( int i =0; i<nDales*nDales;i++)
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
