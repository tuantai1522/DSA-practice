//https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

bool dfs(int start, int color, vector<int>adj[], vector<int>& visited) {
	visited[start] = color;

	for (auto node : adj[start]) {
		if (visited[node] == -1) {
			if (dfs(node, !color, adj, visited) == false) {
				return false;
			}
		}
		else {
			if (visited[node] == color) {
				return false;
			}
		}
	}
	return true;
}

bool isBipartite_dfs(int V, vector<int>adj[]) {
	vector<int>visited(V, -1);
	for (int i = 0; i < V; ++i) {
		if (visited[i] == -1) {
			if (dfs(i, 0, adj, visited) == false) {
				return false;
			}
		}
	}
	return true;
}

bool bfs(int V, vector<int>adj[], vector<int>& visited) {
	queue<int>my_queue;

	//-1: not visited
	//0: first color
	//1: second color

	my_queue.push(V);
	visited[V] = 0;

	while (!my_queue.empty()) {
		int top = my_queue.front();
		my_queue.pop();

		for (auto node : adj[top]) {
			if (visited[node] == -1) {
				visited[node] = !visited[top];
				my_queue.push(node);
			}
			else {
				if (visited[top] == visited[node]) {
					return false;
				}
			}
		}
	}

	return true;
}

bool isBipartite_bfs(int V, vector<int>adj[]) {
	vector<int>visited(V, -1);
	for (int i = 0; i < V; ++i) {
		if (visited[i] == -1) {
			if (bfs(i, adj, visited) == false) {
				return false;
			}
		}
	}
	return true;
}