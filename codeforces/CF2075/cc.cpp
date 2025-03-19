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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int k = 1; k <= n - 1; ++k) {
        int s1 = k;
        int s2 = n - k;
        auto cnt_left = a.end() - lower_bound(a.begin(), a.end(), s1);
        auto cnt_right = a.end() - lower_bound(a.begin(), a.end(), s2);
        int max_s = max(s1, s2);
        auto same = a.end() - lower_bound(a.begin(), a.end(), max_s);
        ans += 1LL * cnt_left * cnt_right - same;
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}