//https://leetcode.com/problems/rotting-oranges/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
	int rows = grid.size();
	int columns = grid[0].size();

	//to find position of rotten oranges
	queue<vector<int>>my_queue;

	int freshOranges = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (grid[i][j] == 2) {
				my_queue.push({ i, j });
			}
			if (grid[i][j] == 1) {
				freshOranges++;
			}
		}
	}
	if (freshOranges == 0) return 0;
	if (my_queue.empty()) return -1;

	//use bfs
	int ans = 0;
	while (!my_queue.empty()) {
		int size = my_queue.size();
		while (size--) {
			vector<int> top = my_queue.front();
			my_queue.pop();

			int row = top[0];
			int column = top[1];
			//check top of current rotten oranges
			if (row > 0 && grid[row - 1][column] == 1) {
				my_queue.push({ row - 1, column });
				grid[row - 1][column] = 2;
				freshOranges--;
			}

			//check bottom of current rotten oranges
			if (row + 1 < rows && grid[row + 1][column] == 1) {
				my_queue.push({ row + 1, column });
				grid[row + 1][column] = 2;
				freshOranges--;
			}

			//check left of current rotten oranges
			if (column > 0 && grid[row][column - 1] == 1) {
				my_queue.push({ row, column - 1 });
				grid[row][column - 1] = 2;
				freshOranges--;
			}

			//check right of current rotten oranges
			if (column + 1 < columns && grid[row][column + 1] == 1) {
				my_queue.push({ row, column + 1 });
				grid[row][column + 1] = 2;
				freshOranges--;
			}
		}
		if (!my_queue.empty())++ans;

	}


	return freshOranges == 0 ? ans : -1;
}