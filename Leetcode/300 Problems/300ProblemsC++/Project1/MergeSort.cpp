//https://www.codingninjas.com/studio/problems/merge-sort_920442?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=1
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid + 1;

    vector<int> temp;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            ++left;
        }else{
            temp.push_back(arr[right]);
            ++right;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        ++left;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        ++right;      
    }

    for(int i = low; i <= high; ++i){ // low can possiblt not begin at 0 
        arr[i] = temp[i - low]; // "- low": for the second part
    }
}
void divide(vector<int> &arr, int low, int high){
    if(low == high) {
        return; // only have single element
    }

    int mid = (low + high) / 2;
    divide(arr, low, mid);    
    divide(arr, mid + 1, high);
    merge(arr, low, mid, high);

}
void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    divide(arr, 0, n - 1);
}