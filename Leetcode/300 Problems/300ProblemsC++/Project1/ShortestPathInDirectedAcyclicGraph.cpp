//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph
#include<bits/stdc++.h>
using namespace std;

//from 0 to find shorted path to another nodes
void TopoList(int node,  vector<vector<pair<int, int>>> adjacent, vector<int>&visited, stack<int>&Topo){
    // STEP 1:
    // Construct adjacentList and indegree
    
    visited[node] = 1;
    for (auto it : adjacent[node]) { // Sử dụng M thay vì N để lặp qua danh sách cạnh
        int start = it.first;

        if(!visited[start]) {
          TopoList(start, adjacent, visited, Topo);
        }
        
    }
    Topo.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>> > adjacent(N); // Sử dụng pair để lưu trọng số của cạnh

    for (int i = 0; i < M; ++i) { // Sử dụng M thay vì N để lặp qua danh sách cạnh
        int start = edges[i][0];
        int end = edges[i][1];
        int weight = edges[i][2];
        
        adjacent[start].push_back({end, weight}); // Thêm cạnh vào danh sách kề
    }
    
    vector<int>visited(N);
    stack<int>Topo;

    for(int i = 0; i < N; ++i){
      if(!visited[i]){
        TopoList(i, adjacent, visited, Topo);
      }
    }

    vector<int>distance(N, INT_MAX);
    distance[0] = 0;
    while(!Topo.empty()){
      int node = Topo.top();
      Topo.pop();

        // Updating the distance to the adjacent nodes if a shorter path is found
        if (distance[node] != INT_MAX) {
              for(auto it : adjacent[node]){
                int v = it.first;
                int weight = it.second;
        
                distance[v] = min(distance[v], distance[node] + weight);
              }
            }
        }

        // Converting unreachable nodes to -1
        for (int i = 0; i < adjacent.size(); ++i) {
            if (distance[i] ==  INT_MAX) distance[i] = -1;
        }

    return distance;
}