#ifndef CONWAY_H
#define CONWAY_H

#include "Grid.h"
#include "dataTypes.h"
#include <vector>
#include <ostream>

class Conway{
	private:
	        int X, Y;
	        Grid grid = Grid(0,0);
	        const int LIVE1 = 2;
	        const int LIVE2 = 3;
	        const int REPRODUCE1 = 3;

        public:
       		Conway(int grid_sz);
		// Updates the grid
	        void updateGrid();
		// returns and updated grid, based on the given grid
	        boolean2dVector updatedGrid(Grid oldGrid);
		void setAlive(std::vector<int> XCoords, std::vector<int> YCoords, int xPos, int yPos);
	        friend std::ostream& operator<< (std::ostream& stream, const Conway& peli);

};

#endif /* CONWAY_H */
