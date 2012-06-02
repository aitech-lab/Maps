#ifndef _TILED_MAP_
#define _TILED_MAP_

#include "ofMain.h"
#include "Tile.h"

class Map {

public:
	Map(void);
	~Map(void);

	void draw(int x, int y);
	void drawGrid();

	int tileX;
	int tileW;
	int tileY;
	int tileH;
	int zoom;
	int maxZoom;

	void shiftLeft ();
	void shiftRight();
	void shiftUp   ();
	void shiftDown ();
	void zoomIn    ();
	void zoomOut   ();

	void updateTiles();

	unsigned int tileSize;
	vector<Tile*> tiles;

};

#endif