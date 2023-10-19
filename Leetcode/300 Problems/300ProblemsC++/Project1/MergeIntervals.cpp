//https://leetcode.com/problems/merge-intervals/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;


vector<vector<int>> merge_MySolution(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int size = intervals.size();
    vector<vector<int>> ans;
    if (size <= 1) return intervals;


    for (int i = 1; i < size; ++i) {
        if (intervals[i][0] > intervals[i - 1][1]) {
            ans.push_back(intervals[i - 1]);
        }
        else {
            intervals[i][0] = min(intervals[i][0], intervals[i - 1][0]);
            intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
        }
    }

    //last element
    if (intervals[size - 1][0] > intervals[size - 2][1]) {
        ans.push_back(intervals[size - 1]);
    }
    else {
        intervals[size - 1][0] = min(intervals[size - 1][0], intervals[size - 2][0]);
        intervals[size - 1][1] = max(intervals[size - 1][1], intervals[size - 2][1]);
        ans.push_back(intervals[size - 1]);
    }
    return ans;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);
    //output.back(): get last index of output

    for (int i = 1; i < intervals.size(); i++) {

        //overlapping
        if (output.back()[1] >= intervals[i][0]) {
            output.back()[1] = max(output.back()[1], intervals[i][1]);
        }
        //non-overlapping
        else {
            output.push_back(intervals[i]);
        }
    }
    return output;
}