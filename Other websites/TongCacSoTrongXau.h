#pragma once
//https://luyencode.net/problem/SUMSO?fbclid=IwAR2DI_AVMUd3FR5tHv11SlGzyjQRzHrM6XDepmAMG2o_y_ve4DuhFUgRSnI
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void solveTongCacSoTrongXau() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	int length = s.length();

	long long ans = 0;

	for (int i = 0; i < length; ++i) {
		string temp = "";
		while (s[i] >= '0' && s[i] <= '9') {
			temp += s[i];
			++i;
		}
		if (temp != "") {
			ans += stoll(temp);
		}
	}

	cout << ans;
}
