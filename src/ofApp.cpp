#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
#ifdef TARGET_OPENGLES
    shader.load("shadersES2/shader");
#else
    if(ofIsGLProgrammableRenderer()){
        shader.load("shadersGL3/shader");
    }else{
        shader.load("shadersGL2/shader");
    }
#endif
    
    ofSetVerticalSync(true);
     ofSetupScreenOrtho();
    
    backgroundImage.loadImage("bg.jpg");
    foregroundImage.loadImage("text.ppg");
    
    
    int width = backgroundImage.getWidth();
    int height = backgroundImage.getHeight();
    
    maskFbo.allocate(width, height);
    fbo.allocate(width, height);
    
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
    
    fbo.begin();
    ofClear(0,0,0,255);
    fbo.end();
    
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
    
    maskFbo.begin();
    ofClear(0,0,0,255);
    maskFbo.end();
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    
     maskFbo.begin();
    for( int i =0; i<nDales*nDales;i++)
    {
        dale[i]->draw();
    }
    maskFbo.end();
    
    fbo.begin();
    ofClear(0, 0, 0, 255);
    shader.begin();
    // here is where the fbo is passed to the shader
    shader.setUniformTexture("maskTex", maskFbo.getTextureReference(), 1 );
    
    backgroundImage.draw(0, 0);
    
    shader.end();
    fbo.end();
    foregroundImage.draw(0,0);
    
    // THEN draw the masked fbo on top
    fbo.draw(0,0);
}
