// https://leetcode.com/problems/palindrome-partitioning/description/
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int left, int right)
{
  while (left < right)
  {
    if (s[left++] != s[right--])
    {
      return false;
    }
  }
  return true;
}
void partitioning(string s, int n, int index, vector<string> &temp, vector<vector<string>> &ans)
{
  if (index >= n)
  {
    ans.push_back(temp);
    return;
  }

  for (int i = index; i < n; ++i)
  {
    // from index 0, cut 1 element

    if (isPalindrome(s, index, i))
    {
      temp.push_back(s.substr(index, i - index + 1));

      partitioning(s, n, i + 1, temp, ans);

      temp.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  vector<vector<string>> ans;
  vector<string> temp;
  int n = s.length();
  partitioning(s, n, 0, temp, ans);
  return ans;
}
