//https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;
int largestAltitude(vector<int>& gain) {
  int size = gain.size();

  //Nếu vị trí đầu nhỏ hơn 0 thì độ cao lớn nhất là 0, không thì độ cao hiện tại là phần tử đầu tiên
  int Max = gain[0] < 0 ? 0 : gain[0];

  for(int i = 1; i < size; ++i){
    gain[i] += gain[i - 1];
    Max = max(Max, gain[i]);
  }       

  return Max;
}