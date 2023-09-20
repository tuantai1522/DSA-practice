//https://luyencode.net/problem/TRUEBRACK?fbclid=IwAR2izrACEYvzrioQZvr3dpEQadvrDn5Rlb856hIAevJBt1VMleJwpjOpMG0
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
void solveDayNgoacDung() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int length = s.length();

	stack<char> my_stack;

	for (int i = 0; i < length; ++i) {

		//dấu ngoặc mở
		if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
			my_stack.push(s[i]);
		}
		//còn lại là dấu ngoặc đóng
		else {
			//nếu stack rỗng -> tức là không có dấu ngoặc mở nào
			if (my_stack.empty()) {
				cout << "No";
				return;
			}
			else if (my_stack.top() == '{' && s[i] == '}') {
				my_stack.pop();
			}
			else if (my_stack.top() == '[' && s[i] == ']') {
				my_stack.pop();
			}
			else if (my_stack.top() == '(' && s[i] == ')') {
				my_stack.pop();
			}
			//trường hợp còn lại là sai
			else {
				cout << "No";
				return;
			}
		}
	}
	cout << "Yes";
}

