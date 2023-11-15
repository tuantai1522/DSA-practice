// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
#include <bits/stdc++.h>
using namespace std;
vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void PhoneNumberCombinations(string digits, int n, int index, string &temp, vector<string> &ans)
{
  if (index >= n)
  {
    ans.push_back(temp);
    return;
  }

  int idx = digits[index] - 48;
  for (int j = 0; j < letters[idx].length(); ++j)
  {
    temp += letters[idx][j];
    PhoneNumberCombinations(digits, n, index + 1, temp, ans);

    temp.pop_back();
  }
}

vector<string> letterCombinations(string digits)
{
  vector<string> ans;
  string temp;
  int n = digits.length();
  if (n == 0)
    return ans;

  PhoneNumberCombinations(digits, n, 0, temp, ans);
  return ans;
}