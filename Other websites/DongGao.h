#pragma once
//http://lequydon.ntucoder.net/Problem/Details/6005?fbclid=IwAR2bduGj4WONOrhS7n-KM0e5Giu8BDh3cFeyX5eQNJdILkHo5DW2O9SYplY
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
void solveDongGao() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;
	long long ans = 0;

	while (n) {
		if ((n - 3) % 3 == 0) {
			++ans;
			n -= 3;
		}
		else if ((n - 5) % 5 == 0) {
			++ans;
			n -= 5;
		}
	}
	cout << ans;
}
