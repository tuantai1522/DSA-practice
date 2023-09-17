#pragma once
//https://thptchuyen.ntucoder.net/Problem/Details/4632?fbclid=IwAR3yl4rIOeksPT5k_upF4oy5o09de-lVEZ7qliDxgl1Zgw2WJE8yxaIfKYo

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void solveDaySo2() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	long long ans = 0;

	if (n >= 3) {
		long long max1 = max(arr[0], arr[1]); //Phần tử lớn nhất
		long long max2 = min(arr[0], arr[1]); // Phần tử lớn nhì
		ans = max1 + max2 - arr[2];
		for (int i = 3; i < n; ++i) {
			if (arr[i] > max1) {
				max2 = max1;
				max1 = arr[i];
			}
			else if (arr[i] > max2) {
				max2 = arr[i];
			}

			ans = max(ans, max1 + max2 - arr[i]);
		}

		cout << ans;

	}
	else {
		cout << 0;
	}

}

