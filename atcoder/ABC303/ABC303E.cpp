#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
vector<int>g[maxn];
int sz[maxn];
vector<int>ans;
void dfs(int now,int father){
	sz[now]=1;
	for(auto v:g[now]){
		if(v==father)continue;
		dfs(v,now);
		sz[now]+=sz[v];
	}
	if(sz[now]>=2){
		if(now==1) ans.push_back(sz[now]-1);//注意根节点不需要再向上拿
		else ans.push_back(sz[now]);
		sz[now]=0;
		sz[father]--;
	}
	return ;
}
signed main(){//注意星之间连边是叶子节点
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	sort(ans.begin(),ans.end());
	for(auto x:ans)cout<<x<<' ';
	return 0;
}
