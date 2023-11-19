// https://leetcode.com/problems/permutation-sequence/description/
#include <bits/stdc++.h>
using namespace std;
string getPermutation(int n, int k)
{
  // index from 0 to k - 1
  --k;
  // count factorial from 1 -> n - 1;
  int factorial = 1;

  // numbers is from 1 -> n
  vector<int> numbers;
  for (int i = 1; i < n; ++i)
  {
    numbers.push_back(i);
    factorial *= i;
  }
  numbers.push_back(n);

  string ans = "";
  while (true)
  {
    int idx = k / factorial;
    int carry = k % factorial;

    ans += to_string(numbers[idx]);
    numbers.erase(numbers.begin() + idx);

    if (numbers.size() == 0)
    {
      break;
    }
    k = carry;
    factorial /= numbers.size();
  }

  return ans;
}