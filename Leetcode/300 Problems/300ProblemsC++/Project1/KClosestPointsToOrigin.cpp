//https://leetcode.com/problems/k-closest-points-to-origin/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
	int size = points.size();

	vector<pair<int, vector<int>>> my_vector;
	for (int i = 0; i < size; ++i) {
		int count = pow(points[i][0], 2.0) + pow(points[i][1], 2.0);
		my_vector.push_back(std::make_pair(count, points[i]));
	}

	sort(my_vector.begin(), my_vector.end());
	vector<vector<int>> ans;
	for (const auto& pair : my_vector) {
		--k;
		ans.push_back(pair.second);
		if (k == 0) break;
	}


	return ans;
}

//xài priority_queue
vector<vector<int>> kClosest_Queue(vector<vector<int>>& points, int k) {
	priority_queue<vector<int>> minHeap;

	for (auto it : points) {
		int count = pow(it[0], 2.0) + pow(it[1], 2.0);

		minHeap.push({ count , it[0], it[1] });
		if (minHeap.size() > k) {
			minHeap.pop();
		}
	}

	vector<vector<int>>ans;
	while (!minHeap.empty()) {
		vector<int> topElement = minHeap.top();
		ans.push_back({ topElement[1], topElement[2] });
		minHeap.pop();
	}

	return ans;
}