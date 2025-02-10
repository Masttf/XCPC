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

void solve2() {
    int x = 17;
    for(int i = 30; i >= 0; i--){
        int d = x >> i & 1;
        cout << d;
    }
    cout << endl;
    for (int i = 1;i <= 1000;i++) {
        int now = __gcd((x * i) ^ x, x);
        dbg(i, now);
        // if(now == 1)dbg(i);
    }
}

void solve(){
    int x,n;cin >> x >> n;
    for (int i = 1;i <= n;i++) {
        int ans = 0;
        int l,r;cin >> l >> r;
        if (__gcd(x * l ^ l,l) == 1) {
            int len = (r - l + 1);
            if (len % 2 == 0) {
                cout << len / 2 << '\n';
            }
            else {
                cout << len / 2 + 1 << '\n';
            }
        }
        else {
            int len = (r - l + 1);
            cout << len / 2 << '\n';
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    //while(t--)solve();
    solve2();
    return 0;
}