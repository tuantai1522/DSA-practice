#pragma once
//https://vinhdinhcoder.net/Problem/Details/5284?fbclid=IwAR1ZF-NYdNFWjst8y0MTAG7R23MXV7a9geFICxpG6C9YS3EFFQ2mflgDGRA
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>;
using namespace std;
string KiemTraDoiXung(string temp) {
	string reverse_temp = temp;
	reverse(reverse_temp.begin(), reverse_temp.end());
	return temp == reverse_temp ? "YES" : "NO";
}

void solveMatKhau() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	long long k;

	//Nhập k
	getline(cin, s);
	k = stoi(s);

	//Nhập s
	getline(cin, s);

	long long length = s.size();

	string numbers = "";

	for (int i = 0; i < length; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			numbers += s[i];
		}
	}


	vector<vector<long long>> my_vector(10);
	length = numbers.length();
	for (int i = 0; i < length; ++i) {
		my_vector[numbers[i] - '0'].push_back(i);

	}

	long long left = 0;
	long long right = length - k;


	string ans = "";

	while (k != 0) {
		if (length - left == k) {
			ans += numbers.substr(left);
			break;
		}

		for (int i = 9; i >= 0; --i) {
			//Tìm giá trị "start" trong mảng 1 chiều hiện tại
			auto iterator = lower_bound(my_vector[i].begin(), my_vector[i].end(), left);

			//Nếu mảng 1 chiều hiện tại tồn tại giá trị
			if (iterator != my_vector[i].end()) {
				//Tính khoảng cách giữa iterator và đầu mảng 1 chiều
				long long idxMax = iterator - my_vector[i].begin();

				if (my_vector[i][idxMax] <= right) {

					//Sau khi tìm được max, ta phải cập nhật lại vị trí left và vị trí sau idxMax, tăng right và giảm k
					ans += (i + 48);
					left = my_vector[i][idxMax] + 1;
					++right;
					--k;

					break;
				}
			}
		}
	}

	cout << ans << endl;
	cout << KiemTraDoiXung(ans);
}

