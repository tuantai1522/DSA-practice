// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
#include <bits/stdc++.h>
using namespace std;
void findPathUti(vector<vector<int>> &matrix, vector<vector<int>> &visited,
                 int n, int row, int column, string temp,
                 vector<string> &ans)
{
  if (row == n - 1 && column == n - 1)
  {
    ans.push_back(temp);
    return;
  }

  if (row + 1 < n &&
      matrix[row + 1][column] == 1 && !visited[row + 1][column])
  {
    visited[row][column] = 1;
    findPathUti(matrix, visited, n, row + 1, column, temp + 'D', ans); // DOWN
    visited[row][column] = 0;
  }

  if (column - 1 >= 0 &&
      matrix[row][column - 1] == 1 && !visited[row][column - 1])
  {
    visited[row][column] = 1;

    findPathUti(matrix, visited, n, row, column - 1, temp + 'L', ans); // LEFT

    visited[row][column] = 0;
  }

  if (column + 1 < n &&
      matrix[row][column + 1] == 1 && !visited[row][column + 1])
  {
    visited[row][column] = 1;
    findPathUti(matrix, visited, n, row, column + 1, temp + 'R', ans); // RIGHT
    visited[row][column] = 0;
  }

  if (row - 1 >= 0 &&
      matrix[row - 1][column] == 1 && !visited[row - 1][column])
  {
    visited[row][column] = 1;
    findPathUti(matrix, visited, n, row - 1, column, temp + 'U', ans); // TOP
    visited[row][column] = 0;
  }
}
vector<string> findPath(vector<vector<int>> &matrix, int n)
{
  vector<string> ans;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  string temp;
  if (matrix[0][0] == 1)
    findPathUti(matrix, visited, n, 0, 0, temp, ans);

  return ans;

  // Your code goes here
}