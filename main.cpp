#include "Conway.h"
#include <vector>
#include <iostream>

int main(int argc, char* argv[]){
	const int GRID_SIZE = 8;
	Conway peli = Conway(GRID_SIZE);

	std::vector<int> xTemp{0, 1, 2, 2, 1};
	std::vector<int> yTemp{0, 0, 0, 1, 2};

	std::cout << xTemp[0];
	std::cout << xTemp[1];
	std::cout << xTemp[2];
	std::cout << xTemp[3];
	peli.setAlive(xTemp, yTemp, 3, 3);

	std::cout << peli << std::endl;
	peli.updateGrid();
	std::cout << peli << std::endl;
	peli.updateGrid();
	std::cout << peli << std::endl;
	peli.updateGrid();
	std::cout << peli << std::endl;
	peli.updateGrid();
	std::cout << peli << std::endl;
	peli.updateGrid();
	std::cout << peli << std::endl;
	peli.updateGrid();
	std::cout << peli << std::endl;


	return 0;
}
