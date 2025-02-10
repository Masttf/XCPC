#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	vector<int>cnt(k+1);
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		if(x>k)continue;
		cnt[x]=max(cnt[x],y);
	}
	int ans=0;
	for(int i=1;i<=k;i++)ans+=a[i];
	vector<int>pre(k+1);
	for(int i=1;i<=k;i++)pre[i]=pre[i-1]+a[i];
	
	vector<int>dp(k+1);
	
	for(int i=1;i<=k;i++){
		dp[i]=dp[i-1]+a[i];
		for(int j=1;j<=i;j++){
			dp[i]=min(dp[i],dp[i-j]+pre[i]-pre[i-(j-cnt[j])]);
		}
	}
	cout<<dp[k]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}