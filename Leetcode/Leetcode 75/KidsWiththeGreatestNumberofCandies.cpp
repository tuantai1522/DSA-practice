// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;
vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
  int n = candies.size();
  vector<bool>result(n);

  int Max = 0;
  for(int i = 0; i < n; ++i){
    Max = max(max, candies[i]); 
  }

  for(int i : candies){
    result.add(i >= Max - extraCandies ? true : false);
  }

  return result;
}
int main(){

}