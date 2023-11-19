//https://leetcode.com/problems/flood-fill/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

void markCell(vector<vector<int>>& image, int sr, int sc, int color, int rows, int columns, int source) {
	if (sr < 0 || sr >= rows || sc < 0 || sc >= columns || image[sr][sc] != source) {
		return;
	}

	image[sr][sc] = color;

	markCell(image, sr - 1, sc, color, rows, columns, source);//TOP
	markCell(image, sr + 1, sc, color, rows, columns, source);//DOWN
	markCell(image, sr, sc - 1, color, rows, columns, source);//LEFT
	markCell(image, sr, sc + 1, color, rows, columns, source);//RIGHT
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	if (color == image[sr][sc]) return image;
	int rows = image.size();
	int columns = image[0].size();
	int source = image[sr][sc];
	markCell(image, sr, sc, color, rows, columns, source);

	return image;
}