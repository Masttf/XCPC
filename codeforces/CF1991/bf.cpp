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
constexpr int maxn = 2e5 + 5;
bool vis[maxn];
vector<int>prim;
void init(){
	vis[1] = 1;
	for(int i = 2; i < maxn; i++){
		if(!vis[i])prim.push_back(i);
		for(int j = 0; prim[j] * i < maxn; j++){
			vis[prim[j] * i] = 1;
			if(i % prim[j] == 0)break;
		}
	}
}
void solve(){
    int n; cin >> n;
    vector<vector<int>>g(n + 1);
    for(int i = 1; i <= n; i++){
    	for(int j = i + 1; j <=n; j++){
    		int res = i ^ j;
    		if(!vis[res]){
                //dbg(i, j);
    			g[i].push_back(j);
                g[j].push_back(i);
    		}
    	}
    }
    vector<int>color(n + 1);
    vector<int>vis(n + 1);
    auto dfs = [&](auto self, int now) -> void{
        for(auto v : g[now]){
            if(color[v]){
                vis[color[v]] = 1;
            }
        }
        int res = 1;
        while(vis[res])res++;
        color[now] = res;
        for(auto v : g[now]){
            if(color[v]){
                 vis[color[v]] = 0;
            }
        }
        for(auto v : g[now]){
            if(!color[v]){
                self(self, v);
            }
        }
    };
    for(int i = 1; i <= n; i++){
        if(!color[i])dfs(dfs, i);
    }
    for(int i = 1; i <= n; i++){
        dbg(i, color[i]);
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();	
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}