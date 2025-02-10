#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a.begin()+1,a.end());
	int mx=0;
	for(int i=1;i<=n;i++){
		if(a[i]==mx)mx++;
	}
	if(mx==0){
		cout<<0<<'\n';
		return ;
	}
	vector<int>cnt(mx+1);
	for(int i=1;i<=n;i++){
		if(a[i]>=mx)break;
		cnt[a[i]]++;
	}
	vector<int>dp(mx);
	for(int i=0;i<mx;i++)dp[i]=(cnt[i]-1)*mx+i;
	for(int i=mx-1;i>=0;i--){
		for(int j=i-1;j>=0;j--){
			dp[j]=min(dp[j],dp[i]+(cnt[j]-1)*i+j);
		}
	}
	cout<<dp[0]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
