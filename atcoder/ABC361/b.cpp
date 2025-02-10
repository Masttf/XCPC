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
    array<int, 6> a, b;
    for(int i = 0; i < 6; i++) cin >> a[i];
    for(int i = 0; i < 6; i++) cin >> b[i];
    int l1 = max(a[2], b[2]);
	int r1 = min(a[5], b[5]);
	int l2 = max(a[0], b[0]);
	int r2 = min(a[3], b[3]);
	int l3 = max(a[1], b[1]);
	int r3 = min(a[4], b[4]);
    int ans = max(0ll, r1 - l1) * max(0ll, r2 - l2) * max(0ll, r3 - l3);
    if(ans)cout << "Yes\n";
    else cout << "No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}