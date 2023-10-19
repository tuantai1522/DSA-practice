//https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance
#include<bits/stdc++.h>
using namespace std;  
vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
  vector<vector<int>>adjacentList(N);
  for(int i = 0; i < M; ++i){
    int u = edges[i][0];
    int v = edges[i][1];
    adjacentList[u].push_back(v);
    adjacentList[v].push_back(u);
  }

  queue<int>my_queue;
  my_queue.push(src);
  vector<int>dis(N, -1);
  dis[src] = 0;

  while(!my_queue.empty()){
            int node=my_queue.front();
            my_queue.pop();
            for(auto it:adjacentList[node]){
                if(dis[it] == -1){ //not visited
                    my_queue.push(it);
                    dis[it] = dis[node] + 1;
                }
            }
  }
  return dis;
}