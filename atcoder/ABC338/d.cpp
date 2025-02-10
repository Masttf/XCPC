#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>b(m+1);
	for(int i=1;i<=m;i++)cin>>b[i];
	vector<int>cnt(n+5);
	for(int i=1;i<m;i++){
		int u=b[i],v=b[i+1];
		if(u>v)swap(u,v);
		int d1=v-u;
		int d2=n-d1;
		cnt[u]+=d2;
		cnt[v]-=d2;
		cnt[1]+=d1;
		cnt[u]-=d1;
		cnt[v]+=d1;
		cnt[n+1]-=d1;
	}
	for(int i=1;i<=n;i++)cnt[i]+=cnt[i-1];
	int ans=LONG_LONG_MAX;
	for(int i=1;i<=n;i++)ans=min(ans,cnt[i]);
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