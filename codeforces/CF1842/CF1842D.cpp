#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int g[maxn][maxn];
bool vis[maxn];
int d[maxn];
int n,m;
pair<string,int>ans[maxn*maxn];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dfs(int now){
	for(int i=1;i<=n;i++){
		if(g[now][i]!=-1&&!vis[i])vis[i]=1,dfs(i);
	}
	return ;
}
void solve(){
	cin>>n>>m;
	string tem="";
	for(int i=1;i<=n;i++)tem+='1';
	tem[n-1]='0';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)g[i][j]=-1;
	}
	for(int i=1;i<=m;i++){
		int u,v,y;cin>>u>>v>>y;
		g[u][v]=y;
		g[v][u]=y;
	}
	vis[1]=1;
	dfs(1);
	if(vis[n]){
		for(int i=1;i<n;i++)vis[i]=0;
		int cnt=0,idx=0,last=0;
		for(int i=1;i<=n;i++){
			if(g[n][i]!=-1)q.push({g[n][i],i});
		}
		while(!q.empty()){
			int cost=q.top().first,u=q.top().second;
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			ans[++idx].first=tem;
			ans[idx].second=cost-last;
			last=cost;
			cnt++;
			tem[u-1]='0';
			if(u==1)break;
			for(int i=1;i<=n;i++){
				if(g[u][i]!=-1&&!vis[i]){
					q.push({cost+g[u][i],i});
				}
			}
		}
		cout<<last<<' '<<cnt<<'\n';
		for(int i=1;i<=idx;i++)cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}else cout<<"inf\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
