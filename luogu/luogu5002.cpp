//注意本题的询问次数比点多，说明会重复需要记忆化优化
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10005;
const int mod=1e9+7;
vector<int>g[maxn];
bool vis[maxn];
int cnt[maxn],deep[maxn];//代表每个节点下的个数
int ae[maxn];
void dfs(int x,int de){
	vis[x]=1;
	deep[x]=de;
	int sz=g[x].size();
	for(int i=0;i<sz;i++){
		int y=g[x][i];
		if(vis[y])continue;
		dfs(y,de+1);
		cnt[x]+=cnt[y];
	}
	cnt[x]++;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,r,m;cin>>n>>r>>m;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(r,1);
	while(m--){
		int p;cin>>p;
		if(ae[p]){
			cout<<ae[p]<<'\n';
			continue;
		}
		int ans=cnt[p];
		int sz=g[p].size();
		int sum=0;
		for(int i=0;i<sz;i++){
			int y=g[p][i];
			if(deep[y]==deep[p]+1){
				ans+=sum*cnt[y];
				sum+=cnt[y];
				ans%=mod;
			}
		}
		ans*=2;
		ans%=mod;
		ans--;
		ae[p]=ans;
		cout<<ans<<'\n';
	}
	return 0;
}
