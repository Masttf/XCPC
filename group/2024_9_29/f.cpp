#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
    int n, m; cin >> n >> m;
    vector<int>res(n + 1);
    vector<int> cnt1(n + 5), cnt2(n + 5);
    for(int i = 1; i <= m; i++){
    	int l, r, s, e; cin >> l >> r >> s >> e;
    	int d = (e - s) / (r - l);
    	s -= l * d;
    	cnt1[l] += s;
    	cnt1[r + 1] -= s;
    	cnt2[l] += d;
    	cnt2[r + 1] -= d;
    }
    for(int i = 1; i <= n; i++){
    	cnt1[i] += cnt1[i - 1];
    	cnt2[i] += cnt2[i - 1];
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1; i <= n; i++){
    	int d = cnt1[i] + cnt2[i] * i;
    	ans1 ^= d;
    	ans2 = max(ans2, d);
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}