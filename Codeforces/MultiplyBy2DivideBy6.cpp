//https://codeforces.com/problemset/problem/1374/B


// Ta phải tìm xem 2^x + 3^y = n
//Sau đó x < y bởi vì có thể loại bỏ toàn bộ số 2 mũ vì 2 mũ * 2 / 6 thì sẽ dư. Trong khi đó giữ số mũ 3 thì 3 mũ * 2 / 6 sẽ là số tròn
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
		int cnt2 = 0, cnt3 = 0;
		while (n % 2 == 0) {
			n /= 2;
			++cnt2;
		}
		while (n % 3 == 0) {
			n /= 3;
			++cnt3;
		}
    if(n == 1 && cnt2 <= cnt3){
      cout << 2 * cnt3 - cnt2 << endl;
    }else{
      cout << "-1\n";
    }
  }
}