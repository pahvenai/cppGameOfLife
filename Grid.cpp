#include "dataTypes.h"
#include "Grid.h"

	Grid::Grid(int x, int y) : sizeX(x), sizeY(y) {
		gridi = boolean2dVector(sizeX, booleanVector(sizeY, false));
	}

	int Grid::translateX (int x, int xStep){
		int newX = x+xStep;
		while (newX > sizeX) newX = newX - sizeX;
		while (newX < 0) newX = sizeX + newX;
		return newX;
	}
	int Grid::translateY (int y, int yStep){
		int newY = y+yStep;
		while (newY > sizeY) newY = newY - sizeY;
		while (newY < 0) newY = sizeY + newY;
		return newY;
	}

	int Grid::n_active (int x, int y) {
		int count = 0;
		if (gridi[x][translateY(y,1)]) count ++;
		if (gridi[translateX(x,1)][y]) count ++;
		if (gridi[translateX(x,1)][translateY(y,1)]) count ++;
		if (gridi[translateX(x,1)][translateY(y,-1)]) count ++;
		if (gridi[x][translateY(y,-1)]) count ++;
		if (gridi[translateX(x,-1)][y]) count ++;
		if (gridi[translateX(x,-1)][translateY(y,-1)]) count ++;
		if (gridi[translateX(x,-1)][translateY(y,1)]) count ++;
		return count;
	}


