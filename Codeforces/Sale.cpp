//https://codeforces.com/problemset/problem/910/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;

    vector<int>arr(n);
    for(int i = 0; i < n; ++i){
      cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int total = 0;
    for(int i = 0; i < n; ++i){
      if(arr[i] < 0){
        total += abs(arr[i]);
      }
      --m;
      if(m == 0) break;
    }

    cout << total;
    return 0;
}