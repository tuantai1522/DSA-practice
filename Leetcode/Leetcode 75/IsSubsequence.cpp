//https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
  int length_s = s.length();
  int length_t = t.length();

  if(length_s > length_t) return false;


  int first = 0;
  int second = 0;
  while(second < length_t){
    if(s[first] == s[second]){
      ++first;
    }

    if(first == length_s) return true;
    ++second;
  }
  return false;
}
int main(){

}