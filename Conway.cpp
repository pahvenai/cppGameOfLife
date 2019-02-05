#include "dataTypes.h"

class Conway{
	int X, Y;
	boolean2DVector grid;
};

Conway::Conway(int grid_size) : X(grid_size), Y(grid_size) {}
