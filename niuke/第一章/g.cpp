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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> a(m + 1);
    vector<int> p;
    p.push_back(0);
    p.push_back(n);
    for(int i = 1; i <= m; i++){
    	int l, r; cin >> l >> r;
        p.push_back(l);
        p.push_back(r + 1);
    	a[i] = {l, r};
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
        return lower_bound(p.begin(), p.end(), x) - p.begin();
    };
    int len = p.size();
    vector<int> v(len);
    for(int i = 1; i <= m; i++){
        auto [l, r] = a[i];
        l = get(l);
        r = get(r + 1);
        v[l]++;
        v[r]--;
    }
    int ans = n + 1;
    for(int i = 0; i < len - 1; i++){
        if(i) v[i] += v[i - 1];
        if(v[i] >= 1){
            ans -= p[i + 1] - p[i];
        }
    }
    cout << ans << '\n';
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