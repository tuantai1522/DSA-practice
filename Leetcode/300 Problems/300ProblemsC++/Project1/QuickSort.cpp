//https://www.codingninjas.com/studio/problems/quick-sort_983625?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTab=1
#include <bits/stdc++.h> 
using namespace std;

//return indexOfPartition (which all left elements are less than and all righ elements are greatere than)
int partition(vector<int> &arr, int low, int high){
    int i = low;
    int j = high;
    int pivot = low;

    while(i < j){
        while(arr[i] <= arr[pivot] && i < j) ++i;      
        while(arr[j] > arr[pivot] && j >= 0) --j;

        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[pivot]);

    return j;
}
void qS(vector<int> &arr, int low, int high){
    if(low < high){
        int partitionIndex = partition(arr, low, high);
        qS(arr, low, partitionIndex - 1);        
        qS(arr, partitionIndex + 1, high);

    }
}
vector<int> quickSort(vector<int> arr)
{
    qS(arr, 0, arr.size() - 1);
    return arr;
}
