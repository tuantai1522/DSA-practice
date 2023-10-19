//https://codeforces.com/problemset/problem/1013/A
#include<bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n;
  cin >> n;

  vector<int>arrX(n);
  vector<int>arrY(n);

  long long sum1 = 0;
  long long sum2 = 0;
  for(int i = 0; i < n; ++i){
    cin >> arrX[i];
    sum1 += arrX[i];
  }

  for(int i = 0; i < n; ++i){
    cin >> arrY[i];
    sum2 += arrY[i];
  }

  if(sum1 < sum2){
    cout << "No";
  }else{
    cout << "Yes";
  }
  return 0;
}