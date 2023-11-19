//https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze
#include<bits/stdc++.h>
using namespace std;
int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
  int N = grid.size(); // row
  int M = grid[0].size(); // column

  queue<pair<int, pair<int, int>>> my_queue;
  my_queue.push({0, {source}});

  grid[source.first][source.second] = -1; //level 0
  while(!my_queue.empty()){
    auto it = my_queue.front();
    my_queue.pop();
    int level = it.first;
    pair<int,int> pos = it.second;

    int row = pos.first;
    int column = pos.second;
    
    if(row == destination.first && column == destination.second) {
      return level;
    }

    //is correct, not visited, and grid[row][column] = 1 (can go)

    //check left
    if(column > 0 && grid[row][column - 1] == 1){
      my_queue.push({level + 1, {row, column - 1}});
      grid[row][column - 1] = -1;
    }

    //check top
    if(row > 0 && grid[row - 1][column] == 1){
      my_queue.push({level + 1, {row - 1, column}});
      grid[row - 1][column] = -1;
    }
    //check right
    if(column + 1 < M && grid[row][column + 1] == 1){
      my_queue.push({level + 1, {row, column + 1}});
      grid[row][column + 1] = -1;
    }
    //check bottom
    if(row + 1 < N && grid[row + 1][column] == 1){
      my_queue.push({level + 1, {row + 1, column}});
      grid[row + 1][column] = level + 1;
    }
    ++level;
  }

  return -1;
}