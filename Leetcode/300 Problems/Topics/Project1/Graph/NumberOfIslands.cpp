//https://leetcode.com/problems/number-of-islands/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
void markCurrentIsland(vector<vector<char>>& grid, int x, int y, int r, int c) {
	if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != '1') {
		return;
	}
	//mark this cell as visited
	grid[x][y] = '2';
	markCurrentIsland(grid, x - 1, y, r, c); //TOP
	markCurrentIsland(grid, x + 1, y, r, c); //DOWN
	markCurrentIsland(grid, x, y + 1, r, c); //LEFT
	markCurrentIsland(grid, x, y - 1, r, c); //RIGHT

}
int numIslands(vector<vector<char>>& grid) {
	int rows = grid.size();
	int columns = grid[0].size();

	int number = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {

			//from current position, we have to mark vertically and horizontally of this position as 2 (processed before)
			if (grid[i][j] - '0' == 1) {
				markCurrentIsland(grid, i, j, rows, columns);
				++number;

			}
		}
	}

	return number;
}