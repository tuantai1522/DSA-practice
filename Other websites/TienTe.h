#pragma once
//https://ntucoder.net/Problem/Details/4420?fbclid=IwAR3hkGtoEWx8bM4innbDxNbRM07hASOVwIpb8UHM56Zpq0_jcgnM10y-9oE

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
string convertIntToString(string s) {
	int length = s.length();
	string ans = "";
	for (int i = 0; i < length; ++i) {
		if (s[i] == '0') ans += 'A';
		else ans += 'B';
		ans += " ";
	}
	return ans;
}
void solveTienTe() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>numbers(n);

	vector<string> binarylist;

	for (int i = 0; i < n; ++i) {
		cin >> numbers[i];
	}

	//to list binary with n length
	for (int i = 1; i < pow(2, n); ++i) {
		binarylist.push_back(TinhNhiPhan(i, n));
	}

	vector<string> ans;

	//0 is for person A, 1 is for person B
	for (int i = 0; i < binarylist.size(); ++i) {
		long long sumA = 0;
		long long sumB = 0;
		for (int j = 0; j < n; ++j) {
			if (binarylist[i][j] == '0') {
				sumA += numbers[j];
			}
			else {
				sumB += numbers[j];
			}
		}
		if (sumA == sumB) {
			ans.push_back(binarylist[i]);
		}
	}

	int length = ans.size();
	if (length == 0) {
		cout << "khong chia duoc";
	}
	else {
		cout << length << endl;
		for (int i = 0; i < ans.size(); ++i) {
			cout << convertIntToString(ans[i]) << endl;
		}
	}
}

