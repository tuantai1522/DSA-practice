//https://codeforces.com/problemset/problem/460/A
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n, m;
  cin >> n >> m;

  int ans = 0;
  if(n < m) {
    cout << n;
  }else{
    if(n / m == 1){
      ans = n + 1;
    }else{
      while(n > 0){
        
        //phần tử cuối cùng
        if(n / m == 0){
          ans += n;
        }else{
          ans += m;
        }
        n = (n - m) + 1;
      }
    }
    cout << ans;
  }

  return 0;
}