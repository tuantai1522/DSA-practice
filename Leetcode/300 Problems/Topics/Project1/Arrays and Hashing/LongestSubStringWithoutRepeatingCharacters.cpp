//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <set>
using namespace std;    
int lengthOfLongestSubstring(string s) {
	int length = s.length();

	set<char> characterArray;
	int first_pointer = 0;
	int second_pointer = 0;
	int res = 0;

	while (second_pointer < length) {
		if (!characterArray.count(s[second_pointer])) {
			characterArray.insert(s[second_pointer]);
			++second_pointer;
			res = max(res, static_cast<int>(characterArray.size()));
		}
		else {
			characterArray.erase(s[first_pointer]);
			++first_pointer;
		}
		
	}
	return res;
}