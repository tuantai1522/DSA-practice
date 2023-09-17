#pragma once
//https://thptchuyen.ntucoder.net/Problem/Details/4633?fbclid=IwAR0seD-YcZoydwSDwzuhxQ5DTKAvSx7he4FqZ15n9Nh1axVxjRpXduFBLOs

/*
Khi dãy chỉ có 1 phần tử A thì có các dãy con liên tiếp là :
A
Khi dãy có thêm 1 phần tử B thì nếu không tính các dãy con đã xuất hiện trước đó khi xét A thì giờ đây có thêm các dãy con liên tiếp mới là :
B
A | B
Khi dãy có thêm 1 phần tử C thì nếu không tính các dãy con đã xuất hiện trước đó khi xét B thì giờ đây có thêm các dãy con liên tiếp mới là :
C
B | C
A B | C
Khi dãy có thêm 1 phần tử D thì nếu không tính các dãy con đã xuất hiện trước đó khi xét C thì giờ đây có thêm các dãy con liên tiếp mới là :
D
C | D
B C | D
A B C | D
0 8 -10 6 -5  9  1 -3
0 8  -2 6  1 10 11  8

Giải thích nhanh: Ở vòng lặp for thứ 2 thì Max là biến lưu giá trị lớn nhất các dãy con liên tiếp từ 0 tới
a[i]. Ở vòng lặp for thứ 3 thì ta tận dụng Max để tìm ra F[i] lớn nhất trong các F[i].
Kết quả sau cùng in ra Max.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
void solveDaySo3_1() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n + 1), temp(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	temp[0] = 0;
	long long Max = temp[0];
	for (int i = 1; i <= n; ++i) {
		Max = max(arr[i], Max + arr[i]);
		temp[i] = Max;
	}
	long long ans = temp[1];
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, temp[i]);
	}

	cout << ans;
}

void solveDaySo3_2() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	long long ans = 0;
	long long sum = 0;
	vector<long long>arr(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

		sum = max(sum + arr[i], arr[i]);
		ans = max(ans, sum);
	}

	cout << ans;
}
