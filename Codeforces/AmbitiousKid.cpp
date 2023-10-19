//https://codeforces.com/problemset/problem/1866/A
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n;
  cin >> n;
  
  int Min = 1000000005;

  for(int i = 0; i < n; ++i){
    int x;
    cin >> x;

    Min = min(Min, abs(x));
  }


  cout << Min;
  

  return 0;
}