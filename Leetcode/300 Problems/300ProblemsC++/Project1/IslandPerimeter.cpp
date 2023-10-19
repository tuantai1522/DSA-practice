//https://leetcode.com/problems/island-perimeter/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(vector<vector<int>>& grid, int x, int y, int r, int c, int &peri) {
	if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == 0) {
		++peri;
		return;
	}
	//mark this cell as visited and iterate ONLY that cell
	if (grid[x][y] == 1) {
		grid[x][y] = 2;
		dfs(grid, x - 1, y, r, c, peri); //TOP
		dfs(grid, x + 1, y, r, c, peri); //DOWN
		dfs(grid, x, y + 1, r, c, peri); //LEFT
		dfs(grid, x, y - 1, r, c, peri); //RIGHT
	}

}
int islandPerimeter(vector<vector<int>>& grid) {
	int rows = grid.size();
	int columns = grid[0].size();

	int peri = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (grid[i][j] == 1) {
				dfs(grid, i, j, rows, columns, peri);
				break;
			}
		}
	}
	return peri;
}