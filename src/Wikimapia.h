#pragma once
#include "ofMain.h"
#include "ofxJSONElement.h"

class Wikimapia {

public:
	Wikimapia(void);
	~Wikimapia(void);

	void load(string url);
	void urlResponse(ofHttpResponse & response);
	void draw();
	void parseJson();
	
	unsigned int numPoints; 
	ofVboMesh vbo;
private:
	ofxJSONElement _json;

	
};

