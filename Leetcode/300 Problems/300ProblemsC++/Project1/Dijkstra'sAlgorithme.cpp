//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
#include<bits/stdc++.h>
using namespace std; 

//using priority_queue
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
  vector<int> distance(V, INT_MAX);

  //first is weight
  //second is vertex

  //Khai báo 1 minimumHeap => luôn luôn lấy phần tử nhỏ nhất trong queue;
  
  //minimum distance to get to vertex
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> my_priority_queue; // Minimum heap

  my_priority_queue.push({0, S});
  distance[S] = 0;

  while(!my_priority_queue.empty()){
    int dis = my_priority_queue.top().first;
    int vertex = my_priority_queue.top().second;
    my_priority_queue.pop();

    for(auto it : adj[vertex]){
      int adjNode = it[0];
      int weight = it[1];

      if(dis + weight < distance[adjNode]){
        distance[adjNode] = dis + weight;
        my_priority_queue.push({dis + weight, adjNode});
      }
    }


  }

  return distance;
}

//using set
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
          vector<int> distance(V, INT_MAX);

  //first is weight
  //second is vertex

  //Khai báo 1 set => vì set luôn lưu trữ phần tử theo chiều tăng dần (phần tử đầu là nhỏ nhất)
  
  //minimum distance to get to vertex
  set<pair<int,int>> mySet;

  mySet.insert({0, S});
  distance[S] = 0;

  while(!mySet.empty()){
    auto firstElement = *(mySet.begin()); // Lấy phần tử đầu
    int dis = firstElement.first; // Lấy thành phần first của cặp
    int vertex = firstElement.second; // Lấy thành phần second của cặp

    mySet.erase(mySet.begin()); // Loại bỏ phần tử đầu (firstElement)

    for(auto it : adj[vertex]){
      int adjNode = it[0];
      int weight = it[1];

      if(dis + weight < distance[adjNode]){
        distance[adjNode] = dis + weight;
        mySet.insert({dis + weight, adjNode});
      }
    }


  }

  return distance;
}