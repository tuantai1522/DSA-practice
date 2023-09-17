#pragma once
//https://ntucoder.net/Problem/Details/103?fbclid=IwAR19TTdtWEOmkdjgXQSjp-VQ-jGKNnec1JhThUKgxS9mHcCkD4O3Mp25vOo
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//to convert from number to binary number with defined length
string TinhNhiPhan(long long n, long long length) {
	string temp;
	int index = n - 1;
	int number = n;
	while (temp.length() < length) {
		temp.push_back((number % 2) + 48);
		number /= 2;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

void solveLietKeChuoiNhiPhan() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;
	long long length = n;
	n = pow(2, n);

	vector<string> ans;
	for (int i = 0; i < n; ++i) {
		ans.push_back(TinhNhiPhan(i, length));
	}


	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
}

