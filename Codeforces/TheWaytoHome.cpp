//https://codeforces.com/problemset/problem/910/A
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int d, string s){
    int i = 0;

    int ans = 0;
    while(i < n - 1){
      int indexTemp = -1;

      for(int j = i + 1; j <= i + d; ++j){
        if(j < n){
          if(s[j] == '1'){
            indexTemp = j;
          }
        }
      }

      if(indexTemp == -1) return -1;
      i = indexTemp;
      ++ans;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d;
    string s;
    //Nhập n
    cin >> n;

    //Nhập d
    cin >> d;
    cin.ignore();
    getline(cin, s);

    
    cout << solve(n, d, s);
    return 0;
}