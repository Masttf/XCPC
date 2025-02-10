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
constexpr int maxn = 5e5 + 5;
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> op(n + 1);
    vector<vector<int>> nums(n + 1);
    vector<int> rt(n + 1, n);
    vector<int> p;
    for(int i = 1; i <= n; i++){
        int ty, x; cin >> ty >> x;
        p.push_back(x);
        op[i] = {ty, x};
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    auto get = [&](int x) -> int{
        return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
    };
    for(int i = 1; i <= n; i++){
        auto &[ty, x] = op[i];
        x = get(x);
        if(ty == 1){
            nums[x].push_back(i);
        }else{
            rt[nums[x].back()] = i - 1;
            nums[x].pop_back();
        }
    }
    vector<vector<int>> tr(n * 4);
    auto insert = [&](auto self, int l, int r, int x, int y, int val, int p) -> void{
        if(x <= l && r <= y){
            tr[p].push_back(val);
            return ;        }
        int mid = (l + r) >> 1;
        if(x <= mid)self(self, l, mid, x, y, val, p << 1);
        if(y > mid)self(self, mid + 1, r, x, y, val, p << 1 | 1);
        return ;
    };
    for(int i = 1; i <= n; i++){
        auto [ty, x] = op[i];
        if(ty == 1){
            // dbg(i, rt[i]);
            insert(insert, 1, n, i, rt[i], p[x - 1], 1);
        }
    }
    vector<int> ans(n + 1);
    bitset<maxn> dp;
    vector<bitset<maxn>>stk;
    dp[0] = 1;
    auto dfs = [&](auto self, int l, int r, int p) -> void{
        stk.push_back(dp);
        for(auto x : tr[p]){
            dp |= dp << x;
        }
        if(l == r){
            ans[l] = dp.count() - 1;
            dp = stk.back();
            stk.pop_back();
            return ;
        }
        int mid = (l + r) >> 1;
        self(self, l, mid, p << 1);
        self(self, mid + 1, r, p << 1 | 1);
        dp = stk.back();
        stk.pop_back();
    };
    dfs(dfs, 1, n, 1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] << '\n';
    }
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
/*
撤销

*/