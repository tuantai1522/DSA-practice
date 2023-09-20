#pragma once
//https://ntucoder.net/Problem/Details/5523?fbclid=IwAR3w4jeWkV58cehidSj98NDlnglWMFn2b3QnkRYMjSgofmJK1nmEHHZrxbE
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
/// <summary>
/// 1. Đầu tiên nhóm 4 và 3 người không thể rách rời nhau => ans += temp[3] + temp[4]
/// 2. Sau đó nhóm 1 người sẽ nhét vào để đi chung với nhóm 3 người => tính số nhóm 1 người còn sau khi đã nhét hết nhóm 1 vàp nhóm 3 người
/// 3. Sau đó nhóm 2 người sẽ đi chung với nhau => tính số nhóm 2 người dư sau khi đã nhét đủ lên xe nhóm 2 người
/// 4. Sau đó ta sẽ gộp chung nhóm 1 (nếu nhóm 1 là dư -> nghĩa là > 1)) và nhóm 2 lại với nhau 
/// 5. Nếu gộp ko đủ nhóm 1 và nhóm 2 -> thuê thêm 1 xe nữa
/// </summary>
void solveTaxi() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;

	cin >> n;

	vector<long long>arr(n);

	vector<int>temp(5);

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		temp[arr[i]] += 1;
	}

	//1. Bước 1
	int ans = temp[4] + temp[3];

	//2. Bước 2
	temp[1] -= temp[3];

	//3. Bước 3
	ans += (temp[2] * 2) / 4;
	temp[2] = (temp[2] * 2) % 4;

	//4. Bước 4
	int sum = 0;
	if (temp[1] > 0) {
		sum = temp[1];
	}
	sum += temp[2];
	ans += (sum / 4);

	//5. Bước 5
	if (sum % 4 != 0) {
		ans++;
	}

	cout << ans;
}

