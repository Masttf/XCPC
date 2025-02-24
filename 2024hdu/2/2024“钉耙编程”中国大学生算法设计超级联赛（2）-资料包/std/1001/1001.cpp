#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin>> n;
    if (n <= 5) {
        for (int i = 0; i < n; i++) cout<< 1<< ' '<< i+2<< '\n';
    } else if (n == 6) {
        for (int i = 2; i <= 5; i++) cout<< 1<< ' '<< i<< '\n';
        for (int i = 0; i < 2; i++) cout<< 2<< ' '<< i+3<< '\n';
    } else {
        for (int i = 0; i < n/3+n%3+2; i++) cout<< 1<< ' '<< i+2<< '\n';
        for (int i = 0; i < n/3; i++) cout<< 2<< ' '<< i+3<< '\n';
        for (int i = 0; i < n/3-2; i++) cout<< 3<< ' '<< i+4<< '\n';
    }
       
}
 
signed main() {
    int T; cin>> T; while (T--)
        solve();
}
