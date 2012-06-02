#ifndef _MAP_TILE_
#define _MAP_TILE_

#include "ofMain.h"

class Tile {
public:
	Tile(void);
	~Tile(void);
	void urlResponse(ofHttpResponse & response);
	void load(int x, int y, int z);
	string url;
	string name;
	unsigned __int64 key;
	ofImage img;
	int id;
	
	unsigned __int64 x64, y64, z64;


	static map<unsigned __int64, ofBuffer> cache;
	static unsigned int tileId;
};

#endif

