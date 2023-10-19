//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
bool dfs(int childNode, int parentNode, vector<int> adj[], vector<int>& visited) {
	visited[childNode] = 1;
	for (auto it : adj[childNode]) {
		if (!visited[it]) {
			if (dfs(it, childNode, adj, visited) == true) {
				return true;
			}
		}
		//if this it node is not a node before current Node
		else if (it != parentNode) {
			return true;
		}
	}

	return false;
}
bool isCycle_dfs(int V, vector<int> adj[]) {
	vector<int>visited(V);

	for (int i = 0; i < V; ++i) {
		if (!visited[i]) {
			if (dfs(i, -1, adj, visited) == true) return true;
		}
	}
	return false;
}

//BFS
bool isCycle_bfs(int V, vector<int> adj[]) {
	vector<int>visited(V);
	queue<vector<int>>my_queue;

	for (int i = 0; i < V; ++i) {
		if (!visited[i]) {

			//first Node in new components = > don't have parent
			my_queue.push({ i, -1 });
			visited[i] = 1;

			while (!my_queue.empty()) {
				vector<int>top = my_queue.front();
				int childNode = top[0];
				int parentNode = top[1];
				my_queue.pop();

				for (auto it : adj[childNode]) {
					if (!visited[it]) {
						my_queue.push({ it, childNode });
						visited[it] = 1;
					}
					else {
						if (it != parentNode) {
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}