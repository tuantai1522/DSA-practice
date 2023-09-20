#pragma once
//https://ntucoder.net/Problem/Details/5527?fbclid=IwAR0pmkC7z0CyXJ4fUmkXf1y_L7k281bIS1wWazktQx-rKIZLOIR1KGRCl88
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
//Tự làm
void solveXinChao_1() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int index = 0;
	int length = s.size();

	string ans = "";
	for (int i = 0; i < length; ++i) {
		if (s[i] == 'h' && index == 0) {
			ans += s[i];
			++index;
		}
		else if (s[i] == 'e' && index == 1) {
			ans += s[i];
			++index;
		}
		else if (s[i] == 'l' && index == 2) {
			ans += s[i];
			++index;
		}
		else if (s[i] == 'l' && index == 3) {
			ans += s[i];
			++index;
		}
		else if (s[i] == 'o' && index == 4) {
			ans += s[i];
			++index;
		}
	}
	if (ans == "hello") {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}

//Tham khảo
void solveXinChao_2() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int index = 0;
	int length = s.size();

	string ans = "hello";
	for (int i = 0; i < length; ++i) {
		if (s[i] == ans[i]) {
			index++;
			if (index == 5) {
				cout << "YES";

			}
		}
	}
	cout << "NO";
}
