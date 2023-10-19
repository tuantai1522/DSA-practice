//https://codeforces.com/problemset/problem/910/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
      int n;
      cin >> n;
      int cnt2021 = n % 2020;
      int cnt2020 = (n - (cnt2021 * 2021)) / 2020;

      if(cnt2020 >= 0 && cnt2021 * 2021 + cnt2020 * 2020 == n){
        cout << "Yes\n";
      }else{
        cout << "No\n";
      }
      
    }
    return 0;
}