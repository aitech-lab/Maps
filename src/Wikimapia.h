#pragma once
#include "ofMain.h"
#include "ofxJSONElement.h"

class Wikimapia {

public:
	Wikimapia(void);
	~Wikimapia(void);

	void load(string url);
	void Wikimapia::urlResponse(ofHttpResponse & response);

private:
	ofxJSONElement _json;

	
};

