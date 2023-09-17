#pragma once
// http://laptrinhonline.club/problem/cotyey05012022
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
//Tư tưởng giải bài
//Ta sẽ xét số mét cây chặt được trong đoạn từ[0, Max]
//Nếu như ở vị trí chặt càng cao = > số m cây thu được càng ít
//Ví dụ :
//4 10
//10 15 12 13
//Nếu chặt ở vị trí 8 = > số cây thu được là : (10 - 8) + (15 - 8) + (12 - 8) + (13 - 8) = 18
//Nếu chặt ở vị trí 10 = > số cây thu được là : (10 - 10) + (15 - 10) + (12 - 10) + (13 - 10) = 10
//Nếu chặt ở vị trí 12 = > số cây thu được là : (10 - 12) + (15 - 12) + (12 - 12) + (13 - 12) = 2
//
//Vì vậy cách làm tương tự như bài trước, tính số mét cây chặt được ở vị trí x
//Nếu số mét cây chặt được ít hơn l = > di chuyển right sang trái của mid để tìm mid nhỏ hơn (vì mid nhỏ hơn thì chặt dc nhìu mét cây hơn)
//Nếu số mét cây chặt được nhiều hơn l = > di chuyển left sang phải của mid để tìm mid lớn hơn (vì mid lớn hơn thì chặt dc ít mét cây hơn)
void solveChatCayXayNha() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, l;

	long long Max = 0;
	cin >> n >> l;

	vector<long long>trees(n);

	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> trees[i];
		Max = max(Max, trees[i]);
	}

	long long left = 0;
	long long right = Max;
	while (left <= right) {
		long long mid = (left + right) / 2;

		long long temp = 0;
		for (int i = 0; i < n; ++i) {
			//if tree is smaller than position => can not cut
			if (trees[i] - mid > 0) {
				temp += trees[i] - mid;
			}
		}

		//move to right
		if (temp >= l) {
			ans = mid;
			left = mid + 1;
		}
		else { //move to left
			right = mid - 1;
		}

	}
	cout << ans;
}

