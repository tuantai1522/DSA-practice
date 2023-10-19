//https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;
string gcdOfStrings(string str1, string str2) {
  int length1 = str1.length();
  int length2 = str2.length();
  int length = -1;

  string smallerString = "";
  string biggerString = "";
  if(length1 < length2){
    smallerString = str1;
    biggerString = str2;
    length = length1;
  }else{
    smallerString = str2;
    biggerString = str1;
    length = length2;
  }
  string result = "";

  for(int i = 0; i < length; ++i){
    string s1 = smallerString.substr(0, i + 1);
    string s2 = "";
    string s3 = "";
    while(s2.length() < biggerString.length()){
      s2 += s1;
    }

    while(s3.length() < smallerString.length()){
      s3 += s1;
    }
    if(s2 == biggerString && s3 == smallerString){
      result = s1;
    }

  }
  return result;
}
int main(){
  cout << gcdOfStrings("ABCABCABC", "ABCABC");
  return 0;
}