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
            dale[a] = new dales(i*daleSize+20,j*daleSize+20,   // dales position
                                daleSize,nDales,                 // dales infos
                                i,j);             //dales uv bot
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
