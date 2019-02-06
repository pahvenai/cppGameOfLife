#include "dataTypes.h"
#include "Grid.h"
#include "Conway.h"
#include <iostream>

	Conway::Conway(int grid_sz) : X(grid_sz), Y(grid_sz) {
		grid = Grid(X,Y);
	}

	void Conway::updateGrid(){
		grid.gridi = updatedGrid(grid);
	}


	boolean2dVector Conway::updatedGrid(Grid oldGrid){
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


	// The array of relative coordinates are set to true, centered at xPos, yPos
	// Behavior not defined if the pattern is larger than the grid
	void Conway::setAlive(std::vector<int> XCoords, std::vector<int> YCoords, int xPos, int yPos){
		if (XCoords.size() != YCoords.size()) throw "Vector size mismatch error!";
		// Clear neighbors to have "clean" space
		for (int ii=0; ii<XCoords.size(); ii++){
			grid.clearNeighbors(XCoords[ii]+xPos, YCoords[ii]+yPos);
		}
		// insert actual pattern
		for (int ii=0; ii<XCoords.size(); ii++){
			// translateX and translateY give "legal", periodic boundary positions
			grid.gridi[grid.translateX(XCoords[ii],xPos)][grid.translateY(YCoords[ii],yPos)] = true;
		}

	}


        std::ostream& operator<< (std::ostream& stream, const Conway& peli){
		stream << peli.grid;
		return stream;
        }

