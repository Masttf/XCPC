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
    int n, k; cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> vis(n + 1);
    int rt = 0;
    for(int i = 1; i <= k; i++){
    	int x; cin >> x;
    	if(!rt)rt = x;
    	vis[x] = 1;
    }
    vector<int> ans(n + 1);
    auto dfs = [&](auto self, int now, int father) -> void{
    	for(auto v : g[now]){
    		if(v == father)continue;
    		self(self, v, now);
    		ans[now] += ans[v];
    	}
    	if(ans[now] || vis[now])ans[now]++;
    };
    dfs(dfs, rt, 0);
    cout << ans[rt] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}