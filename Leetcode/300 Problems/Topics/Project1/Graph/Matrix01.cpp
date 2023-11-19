//https://leetcode.com/problems/01-matrix/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
	int rows = grid.size();
	int columns = grid[0].size();

	queue<vector<int>>my_queue;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			if (grid[i][j] == 0) {
				//my_queue: indexI, indexJ, valueIJ
				my_queue.push({ i, j });
			}
			else {
				grid[i][j] = -1; //mark as not visited
			}
		}
	}

	if (my_queue.empty()) return grid;

	while (!my_queue.empty()) {
		vector<int> top = my_queue.front();
		my_queue.pop();

		int row = top[0];
		int column = top[1];
		//check top of current cell
		if (row > 0 && grid[row - 1][column] == -1) {
			my_queue.push({ row - 1, column });
			grid[row - 1][column] = grid[row][column] + 1;

		}

		//check bottom of current cell
		if (row + 1 < rows && grid[row + 1][column] == -1) {
			my_queue.push({ row + 1, column });
			grid[row + 1][column] = grid[row][column] + 1;

		}

		//check left of current cell
		if (column > 0 && grid[row][column - 1] == -1) {
			my_queue.push({ row, column - 1 });
			grid[row][column - 1] = grid[row][column] + 1;


		}

		//check right of current cell
		if (column + 1 < columns && grid[row][column + 1] == -1) {
			my_queue.push({ row, column + 1 });
			grid[row][column + 1] = grid[row][column] + 1;
		}
	}

	return grid;

}