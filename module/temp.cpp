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
struct node{
	int v,w;
};
constexpr int Max=1e18;
void solve(){
	int n,m,s,t;cin>>n>>m>>s>>t;
	vector<node>e;
	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g[u].push_back(e.size());
		e.push_back({v,w});
		g[v].push_back(e.size());
		e.push_back({u,0});
	}
	vector<int>h(n+1);
	auto bfs = [&]()->bool{
		h.assign(n+1,-1);
		h[s]=0;
		queue<int>q;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto x:g[u]){
				auto [v,w]=e[x];
				//dbg(u,uu,v,w);
				if(w&&h[v]==-1){
					h[v]=h[u]+1;
					if(v==t)return true;
					q.push(v);
				}
			}
		}
		return false;
	};
	vector<int>cur(n+1);
	auto dfs = [&](auto self,int now,int tot)->int{
		//dbg(now);
		if(now==t)return tot;
		int res=tot;
		for(int  &i=cur[now];i<g[now].size();i++){
			int j=g[now][i];
			auto [v,w]=e[j];
			if(w&&h[v]==h[now]+1){
				int d=self(self,v,min(w,res));
				res-=d;
				e[j].w-=d;
				e[j^1].w+=d;
				if(res<=0)return tot;
			}
		}
		return tot-res;
	};
	int ans=0;
	while(bfs()){
		//dbg(ans);
		cur.assign(n+1,0);
		ans+=dfs(dfs,s,Max);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}