#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
vector<pair<int,int>>g[maxn];
int cnt[maxn];
void dfs(int now,int father,int val){
	int res=0;
	for(auto x:g[now]){
		if(x.first!=father){
			dfs(x.first,now,x.second);
			if(val>x.second)res=max(cnt[x.first]+1,res);
			else res=max(cnt[x.first],res);
		}
	}
	cnt[now]=res;
	return ;
}
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cnt[i]=0;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back({v,i});
		g[v].push_back({u,i});
	}
	dfs(1,0,0);
	cout<<cnt[1]+1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
