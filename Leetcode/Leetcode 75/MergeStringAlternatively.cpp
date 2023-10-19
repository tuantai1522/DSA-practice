//https://leetcode.com/problems/merge-strings-alternately/description/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;
string mergeAlternately(string word1, string word2) {
  string result = "";
  int length1 = word1.length();
  int length2 = word2.length();
  
  int index1 = 0;
  int index2 = 0;

  while(index1 < length1 || index2 < length2){
    if(index1 < length1){
      result += word1[index1++];
    }
    
    if(index2 < length2){
      result += word2[index2++];
    }
  }
  return result;
}
int main(){
  cout << mergeAlternately("abcd", "pq");
  return 0;
}