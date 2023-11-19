//https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph
#include<bits/stdc++.h>
using namespace std; 

//using priority_queue
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
      vector<int> distance(n + 1, INT_MAX);
      vector<int> parent(n + 1); // Sửa INT_MAX thành -1 hoặc giá trị phù hợp cho parent
    
        vector<vector<pair<int, int>> > adj(n + 1);
    
    
      for (auto it : edges) {
          adj[it[0]].push_back({it[1], it[2]});
          adj[it[1]].push_back({it[0], it[2]});
      }
    
        for(int i = 1; i <= n; ++i){
            parent[i] = i;
        }
        
      //first is weight
      //second is vertex
    
      //Khai báo 1 minimumHeap => luôn luôn lấy phần tử nhỏ nhất trong queue;
      
      //minimum distance to get to vertex
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> my_priority_queue; // Minimum heap
    
      my_priority_queue.push({0, 1});
      distance[1] = 0;
    
      while(!my_priority_queue.empty()){
        int dis = my_priority_queue.top().first;
        int vertex = my_priority_queue.top().second;
        my_priority_queue.pop();
    
        for(auto it : adj[vertex]){
          int adjNode = it.first;
          int weight = it.second;
    
          if(dis + weight < distance[adjNode]){
            distance[adjNode] = dis + weight;
            my_priority_queue.push({dis + weight, adjNode});
            parent[adjNode] = vertex; //update parent of that node
          }
        }
    
    
      }
    
      //can not reach end point
      if(distance[n] == INT_MAX) return {-1};
    
      vector<int>ans;
      while(parent[n] != n){
        ans.push_back(n);
        n = parent[n];
      }
    
      ans.push_back(1);
      reverse(ans.begin(), ans.end());
      return ans;
}