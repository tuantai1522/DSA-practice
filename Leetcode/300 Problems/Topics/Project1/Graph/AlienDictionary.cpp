//https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

string findOrder(string dict[], int N, int K) {
    //STEP 1:
// construct adjacentList and indegree
    vector<vector<int>>adjacentList(K);
    vector<int> indegree(K);

    for (int i = 0; i < N - 1; ++i) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int length = min(s1.length(), s2.length());

        for (int j = 0; j < length; ++j) {
            if (s1[j] != s2[j]) {
                adjacentList[s1[j] - 'a'].push_back(s2[j] - 'a');
                indegree[s2[j] - 'a']++;
                break;
            }
        }
    }

    //STEP 2: Push all nodes with indegree 0 into queue
    queue<int>my_queue;
    vector<int>topo;

    for (int j = 0; j < K; ++j) {
        if (indegree[j] == 0) {
            my_queue.push(j);
            topo.push_back(j);
        }

    }
    //STEP 3: Process with queue
    while (!my_queue.empty()) {
        int top = my_queue.front();
        my_queue.pop();

        for (auto it : adjacentList[top]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                my_queue.push(it);
                topo.push_back(it);
            }
        }
    }

    string ans = "";
    for (int i = 0; i < topo.size(); ++i) {
        ans = ans + char(topo[i] + 'a'); //convert int to string;
    }
    //ans: bdac => true => retun 1

    return ans;
}