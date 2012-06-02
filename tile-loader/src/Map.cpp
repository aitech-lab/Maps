#include "Map.h"

#include "testApp.h"

Map::Map(void) : 
tileSize(256),
tileX(0),
tileY(0),
tileW(5),
tileH(3),
zoom(2),
maxZoom(14) {
	updateTiles();
}

Map::~Map(void) {
	while(tiles.size()) {
		delete tiles.back();
		tiles.pop_back();
	}
}

void Map::drawGrid(void) {

}

void Map::updateTiles() {

	int yId = tileY - tileH / 2;
	unsigned int tileId = 0;
	for(int yy=0; yy<tileH; yy++) {
		int xId = tileX - tileW / 2;
		for(int xx=0; xx<tileW; xx++) {
			if(tiles.size() == tileId) {
				tiles.push_back(new Tile());
			}
			tiles[tileId]->load(xId, yId, zoom);
			tileId++;
			xId++;
		}
		yId++;
	}

}

void Map::draw(int x, int y) {
	
	int yId, xId;

	ofTrueTypeFont& font = (*(testApp*)ofGetAppPtr()).font1;

	ofNoFill();
	
	ofSetHexColor(0xFFFFFF);	
	unsigned int tileId = 0;
	yId = tileY - tileH / 2;
	for(int yy=0; yy<tileH; yy++) {
		xId = tileX - tileW / 2;
		for(int xx=0; xx<tileW; xx++) {
			//ofRect(tx , ty, tileSize, tileSize);
			Tile& t = *tiles[tileId];
			if(t.img.isAllocated()) 
				t.img.draw(x+xx*tileSize, y+yy*tileSize);
			tileId++;
			//font.drawString(ofToString(sx)+":"+ofToString(sy), tx+1, ty+14);
			xId++;
		}
		yId++;
	}

	ofSetHexColor(0x20202020);
	ofEnableAlphaBlending();
	tileId=0;
	yId = tileY - tileH / 2;
	for(int yy=0; yy<tileH; yy++) {
		xId = tileX - tileW / 2;
		for(int xx=0; xx<tileW; xx++) {
			Tile& t = *tiles[tileId];
			ofRect(x+xx*tileSize, y+yy*tileSize, tileSize, tileSize);
			font.drawString(ofToString(t.x64)+":"+ofToString(t.y64), 
				x+xx*tileSize+1, y+yy*tileSize+14);
			tileId++;
			xId++;
		}
		yId++;
	}


}

void Map::shiftLeft (){
	tileX--;
	updateTiles();
};

void Map::shiftRight (){
	tileX++;
	updateTiles();
};

void Map::shiftUp (){
	tileY++;
	updateTiles();
};

void Map::shiftDown (){
	tileY--;
	updateTiles();
};

void Map::zoomIn (){
	if(zoom<=maxZoom) {
		zoom++;
		tileX<<=1;
		tileY<<=1;
		updateTiles();
	};
};

void Map::zoomOut (){
	if (zoom>0) {
		zoom--;
		tileX>>=1;
		tileY>>=1;
		updateTiles();
	}
};
