#pragma once
//https://ntucoder.net/Problem/Details/3323?fbclid=IwAR2EBdWaDf3CW43qPLXLIOasO0qhPhZ1LnFvvk45mJdJlMSOGFvRKrhu-rU
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
void solveChongGach() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n);


	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	long long max = arr[n - 1];

	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		sum += arr[i];
		if (sum <= max) {
			ans += 1;
		}
	}
	cout << ans + 1;
}
