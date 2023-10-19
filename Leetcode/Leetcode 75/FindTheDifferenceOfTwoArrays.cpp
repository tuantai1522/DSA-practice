//https://leetcode.com/problems/find-the-difference-of-two-arrays/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;    
vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
  set<int>mySet1;
  set<int>mySet2;

  vector<vector<int>>arr;

  vector<int>temp;
  
  for(int ele : nums2){
    //add to set2
    mySet2.insert(ele);
  }

  for(int ele : nums1){
    auto it = find(temp.begin(), temp.end(), ele);
    if(!mySet2.contains(ele) && it == temp.end()){
      temp.push_back(ele);
    }
    mySet1.insert(ele);
  }

  arr.push_back(temp);
  temp.clear();

  for(int ele : nums2){
    //work to find result
    auto it = find(temp.begin(), temp.end(), ele);
    if(!mySet1.contains(ele) && it == temp.end()){
      temp.push_back(ele);
    }
  }  

  arr.push_back(temp);

  return arr;
    }
}
    