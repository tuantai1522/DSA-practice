//https://leetcode.com/problems/max-area-of-island/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(vector<vector<int>>& grid, int x, int y, int r, int c, int& area) {
	if (x < 0 || x >= r || y < 0 || y >= c || grid[x][y] != 1) {
		return;
	}
	//mark this cell as visited and iterate that cell
	//mark this cell as visited
	grid[x][y] = 2;
	++area;

	dfs(grid, x - 1, y, r, c, area); //TOP
	dfs(grid, x + 1, y, r, c, area); //DOWN
	dfs(grid, x, y + 1, r, c, area); //LEFT
	dfs(grid, x, y - 1, r, c, area); //RIGHT
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
	int rows = grid.size();
	int columns = grid[0].size();

	int ans = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (grid[i][j] == 1) {
				int area = 0;
				dfs(grid, i, j, rows, columns, area);
				ans = max(ans, area);

			}
		}
	}
	return ans;
}