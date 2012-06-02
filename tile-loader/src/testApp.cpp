#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {

	ofSetWindowTitle("Tile-Loader");
	font1.loadFont("fonts\\OpenSans-CondLight.ttf", 12);
	font2.loadFont("fonts\\OpenSans-CondLight.ttf", 24);
	ofBackground(0);

	tile.load(8,8,4);
	
}


//--------------------------------------------------------------
void testApp::update() {

}

//--------------------------------------------------------------
void testApp::draw() {
	ofSetHexColor(0xffffff);
	
	//ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);

	//if (tile.img.isAllocated()) tile.img.draw(0,0);

	map.draw(0, 0);

	// ofSetColor(255);
	// font1.drawString("Abcdefg", 10, 20);
	// font2.drawString("Abcdefg", 10, 50);

}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	
	if (key == 27) return;

	if(key=='4' || key==356) map.shiftLeft ();
	if(key=='6' || key==358) map.shiftRight();
	if(key=='8' || key==357) map.shiftUp   ();
	if(key=='2' || key==359) map.shiftDown ();
	if(key=='+') map.zoomIn    ();
	if(key=='-') map.zoomOut   ();
	
	tile.load(map.tileX, map.tileY, map.zoom);

	//wikimapia.load(x,y,z);
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
