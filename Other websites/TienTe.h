﻿
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;


void solveTienTe() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n);

	vector<string>ans;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	long long size = pow(2, n);
	for (int i = 1; i < size; ++i) {
		//Tạo dãy nhị phân tương ứng với i
		string temp(n, '0');

		int number = i;
		int index = n - 1;
		while (number) {
			temp[index--] = (number % 2) + 48;
			number /= 2;
		}

		long long sumA = 0;
		long long sumB = 0;
		for (int i = 0; i < n; ++i) {
			if (temp[i] == '0') {
				sumA += arr[i];
			}
			else if (temp[i] == '1') {
				sumB += arr[i];
			}
		}

		if (sumA == sumB) {
			ans.push_back(temp);
		}
	}

	int length = ans.size();

	if (length == 0) {
		cout << "khong chia duoc";
		return;
	}
	cout << length << endl;
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (ans[i][j] == '0' ? 'A' : 'B') << " ";
		}
		cout << "\n";
	}
}


