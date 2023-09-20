#pragma once
//https://ntucoder.net/Problem/Details/3?fbclid=IwAR1W4FW7YDYV2u0um19kw7XOARCGrhIsMuSEwV6GxyBJIz1bx3AiLCgVzq8

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void solveCaiTui() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;

	cin >> n >> m;

	vector<vector<int>> arr(n, vector<int>(2)); // Tạo vector 2D với n dòng và 2 cột

	// Nhập dữ liệu cho vector 2D
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> arr[i][j];
		}
	}

	long long size = pow(2, n);

	long long ans = -1;
	long long TotalWeight;
	long long TotalValue;

	vector<int> array_temp;
	vector<int> array_ans;

	for (int i = 1; i < size; ++i) {
		//Tạo dãy nhị phân tương ứng với i
		string temp(n, '0');

		int number = i;
		int index = n - 1;
		while (number) {
			temp[index--] = (number % 2) + 48;
			number /= 2;
		}

		TotalWeight = 0;
		TotalValue = 0;
		array_temp.clear();

		for (int i = 0; i < n; ++i) {
			//0 là không lấy giỏ hàng đó, 1 là lấy
			if (temp[i] == '1') {
				TotalWeight += arr[i][0];
				TotalValue += arr[i][1];
				array_temp.push_back(i + 1);
			}
		}
		if (TotalWeight <= m && TotalValue > ans) {
			ans = max(ans, TotalValue);
			array_ans = array_temp;
		}
	}
	if (ans == -1) {
		cout << "0";
		return;
	}

	cout << ans << "\n";

	for (int i = array_ans.size() - 1; i >= 0; --i) {
		cout << array_ans[i] << " ";
	}
}

