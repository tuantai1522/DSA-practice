#pragma once
// https://cses.fi/problemset/task/1620
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void solveFactoryMachines() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, t, Min = 1000000005;

	cin >> n >> t;

	vector<long long>machines(n);

	for (int i = 0; i < n; ++i) {
		cin >> machines[i];
		Min = min(Min, machines[i]);
	}
	long long left = 1;
	long long ans = 0;
	long long right = Min * t;

	while (left <= right) {
		long long mid = (left + right) / 2;

		long long temp = 0;
		for (int i = 0; i < n; ++i) {
			temp += mid / machines[i];
		}

		//move to left
		if (temp >= t) {
			ans = mid;
			right = mid - 1;
		}
		else{ //move to right
			left = mid + 1;
		}
	}

	cout << ans;
}
