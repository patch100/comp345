#pragma once
class Grid
{
public:
	bool mapgrid[25][25];



	Grid(int row, int column);
	Grid();
	~Grid();
	
	void changeGrid(int row, int column);

	


};

