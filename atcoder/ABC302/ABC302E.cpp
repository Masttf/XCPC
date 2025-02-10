#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+5;
int du[maxn];
int limit[maxn];
vector<pair<int,int>>g[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int tot=n;
	for(int i=1;i<=m;i++){
		int t;cin>>t;
		if(t==1){
			int u,v;cin>>u>>v;
			g[u].push_back({v,i});
			g[v].push_back({u,i});
			du[u]++;
			du[v]++;
			if(du[u]==1)tot--;
			if(du[v]==1)tot--;
		}else{
			int v;cin>>v;
			if(du[v])tot++;
			for(auto [u,l]:g[v]){
				if(l>limit[u]){
					du[u]--;
					du[v]--;
					if(du[u]==0)tot++;
				}
			}
			g[v].clear();
			limit[v]=i;
		}
		cout<<tot<<'\n';
	}
	return 0;
}
