#pragma once
//https://lqdoj.edu.vn/problem/delnum?fbclid=IwAR18MknXUBh0AuWIcguDNTJxEkWOlGX3byCjGLcet-R3M4Gx2XATClk9qC8
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

void solveXoaChuSo_1() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string n, s;
	long long k;

	// //Nhập n
	// getline(cin, n);
	n = "58816";

	//Nhập k
	getline(cin, s);
	k = stoi(s);

	vector<vector<long long>> my_vector(10);
	int length = n.length();

	for (int i = 0; i < length; ++i) {
		my_vector[n[i] - '0'].push_back(i);
	}

	string ans = "";

	long long left = 0;
	long long right = k;
	while (true) {

		//Nếu k số cần xóa nằm ở cuối
		if (n.length() - ans.length() == k) {
			break;
		}

		if (k == 0) {
			ans += n.substr(left);
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

					//Ta phải cập nhật lại vị trí left và vị trí sau idxMax, tăng right và giảm k
					ans += (i + 48);

					k -= abs(my_vector[i][idxMax] - left);

					left = my_vector[i][idxMax] + 1;
					++right;

					break;
				}
			}
		}


	}

	cout << ans << endl;

}
//Tự làm
void solveXoaChuSo_2() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string n, s;
	long long k;

	// //Nhập n
	getline(cin, n);

	//Nhập k
	getline(cin, s);
	k = stoi(s);

	stack<char> my_stack;

	int length = n.length();
	string ans = "";
	if (k == 0) {
		cout << n << endl;
		return;
	}
	my_stack.push(n[0]);

	int index = 1;
	while (index < length) {
		if (n[index] > my_stack.top()) {
			while (!my_stack.empty() && k > 0 && n[index] > my_stack.top()) {
				my_stack.pop();
				--k;
			}
		}
		my_stack.push(n[index]);
		++index;
	}
	while (!my_stack.empty()) {
		ans += my_stack.top();
		my_stack.pop();
	}
	reverse(ans.begin(), ans.end());

	if (length - ans.length() != k) {
		ans += n.substr(index);
	}

	if (k > 0) {
		cout << ans.substr(0, length - k);
	}
	else {
		cout << ans << endl;
	}

}

//Tham khảo code
void solveXoaChuSo_3() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string n, s;
	long long k;

	// //Nhập n
	getline(cin, n);

	//Nhập k
	getline(cin, s);
	k = stoi(s);

	stack<char> st;
	for (int i = 0; i < (int)n.length(); ++i) {
		while (!st.empty() && k > 0 && n[i] > st.top()) {
			k--;
			st.pop();
		}
		st.push(n[i]);
	}
	string ans = "";
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	reverse(ans.begin(), ans.end());

	cout << ans.substr(0, ans.length() - k);
}
