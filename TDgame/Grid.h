#pragma once
class Grid
{
public:
	Grid(int row, int column);
	Grid();
	~Grid();
	
	void changeGrid(int row, int column);

	int mapgrid[25][25];


};

