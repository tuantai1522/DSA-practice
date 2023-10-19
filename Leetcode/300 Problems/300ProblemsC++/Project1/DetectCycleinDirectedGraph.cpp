//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
bool dfs(int curNode, vector<int>adj[], vector<int>& visited, vector<int>& pathVisited) {
    visited[curNode] = 1;
    pathVisited[curNode] = 1;

    for (auto it : adj[curNode]) {
        if (!pathVisited[it] && !visited[it]) {
            if (dfs(it, adj, visited, pathVisited) == true) {
                return true;
            }
        }
        //if the node has been previously visited and it is visited on the same path
        else if (pathVisited[it]) {
            return true;
        }
    }

    //mark as path not visited
    pathVisited[curNode] = 0;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<int>visited(V);
    vector<int>pathVisited(V);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, pathVisited) == true) {
                return true;
            }
        }
    }

    return false;
}