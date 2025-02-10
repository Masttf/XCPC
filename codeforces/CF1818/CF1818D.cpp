#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2005;
bool g2[maxn][maxn];
vector<int>belong[maxn];
vector<int>g[maxn];
stack<int>s;
int dfn[maxn],low[maxn],idx,cnt,f[maxn],k[maxn];
bool instack[maxn],vis[maxn];
int n,m;
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	s.push(u);
	instack[u]=1;
	for(int v=1;v<=n;v++){
		if(!g2[u][v])continue;
		if(!dfn[v]){
			g2[v][u]=0;
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}else if(instack[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	if(dfn[u]==low[u]){
		cnt++;
		int temp;
		do{
			temp=s.top();
			s.pop();
			instack[temp]=0;
			f[temp]=cnt;
			belong[cnt].push_back(temp);
		}while(temp!=u);
	}
	return ;
}
void solve(){
	cin>>n>>m;
	idx=0,cnt=0;
	vector<pair<int,int>>e;
	for(int i=1;i<=n;i++)belong[i].clear(),dfn[i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g2[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		k[u]++;
		k[v]++;
		g[u].push_back(v);
		g[v].push_back(u);
		g2[u][v]=1;
		g2[v][u]=1;
		e.push_back({u,v});
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i])tarjan(i);
	}
	int flag=0;
	int res2;
	for(int i=1;i<=n;i++){
		if(k[i]>=4&&belong[f[i]].size()>2){
			flag=1;
			res2=i;
			break;
		}
	}
	if(flag){
		cout<<"YES\n";
		
	}else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
