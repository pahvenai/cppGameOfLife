#include "dataTypes.h"
#include "Grid.h"
#include "Conway.h"


	Conway::Conway(int grid_sz) : X(grid_sz), Y(grid_sz) {
		grid = Grid(X,Y);
	}

	boolean2dVector Conway::updateGrid(Grid oldGrid){
		boolean2dVector newGrid = boolean2dVector(X, booleanVector(Y, false));
		for (int xPos=0; xPos<X; xPos++){
			for (int yPos=0; yPos < Y; yPos++){
				int n_neighbors = oldGrid.n_active(xPos, yPos);
				if (oldGrid.gridi[xPos][yPos]){
					if ((n_neighbors == LIVE1) || (n_neighbors == LIVE2)){
						newGrid[xPos][yPos] = true;
					}
				}
				else if (n_neighbors == REPRODUCE1) newGrid[xPos][yPos] = true;
			}
		}
		return newGrid;
	}

