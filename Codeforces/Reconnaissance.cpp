#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, d;
    cin >> n >> d;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a + n);
    long long res = 0;
    int j = 1;
    for(int i = 0; i < n; ++i){
        while(j < n && a[j] - a[i] <= d){
            j++;
        }
        j--;
        res += j - i;
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
    }
    cout << 2 * res;
    return 0;
}