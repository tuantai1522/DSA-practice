//https://codeforces.com/problemset/problem/1786/A2
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int>answer(4);
    int numberOfCards = 1;

    int it = 1;    
    while (n != 0) {
      //who is 1 and 4 is Alice; who is 2 and 3 is Bob
      int who = (it % 4 == 1 || it % 4 == 0) ? 0 : 1;
      int cnt = it;
      if (n < cnt) {
        cnt = n;
        }
                
      int cntWhite = (cnt + numberOfCards % 2) / 2;
      int cntBlack = cnt - cntWhite;
      answer[who * 2 + 0] += cntWhite;
      answer[who * 2 + 1] += cntBlack;
      numberOfCards += cnt;
      n -= cnt;
      ++it;
    }

    for(int i = 0; i < 4; ++i){
      cout << answer[i] << " ";
      }
      cout << endl;
  }
}