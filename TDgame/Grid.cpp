#include "Grid.h"


Grid::Grid(int row, int column)
{



}


Grid::~Grid()
{
}

void Grid::changeGrid(int row, int column)
{
	//This will trigger a switching of the grid array value
	//To be used with User Input method mapSelect, when the player is creating new grid

	if (mapgrid[row][column] == 1)
		mapgrid[row][column] = 0;

	else if (mapgrid[row][column] == 0)
		mapgrid[row][column] = 1;

}
