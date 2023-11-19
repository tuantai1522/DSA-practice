//https://leetcode.com/problems/number-of-provinces/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
void dfs(int vertex, vector<vector<int>>adj, vector<int>& visited) {
	visited[vertex] = 1;

	for (int i = 0; i < adj.size(); ++i) {
		//if there is connection between this vertex and other nodes and this node is not visited
		if (adj[vertex][i] == 1 && visited[i] == 0) {
			dfs(i, adj, visited);
		}
	}
}
int findCircleNum(vector<vector<int>>& isConnected) {
	int numberOfNodes = isConnected.size();

	vector<int>visited(numberOfNodes);
	int ans = 0;

	for (int i = 0; i < numberOfNodes; ++i) {
		if (visited[i] == 0) {
			dfs(i, isConnected, visited);
			++ans;
		}
	}
	return ans;
}