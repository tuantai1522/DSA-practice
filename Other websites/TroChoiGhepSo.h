#pragma once
//https://luyencode.net/problem/NUMTRANS?fbclid=IwAR1mSWIK3cP-7ijJndjZtOCBHIs3IdReJie6OedhvvK1_SlclGvVUH36fF8

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void solveTroChoiGhepSo() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	long long n;

	cin >> n;

	vector<string>arr;

	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		arr.push_back(to_string(x));
	}
	sort(arr.begin(), arr.end());

	string ans = "";
	for (int i = n - 1; i >= 0; --i) {
		cout << arr[i];
	}

}

