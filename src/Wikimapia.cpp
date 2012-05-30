#include "Wikimapia.h"


Wikimapia::Wikimapia(void) {

	ofRegisterURLNotification(this);
}


Wikimapia::~Wikimapia(void)
{
}

void Wikimapia::load(string url)  {
	ofLoadURLAsync(url);

}

// When we receive an url response this method is called; 
// The loaded image is removed from the async_queue and added to the
// update queue. The update queue is used to update the texture.
//--------------------------------------------------------------
void Wikimapia::urlResponse(ofHttpResponse & response) {
	if(response.status == 200) {

		_json = ofxJSONElement(response.data);

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

