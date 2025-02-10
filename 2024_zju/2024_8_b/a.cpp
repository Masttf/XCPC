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
constexpr int Max=1e18;
void solve(){
    int n,m;cin>>n>>m;
    vector<int>l(n+1),r(n+1);
    vector<vector<pair<int,int>>>g(n+1);
    for(int i=1;i<=n;i++)cin>>l[i]>>r[i];
    for(int i=1;i<=m;i++){
    	int u,v,w;cin>>u>>v>>w;
    	g[u].push_back({v,w});
    }
    vector d(2,vector<int>(n+1,Max));
    vector vis(2,vector<int>(n+1));
    auto dijkstra = [&](int s)->void{
    	priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    	d[0][s]=0;
    	q.push({d[0][s],0,s});
    	while(!q.empty()){
    		auto [ww,ty,u]=q.top();
    		q.pop();
    		if(vis[ty][u])continue;
    		//dbg(u,ty);
    		vis[ty][u]=1;
    		for(auto [v,w]:g[u]){
    			int ls=d[ty][u]+w;
    			//dbg(v,ls);
    			if(ls>=r[v]){
    				if(d[1][v]>ls){
    					d[1][v]=ls;
    					q.push({d[1][v],1,v});
    				}
    			}else if(ls<=l[v]){
    				if(d[0][v]>ls){
    					d[0][v]=ls;
    					q.push({d[0][v],0,v});
    				}
    			}else{
    				int tm=r[v]-ls;
    				if(ty==1){
    					if(d[1][v]>r[v]){
    						d[1][v]=r[v];
    						q.push({d[1][v],1,v});
    					}
    				}else{
    					int t=d[0][u]+tm;
    					if(t<=l[u]){
    						ls+=tm;
    						if(d[1][v]>ls){
		    					d[1][v]=ls;
		    					q.push({d[1][v],1,v});
		    				}
    					}
    				}
    			}
    		}
    	}
    };
    dijkstra(1);
    int ans=min(d[0][n],d[1][n]);
    if(ans==Max)cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}
