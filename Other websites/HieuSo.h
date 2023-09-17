#pragma once
//https://ntucoder.net/Problem/Details/73

/*
* Ở vị trí j hiện tại, tìm giá trị min từ 0 đến j - 1
* Kết quả là max của Max và arr[i] - Min
*/


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void solveHieuSo() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	long long Min = min(arr[0], arr[1]);
	long long Max = arr[1] - arr[0];

	for (int i = 2; i < n; ++i) {
		Max = max(Max, arr[i] - Min);
		Min = min(Min, arr[i]);
	}

	cout << Max;

}



