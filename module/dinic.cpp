#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int Max=1e18;
struct Max_Flow{
	struct node{
		int v,w;
	};
	int n;
	vector<node>e;
	vector<vector<int>>g;
	vector<int>h,cur;
	Max_Flow(int n){
		init(n);
	}
	void add(int u,int v,int w){
		g[u].push_back(e.size());
		e.push_back({v,w});
		g[v].push_back(e.size());
		e.push_back({u,0});
	}
	void init(int n) {
        this->n = n;
        e.clear();
        g.assign(n+1, {});
        cur.resize(n+1);
        h.resize(n+1);
    }
    bool bfs (int s,int t){
		h.assign(n+1,-1);
		queue<int>q;
		h[s]=0;
		q.push(s);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto i:g[u]){
				auto [v,w]=e[i];
				if(h[v]==-1&&w){
					h[v]=h[u]+1;
					if(v==t){
						return true;
					}
					q.push(v);
				}
			}
		}
		return false;
	}
	int dfs(int u,int t,int val){
		if(u==t)return val;
		int res=val;
		for(auto &i=cur[u];i<(int)g[u].size();i++){
			int j=g[u][i];
			auto [v,w]=e[j];
			if(w&&h[v]==h[u]+1){
				int d=dfs(v,t,min(res,w));
				e[j].w-=d;
				e[j^1].w+=d;
				res-=d;
				if(res==0)return val;
			}
		}
		return val-res;
	}
	int flow(int s,int t){
		int ans=0;
		while(bfs(s,t)){
			cur.assign(n+1,0);
			ans+=dfs(s,t,Max);
		}
		return ans;
	}
};
void solve(){
	int n,m,s,t;cin>>n>>m>>s>>t;
	Max_Flow g(n);
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		g.add(u,v,w);
	}
	cout<<g.flow(s,t)<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}