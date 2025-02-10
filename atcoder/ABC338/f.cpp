#include<bits/stdc++.h>
#define int long long
#define Max 1e18
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector g(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)g[i][j]=0;
			else g[i][j]=Max;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		u--;v--;
		g[u][v]=min(g[u][v],w);
	}
	int ok=0;
	auto spfa = [&](int s)->void{
		vector<int>d(n,Max);
		queue<pair<int,int>>q;
		d[s]=0;
		q.push({d[s],s});
		while(!q.empty()){
			auto [ww,u]=q.front();
			q.pop();
			for(int i=0;i<n;i++){
				if(g[u][i]!=Max&&g[u][i]+ww<d[i]){
					d[i]=g[u][i]+ww;
					q.push({d[i],i});
				}
			}
		}
		int res=1;
		for(int i=0;i<n;i++){
			if(d[i]>=Max)res=0;
		}
		ok|=res;
	};
	for(int i=0;i<n;i++)spfa(i);
	if(!ok){
		cout<<"No\n";
		return ;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		}
	}
	vector dp(n,vector<int>(1<<n,Max));
	for(int i=0;i<n;i++){
		dp[i][1<<i]=0;
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			if(i>>j&1){
				for(int k=0;k<n;k++){
					if((i^(1<<j))>>k&1){
						dp[j][i]=min(dp[j][i],dp[k][i^(1<<j)]+g[k][j]);
					}
				}
			}
		}
	}
	int ans=Max;
	for(int i=0;i<n;i++)ans=min(ans,dp[i][(1<<n)-1]);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}