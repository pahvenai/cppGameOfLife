#include "dataTypes.h"
#include "Grid.h"
#include <iomanip>

	Grid::Grid(int x, int y) : sizeX(x), sizeY(y) {
		gridi = boolean2dVector(sizeX, booleanVector(sizeY, false));
	}

	int Grid::translateX (int x, int xStep){
		int newX = x+xStep;
		while (newX > sizeX-1) newX = newX - sizeX;
		while (newX < 0) newX = sizeX + newX;
		return newX;
	}
	int Grid::translateY (int y, int yStep){
		int newY = y+yStep;
		while (newY > sizeY-1) newY = newY - sizeY;
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

	void Grid::clearNeighbors(int x, int y){
		gridi[x][translateY(y,1)] = false;
		gridi[translateX(x,1)][y] = false;
		gridi[translateX(x,1)][translateY(y,1)] = false;
		gridi[translateX(x,1)][translateY(y,-1)] = false;
		gridi[x][translateY(y,-1)] = false;
		gridi[translateX(x,-1)][y] = false;
		gridi[translateX(x,-1)][translateY(y,-1)] = false;
		gridi[translateX(x,-1)][translateY(y,1)] = false;
	}


	std::ostream& operator<< (std::ostream& stream, const Grid& outputGrid){
		stream << "Grid of size: " << outputGrid.gridi.size() << " x " << outputGrid.gridi[0].size() << std::endl; 
		for (int ii=0; ii<outputGrid.gridi.size(); ii++){
			stream << std::setw(4) << ii+1 <<  ":" ;
			for (int jj=0; jj<outputGrid.gridi[ii].size(); jj++){
				stream << outputGrid.gridi[ii][jj];
			}
			stream << "\n";
		}
		return stream;
	}
