#pragma once
#include "ofMain.h"
#include "ofxJSONElement.h"

class Wikimapia {

public:
	Wikimapia(void);
	~Wikimapia(void);

	void load(string url);
	void load(int x, int y, int z);
	void urlResponse(ofHttpResponse & response);
	void draw();
	void parseJson();
	
	static string baseUrl;
	static string key;


	unsigned int numPoints; 
	ofVboMesh vbo;
private:
	ofxJSONElement _json;

	
};

