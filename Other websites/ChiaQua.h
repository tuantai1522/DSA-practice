#pragma once
//https://ntucoder.net/Problem/Details/3?fbclid=IwAR1W4FW7YDYV2u0um19kw7XOARCGrhIsMuSEwV6GxyBJIz1bx3AiLCgVzq8

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
void solveChiaQua() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n);
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
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}
