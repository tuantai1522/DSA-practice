//https://practice.geeksforgeeks.org/problems/eventual-safe-states/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

//node who is part of cycle can not be a safe node
//node leads to a cycle can not be safe node

bool dfs(int curNode, vector<int>adj[], vector<int>& visited, vector<int>&pathVisited, vector<int>& check) {
    visited[curNode] = 1;
    pathVisited[curNode] = 1;
    check[curNode] = 0; // mark as not safe nodes;
    for (auto it : adj[curNode]) {
        if (!pathVisited[it] && !visited[it]) {
            if (dfs(it, adj, visited, pathVisited, check) == true) {
                return true; // there is a cycle => all nodes in path are not safe nodes
            }
        }
        //if the node has been previously visited and it is visited on the same path
        else if (pathVisited[it]) {
            return true; // there is a cycle => all nodes in path are not safe nodes
        }
    }

    //mark as path not visited
    pathVisited[curNode] = 0;
    check[curNode] = 1; //after running all codes below, this is safe node
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int>visited(V);
    vector<int>pathVisited(V);
    vector<int>check(V);
    vector<int>ans;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, pathVisited, check);
        }
    }
    for (int i = 0; i < V; ++i) {
        if (check[i] == 1) {
            ans.push_back(i);
        }
    }

    return ans;
}