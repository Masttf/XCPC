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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector g(n+1,vector<int>());
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		if(a[u]<a[v]){
			g[u].push_back(v);
		}
		else if(a[u]>a[v]){
			g[v].push_back(u);
		}else{
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	vector<int>dfn(n+1),low(n+1);
	vector<int>stk;
	vector<int>bl(n+1);
	vector<int>val(n+1);
	int tot=0;
	int cnt=0;
	auto tarjan = [&](auto self,int now)->void{
		dfn[now]=low[now]=++tot;
		stk.push_back(now);
		for(auto v:g[now]){
			if(!dfn[v]){
				self(self,v);
				low[now]=min(low[now],low[v]);
			}else if(!bl[v]) low[now]=min(low[now],dfn[v]);
		}
		if(dfn[now]==low[now]){
			int y;
			cnt++;
			do{
				y=stk.back();
				stk.pop_back();
				bl[y]=cnt;
				val[cnt]=a[y];
			}while(y!=now);
		}
	};
	tarjan(tarjan,1);
	vector e(cnt+1,vector<int>());
	vector<int>du(cnt+1);
	for(int i=1;i<=n;i++){
		if(!bl[i])continue;
		for(auto v:g[i]){
			if(bl[i]==bl[v])continue;
			e[bl[i]].push_back(bl[v]);
			du[bl[v]]++;
		}
	}
	vector<int>dp(cnt+1);
	dp[bl[1]]=1;
	auto bfs = [&]()->void{
		queue<int>q;
		q.push(bl[1]);
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				du[v]--;
				dp[v]=max(dp[v],dp[u]+(val[u]==val[v]?0:1));
				if(!du[v])q.push(v);
			}
		}
	};
	bfs();
	cout<<dp[bl[n]]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}