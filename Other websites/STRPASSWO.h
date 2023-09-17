#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long long STRPASSWO(string s) {
    long long ans = 0;
    int length = s.length();

    int countNum = 0;
    int countUp = 0;
    int countLow = 0;

    int left = -1;
    int begin = 0;

    while (left < length) {

        if ((left - begin + 1 < 6) || !(countNum > 0 && countLow > 0 && countUp > 0)) {
            ++left;

            if (isdigit(s[left])) {
                ++countNum;
            }

            if (isupper(s[left])) {
                ++countUp;
            }

            if (islower(s[left])) {
                ++countLow;
            }
        }
        else {
            ans += (length - left);
            if (isdigit(s[begin])) {
                --countNum;
            }

            if (isupper(s[begin])) {
                --countUp;
            }

            if (islower(s[begin])) {
                --countLow;
            }

            ++begin;
        }

    }
    return ans;
}
