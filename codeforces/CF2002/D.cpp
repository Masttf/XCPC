#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    int n, q; cin >> n >> q;
    vector<vector<int>>g(n + 1);
    vector<int>vis(n + 1);
    vector<int>p(n + 1);
    for(int i = 2; i <= n; i++){
    	cin >> p[i];
        g[p[i]].push_back(i);
    }
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector<int>sz(n + 1);
    vector<int>st(n + 1), ed(n + 1);
    int dfn = 0;
    auto dfs = [&](auto self, int now) -> void{
        st[now] = ++dfn;
        sz[now] = 1;
        for(auto v :g[now]){
            self(self, v);
            sz[now] += sz[v];
        }
        ed[now] = dfn;
    };
    dfs(dfs, 1);
    auto check = [&](int x, int y) -> bool{
        if(x == y)return true;
        if(!g[y].empty())return false;
        if(st[y] < st[x])return false;
        if(ed[y] > ed[x])return false;
        return true;
    };
    int cnt = 0;
    auto get = [&](int x) -> void{
        if(x > n)return ;
        if(vis[x])cnt--;
        vis[x] = 0;
        if(check(p[a[x]], a[x - 1])){
            cnt++;
            vis[x] = 1;
        }
    };
    for(int i = 1; i <= n; i++){
        get(i);
    }
    for(int i = 1; i <= q; i++){
    	int x, y; cin >> x >> y;
        swap(a[x], a[y]);
        get(x);
        get(x + 1);
        get(y);
        get(y + 1);
        if(cnt == n)cout << "Yes\n";
        else cout << "No\n";
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}