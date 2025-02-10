#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<pair<int,int>>a(k+1);
	for(int i=1;i<=k;i++)cin>>a[i].second>>a[i].first;
	//sort(a.begin()+1,a.end());
	vector<int>vis(n+1);
	vector<int>d(n+1,-1);
	priority_queue<pair<int,int>>q;
	for(int i=1;i<=k;i++){
		q.push(a[i]);
		d[a[i].second]=a[i].first;
	}

	while(!q.empty()){
		int rt=q.top().second;
		q.pop();
		if(vis[rt])continue;
		vis[rt]=1;
		for(auto v:g[rt]){
			if(d[v]<d[rt]-1){
				d[v]=d[rt]-1;
				q.push({d[v],v});
			}
		}
	}

	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(d[i]>=0)ans.push_back(i);
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}