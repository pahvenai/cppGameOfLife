#ifndef GRID_H
#define GRID_H

#include "dataTypes.h"

class Grid{
	private:
		int sizeX;
		int sizeY;
	public:
		boolean2dVector gridi;

        	Grid(int x, int y);
	        int translateX (int x, int xStep);
	        int translateY (int y, int yStep);
	        int n_active (int x, int y);
};

#endif /* GRID_H */
