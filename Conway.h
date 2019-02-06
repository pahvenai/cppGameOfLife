#ifndef CONWAY_H
#define CONWAY_H

#include "Grid.h"
#include "dataTypes.h"

class Conway{
	private:
	        int X, Y;
	        Grid grid = Grid(0,0);
	        const int LIVE1 = 2;
	        const int LIVE2 = 3;
	        const int REPRODUCE1 = 3;

        public:
       		Conway(int grid_sz);
	        boolean2dVector updateGrid(Grid oldGrid);

};

#endif /* CONWAY_H */
