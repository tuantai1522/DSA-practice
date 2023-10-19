//https://leetcode.com/problems/longest-common-prefix/description/
#include<iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
	int length = strs.size();
	if (length == 1) return strs[0];

	int index = 0;
	string res = "";

	//check = 1: that character is the same in every word
	//check = -1: that character is not the same in every word
	//check = 0: index is higher than the minimum length of vector string
	int check = 1;

	while (check != 0) {
		check = 1;

		char compare = strs[0][index];
		for (int i = 1; i < length; ++i) {
			if (index < strs[i].length()) {
				if (strs[i][index] != compare) {
					check = -1;
					break;
				}
			}
			else {
				check = 0;
				break;
			}
		}

		if (check == 0 || check == -1) {
			break;
		}

		if (check == 1) {
			res += strs[0][index];
			++index;
		}

	}
	return res;
}