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
const int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	vector g(n+1,vector<pair<int,int>>());
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<int>dfn(n+1),low(n+1);
	vector<int>f(n+1,-1);
	vector<int>stk;
	int tot=0;
	int cnt=0;
	auto tarjan = [&](auto self,int x,int father)->void{
		dfn[x]=low[x]=++tot;
		stk.push_back(x);
		for(auto [v,w]:g[x]){
			if(v==father)continue;
			if(!dfn[v]){
				self(self,v,x);
				low[x]=min(low[x],low[v]);
			}else if(f[v]==-1) low[x]=min(low[x],dfn[v]);
		}
		if(dfn[x]==low[x]){
			cnt++;
			int y;
			do{
				y=stk.back();
				stk.pop_back();
				f[y]=cnt;
				//dbg(cnt,y);
			}while(y!=x);
		}
	};
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(tarjan,i,0);
	}
	int ans=Max;
	int s=-1,t=-1;
	for(int i=1;i<=n;i++){
		for(auto [v,w]:g[i]){
			if(f[v]==f[i]){
				if(w<ans){
					ans=w;
					s=i,t=v;
				}
			}
		}
	}
	//dbg(ans,s,t);
	vector<int>track;
	auto bfs = [&]()->void{
		vector<int>p(n+1);
		vector<int>vis(n+1);
		queue<int>q;
		q.push(s);
		vis[s]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			//dbg(u);
			for(auto [v,w]:g[u]){
				if(u==s&&v==t)continue;
				if(vis[v]||f[v]!=f[s])continue;
				p[v]=u;
				vis[v]=1;
				q.push(v);
			}
		}
		int nw=t;
		while(nw!=s){
			track.push_back(nw);
			nw=p[nw];
		}
		track.push_back(nw);
	};
	bfs();
	cout<<ans<<' '<<track.size()<<'\n';
	for(auto x:track)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}