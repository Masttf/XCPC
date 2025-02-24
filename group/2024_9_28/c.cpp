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
    int n; cin >> n;
    vector<vector<int>>g(2 * n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	int x; cin >> x;
    	g[i].push_back(x);
    }
    vector<int> dfn(2 * n + 1), low(2 * n + 1);
    vector<int> bl(2 * n + 1), sz(2 * n + 1);
    vector<int> stk;
    int tot = 0, cnt = 0;
    auto tarjan = [&](auto self, int now) -> void{
    	dfn[now] = low[now] = ++tot;
    	//dbg(now);
    	stk.push_back(now);
    	for(auto v : g[now]){
    		if(!dfn[v]){
    			self(self, v);
    			low[now] = min(low[now], low[v]);
    		}else if(!bl[v]) low[now] = min(low[now], dfn[v]);
    	}
    	if(dfn[now] == low[now]){
    		int y;
    		cnt++;
    		do{
    			y = stk.back();
    			stk.pop_back();
    			bl[y] = cnt;
    			sz[cnt]++;
    			//dbg(cnt, y);
    		}while(y != now);
    	}
    };
    for(int i = 1; i <= n; i++){
    	if(!dfn[i])tarjan(tarjan, i);
    }
    //dbg(cnt);
    vector<int> du(2 * n + 1);
    vector<vector<int>> G(2 * n + 1);
    vector<int>mx(2 * n + 1);
    vector<int> vis(2 * n + 1);
    for(int i = 1; i <= n; i++){
    	for(auto v : g[i]){
    		if(v == i)vis[bl[i]] = 1;
    		if(bl[i] == bl[v])continue;
    		G[bl[i]].push_back(bl[v]);
    		du[bl[v]]++;
    	}
    }
    queue<int>q;
    for(int i = 1; i <= cnt; i++){
    	if(!du[i])q.push(i);
    }
    while(!q.empty()){
    	int u = q.front();
    	q.pop();
    	if(G[u].empty()){
    		if(sz[u] == 1 && !vis[u])ans += mx[u];
    		else{
    			ans += sz[u];
    		}
    	}
    	for(auto v : G[u]){
    		du[v]--;
    		mx[v] = max(mx[v], mx[u] + 1);
    		if(!du[v])q.push(v);
    	}
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