#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetWindowTitle("Ailove-Maps");
	ofBackground(0);
	string url = "http://api.wikimapia.org/?key=B5AC2882-449F2B81-16B63FE8-CBB00E11-8DE5B963-6DD96FB4-CF5B3C60-E8882F28&function=box&x=687&y=328&z=10&format=json";
}


//--------------------------------------------------------------
void testApp::update() {
	instagram.update();
}

//--------------------------------------------------------------
void testApp::draw() {	
	int xc = ofGetWidth() / 150; 
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
