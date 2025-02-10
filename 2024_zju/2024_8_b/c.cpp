
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
    int n,m,q,k;cin>>n>>m>>q>>k;
    vector<int>vis(n+1);
    vector<vector<int>>g(n+1);
    vector<int>du(n+1);
    for(int i=1;i<=q;i++){
    	int x;cin>>x;
    	vis[x]=1;
    }
    for(int i=1;i<=m;i++){
    	int u,v;cin>>u>>v;
    	g[v].push_back(u);
    	du[u]++;
    }
    vector<int>cnt(n+1);
    vector<int>ans(n+1);
    queue<int>qq;
    for(int i=1;i<=n;i++){
    	if(vis[i]||du[i]<=k){
    		qq.push(i);
    	}
    }
    while(!qq.empty()){
    	int u=qq.front();
    	if(vis[u]==1||cnt[u]>k){
    		ans[u]=1;
    	}
    	qq.pop();
    	if(vis[u]==2)continue;
    	vis[u]=2;
    	for(auto v:g[u]){
    		cnt[v]+=ans[u];
    		du[v]--;
    		if(du[v]==0||cnt[v]>k||cnt[v]+du[v]<=k)qq.push(v);
    	}
    }
    // int ct=0;
    // for(int i=1;i<=n;i++){
    // 	if(vis[i]==2)ct++;
    // }
    // assert(ct==n);
    for(int i=1;i<=n;i++){
    	if(ans[i]==1||cnt[i]>k)cout<<'S';
    	else cout<<'B';
    }
    cout<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
