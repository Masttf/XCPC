#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	
	vector<int>ans(n+1);
	vector<int>du(n+1);
	vector<int>vis(n+1);
	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		du[u]++;
		vis[v]++;
	}
	
	queue<int>q;
	for(int i=1;i<=n;i++){
		if(du[i]==0)q.push(i);
	}
	while(!q.empty()){
		int rt=q.front();
		q.pop();
		for(auto v:g[rt]){
			if(a[rt]>=a[v])ans[v]=max(ans[v],ans[rt]+a[rt]-a[v]);
			else ans[v]=max(ans[v],ans[rt]+k+a[rt]-a[v]);
			du[v]--;
			if(du[v]==0)q.push(v);
		}
	}
	
	for(int i=1;i<=n;i++)ans[i]+=a[i];
	
	int res=*max_element(ans.begin()+1,ans.end());
	
	vector<pair<int,int>>b(n+1);//sort之后就可以知道哪些天要在第二天开始
	for(int i=1;i<=n;i++)b[i].first=a[i],b[i].second=i;
	sort(b.begin()+1,b.end());
	
	int ok=res;
	for(int i=1;i<=n;i++){
		if(!vis[b[i].second]){
			ok=min(ok,res-a[b[i].second]);
			res=max(res,ans[b[i].second]+k);
		}
	}
	cout<<ok<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
