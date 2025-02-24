#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n,k;cin >> n >> k;
    if (n == 1) {
        cout << "Yes" << '\n';
        return ;
    }
    if (k == 1) {
        cout << "No" << '\n';
        return ;
    }
    if (n == k) {
        cout << "Yes" << '\n';
        return ;
    }
    if (k % 2 == 0) {
        cout << "Yes" << '\n';
        return ;
    }
    if (n % 2 == 1) {
        cout << "Yes" << '\n';
        return ;
    }
    else {
        cout << "No" << '\n';
        return ;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}