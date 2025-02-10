#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	vector<int>b(m+1);
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];

	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}

	vector<int>color(n+1);
	int ok=1;
	auto dfs = [&](auto self,int now,int t)->void{
		if(!ok)return ;
		color[now]=t;
		for(auto x:g[now]){
			if(color[x]){
				if(color[x]==color[now])ok=0;
			}else self(self,x,t^1);
		}
		return ;
	};
	for(int i=1;i<=n;i++){
		if(!color[i]){
			dfs(dfs,i,2);
		}
	}
	if(ok)cout<<"Yes";
	else cout<<"No";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}