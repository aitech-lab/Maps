#include "Wikimapia.h"

string Wikimapia::baseUrl = "http://api.wikimapia.org/";
string Wikimapia::key     = "B5AC2882-449F2B81-16B63FE8-CBB00E11-8DE5B963-6DD96FB4-CF5B3C60-E8882F28";


Wikimapia::Wikimapia(void) {

	ofRegisterURLNotification(this);
	vbo.setMode(OF_PRIMITIVE_POINTS);

}


Wikimapia::~Wikimapia(void) {
}

void Wikimapia::load(string url)  {
	ofLoadURLAsync(url);
}

void Wikimapia::load(int x, int y, int z)  {
	string url = baseUrl+
		"?function=box"
		"&key="+key+
		"&format=json"
		"&cound=10"
		"&page=1"
		"&x="+ofToString(x)+
		"&y="+ofToString(y)+
		"&z="+ofToString(z);
	cout << url << "\n";
	load(url);
}


void Wikimapia::urlResponse(ofHttpResponse & response) {

	if(response.status == 200) {

		_json = ofxJSONElement(string(response.data));
		parseJson();

//		lock();
//		
//		// Get the loaded url from the async queue and move it into the update queue.
//		entry_iterator it = getEntryFromAsyncQueue(response.request.name);
//		if(it != images_async_loading.end()) {
//			(*it).image->loadImage(response.data);
//			images_to_update.push_back((*it));
//			images_async_loading.erase(it);
//		}
//		
//		unlock();
	} else {
		// log error.
		stringstream ss;
		ss << "Could not load from url, response status: " << response.status;
		ofLog(OF_LOG_ERROR, ss.str());

	}
}

void Wikimapia::draw() {
	//ofEnablePointSprites();
	vbo.drawVertices();
}

void Wikimapia::parseJson() {
	vbo.clear();
	//cout<<_json.toStyledString() << "\n";
	for(int i=0; i<_json["folder"].size(); i++) {
		for(int j=0; j<_json["folder"][i]["polygon"].size(); j++) {
			double x = (_json["folder"][i]["polygon"][j]["x"].asDouble()-37.606763)*20000.0;
			double y =-(_json["folder"][i]["polygon"][j]["y"].asDouble()-55.727757)*36000.0;
			vbo.addVertex(ofVec2f(x,y));
			vbo.addColor(ofColor(255,255,255,255));
			//cout << x << "\t" << y << "\n";
		}
	}	
}

