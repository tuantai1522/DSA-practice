#pragma once
//https://ntucoder.net/Problem/Details/4?fbclid=IwAR0n7tdw7uIGmU1HW1pPyGnifPHtcZL_IgRVvKryA7wndS7fe66hOyLpuS8
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int solveCamDien() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;

	cin >> n >> m;
	if (m == 1) return 0;

	vector<long long>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	long long ans = 0;

	long long sum = 0;

	for (int i = n - 1; i >= 0; --i) {

		//số ổ cắm hiện tại đã đủ, ko cần phải nối thêm nữa
		if (sum + arr[i] >= m) {
			sum += arr[i];
			++ans;
			return ans;
		}
		else {//số ổ cắm hiện tại không đủ, cần phải nối thêm => ổ cắm hiện tại chỉ có arr[i] - 1 ổ cắm cho các thiệt bị điện vì 1 chỗ phải để cho ổ cắm rời tiếp theo cắm vào
			sum += (arr[i] - 1);
			++ans;
		}
	}
	return -1;
}