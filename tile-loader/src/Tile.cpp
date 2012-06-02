#include "Tile.h"

map<unsigned __int64, ofBuffer> Tile::cache;

unsigned int Tile::tileId = 0;


Tile::Tile(void) :
name(""),
url(""),
id(-1){
	id = tileId++;
}


Tile::~Tile(void) {
	cout << "Tile dtor" << "\n";
}
// http://a.tiles.mapbox.com/v3/mapbox.mapbox-streets/9/312/161.png
void Tile::load(int x, int y, int z) {

	unsigned __int64 d = powl(2, z);
	x %= d; y %=d;
	x64 = (x<0) ? d+x : x;
	y64 = (y<0) ? d+y : y;
	z64 = z;

 	key = (z64<<32) | (x64<<16) | y64;

	if(cache.count(key)) {
		img.loadImage(cache[key]);
		return;
	}
	img.clear();
	// 
	//name = "v=112&src=app&x="+ofToString(x)+"&s=&y="+ofToString(y)+"&z="+ofToString(z)+"&s=Galileo";
	//url="https://khms1.google.ru/kh/"+name+".png";
	name = ofToString(z)+"/"+ofToString(x)+"/"+ofToString(y);
	url="http://a.tiles.mapbox.com/v3/mapbox.mapbox-streets/"+name+".png";
	
	ofRegisterURLNotification(this);
	cout << url << "\n";
	ofLoadURLAsync(url, ofToString(id)+":"+name);
}

void Tile::urlResponse(ofHttpResponse & response) {
	cout << response.request.name << "\n";
	if(response.status == 200 ) {
		if (response.request.name == ofToString(id)+":"+name) {
			ofUnregisterURLNotification(this);
			cache[key] = response.data;
			img.loadImage(response.data);

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
		}
	} else {
		// log error.
		stringstream ss;
		ss << "Could not load from url, response status: " << response.status;
		ofLog(OF_LOG_ERROR, ss.str());

	}

}
