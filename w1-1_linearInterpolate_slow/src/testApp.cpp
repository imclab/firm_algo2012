#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    ofSetWindowShape(1500, 500);
	
	// set background: 
	
	ofBackground(50,50,50);
    
	// set the "a" and "b" positions of the rectangle...
    
	
	slowRect.posa.x = 100;
	slowRect.posa.y = ofGetHeight()/3;
    slowRect.posb.x = ofGetWidth()-100;
	slowRect.posb.y = ofGetHeight()/3;
    
	slowRect.interpolateByPct(0);           // start at 0 pct
	slowPct = 0;							// a variable we can alter...
	
    
	fastRect.posa.x = 100;
	fastRect.posa.y = ofGetHeight()*2/3;
    fastRect.posb.x = ofGetWidth()-100;
	fastRect.posb.y = ofGetHeight()*2/3;
    
	fastRect.interpolateByPct(0);           // start at 0 pct
	fastPct = 0;							// a variable we can alter...
	
	
} 

//--------------------------------------------------------------
void testApp::update(){
    
	// to see pct in the console
	//printf("%f \n", pct);
	 
    
	//slowest speed
    slowPct += 0.00001f;
	
    if (fastPct > 1) {
		slowPct = 0;						// just between 0 and 1 (0% and 100%)
	}
	slowRect.interpolateByPct(slowPct);		// go between pta and ptb
    
	//fastest speed
    fastPct += 0.05f;
	
    if (fastPct > 1) {
		fastPct = 0;						// just between 0 and 1 (0% and 100%)
	}	
	fastRect.interpolateByPct(fastPct);		// go between pta and ptb

        
    // refresh window relative position
	slowRect.posa.x = 100;
	slowRect.posa.y = ofGetHeight()/3;
    slowRect.posb.x = ofGetWidth()-100;
	slowRect.posb.y = ofGetHeight()/3;
    
    
	fastRect.posa.x = 100;
	fastRect.posa.y = ofGetHeight()*2/3;
    fastRect.posb.x = ofGetWidth()-100;
	fastRect.posb.y = ofGetHeight()*2/3;
    
}

//--------------------------------------------------------------
void testApp::draw(){
    /*
    ofSetColor(255, 255, 255);
    ofSetLineWidth(1);
    ofLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    
    ofSetColor(155, 155, 155);
    ofSetLineWidth(3);
    
    ofCircle(startPoint.x, startPoint.y, 5);
    ofCircle(endPoint.x, endPoint.y, 5);
     
     */
    
	slowRect.draw();
    fastRect.draw();
    
    ofDrawBitmapString("0.005 inch per second", 100, 100);
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    

    if(key == 'f'||key == 'F'){
		ofToggleFullscreen();
        
        /*
        bFullscreen = !bFullscreen;
		if(!bFullscreen){
			ofSetFullscreen(false);
		} else if(bFullscreen == 1){
			ofSetFullscreen(true);
		}
        */
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	//myRectangle.posa.x = x;
	//myRectangle.posa.y = y;
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
