/ https://leetcode.com/problems/insert-interval/description/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int n = intervals.size(), i = 0;
    vector<vector<int>> res;

    int start = newInterval[0];
    int end = newInterval[1];

    //case 1: no overlapping case before the merge intervals
    //compare ending point of intervals to starting point of newInterval
    while (i < n && intervals[i][1] < start) {
        res.push_back(intervals[i]);
        i++;
    }
    //case 2: overlapping case and merging of intervals
    while (i < n && end >= intervals[i][0]) {
        start = min(start, intervals[i][0]);
        end = max(end, intervals[i][1]);
        i++;
    }
    res.push_back({start, end});
    // case 3: no overlapping of intervals after newinterval being merged
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}