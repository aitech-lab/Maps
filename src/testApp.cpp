#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetWindowTitle("Ailove-Maps");
	ofBackground(0);
	// 37.595366 55.731480
	// 37.618160 55.724034
	// http://api.wikimapia.org/?function=box&lon_min=37.595366&lat_min=55.724034&lon_max=37.618160&lat_max=55.731480&key=B5AC2882-449F2B81-16B63FE8-CBB00E11-8DE5B963-6DD96FB4-CF5B3C60-E8882F28&pack=gzip

	string url = 
		"http://api.wikimapia.org/"
		"?function=box"
		"&lon_min=37.595366"
		"&lat_min=55.724034"
		"&lon_max=37.618160"
		"&lat_max=55.731480"
		"&key=B5AC2882-449F2B81-16B63FE8-CBB00E11-8DE5B963-6DD96FB4-CF5B3C60-E8882F28"
		"&pack=gzip";
	
	//string url = "http://api.wikimapia.org/?key=B5AC2882-449F2B81-16B63FE8-CBB00E11-8DE5B963-6DD96FB4-CF5B3C60-E8882F28&function=box&x=687&y=328&z=10&format=json";
	
	wikimapia.load(url);
}


//--------------------------------------------------------------
void testApp::update() {

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
