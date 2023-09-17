#pragma once
// https://cses.fi/problemset/task/1084
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX_N = 2e5;
int applicants[MAX_N], apartments[MAX_N];
int ans = 0;
int n, m, k;

void solveApartments() {

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) cin >> applicants[i];
	for (int i = 0; i < m; ++i) cin >> apartments[i];

	sort(applicants, applicants + n);
	sort(apartments, apartments + m);

	int i = 0, j = 0;

	while (i < n && j < m) {
		if (abs(applicants[i] - apartments[j]) <= k) {
			++i;
			++j;
			++ans;
		}
		else {
			if (applicants[i] - apartments[j] < 0) {
				++i;
			}
			else {
				++j;
			}
		}
	}
	cout << ans;
}
