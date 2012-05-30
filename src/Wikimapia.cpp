#include "Wikimapia.h"


Wikimapia::Wikimapia(void) {

	ofRegisterURLNotification(this);
	vbo.setMode(OF_PRIMITIVE_POINTS);

}


Wikimapia::~Wikimapia(void) {
}

void Wikimapia::load(string url)  {
	ofLoadURLAsync(url);
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

