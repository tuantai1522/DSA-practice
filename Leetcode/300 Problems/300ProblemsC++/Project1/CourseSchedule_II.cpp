//https://leetcode.com/problems/course-schedule-ii/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	int n = prerequisites.size();
	vector<int>indegree(numCourses);
	vector<vector<int>>adjacent(numCourses);

	//Step 1: find indegree and adjacents of all vertexes
	for (int i = 0; i < n; ++i) {
		int learn = prerequisites[i][0];
		int require = prerequisites[i][1];
		indegree[require]++;
		adjacent[learn].push_back(require);
	}

	//Step 2: push all nodes with indegree = 0 into queue
	vector<int>ans;
	queue<int> my_queue;
	for (int i = 0; i < numCourses; ++i) {
		if (indegree[i] == 0) {
			my_queue.push(i);
			ans.push_back(i);
		}
	}

	//Step 3: process with the queue
	while (!my_queue.empty()) {
		int top = my_queue.front();

		my_queue.pop();

		//loop vector of current vertex
		for (int i = 0; i < adjacent[top].size(); ++i) {
			indegree[adjacent[top][i]]--;
			if (indegree[adjacent[top][i]] == 0) {
				my_queue.push(adjacent[top][i]);
				ans.push_back(adjacent[top][i]);
			}
		}
	}

	//If it is impossible to finish all courses, return an empty array
	if (ans.size() != numCourses) {
		ans.clear();
	}
	else {
		reverse(ans.begin(), ans.end());
	}

	return ans;
}