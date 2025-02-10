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
    int n, X; cin >> n >> X;
    vector<pair<int, int>> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
        cin >> b[i].first >> b[i].second;
    }
    auto get = [&](int x, int limit) -> int{
        int ans = 1e9;
        int LCM = lcm(a[x].first, b[x].first);
        limit -= LCM;
        int res = min((limit / LCM) * LCM / b[x].first * b[x].second, (limit / LCM) * LCM / a[x].first * a[x].second);
        limit = limit % LCM;
        limit += LCM;
        for(int i = 0; i * a[x].first <= limit; i++){
            int d = i * a[x].second + (limit - a[x].first * i + b[x].first - 1) / b[x].first * b[x].second;
            ans = min(ans, res + d);
        }
        for(int i = 0; i * b[x].first <= limit; i++){
            int d = i * b[x].second + (limit - b[x].first * i + a[x].first - 1) / a[x].first * a[x].second;
            ans = min(ans, res + d);
        }
        return ans;
    };
    auto check = [&](int limit) -> bool{
        int tot = 0;
        for(int i = 1; i <= n; i++){
            tot += get(i, limit);
        }
        return tot <= X;
    };
    int l = 0, r = 1e10;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}