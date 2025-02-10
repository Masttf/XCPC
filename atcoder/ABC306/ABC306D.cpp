#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int ans=0;
	vector<int>dp(n+1);
	vector<int>mx(2);
	mx[1]=-INT_MAX;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		dp[i]=dp[i-1];
		if(x==0){
			int d=max(mx[0]+y,mx[1]+y);
			dp[i]=max(dp[i],d);
			mx[0]=max(mx[0],d);
		}else{
			dp[i]=max(dp[i-1],mx[0]+y);
			mx[1]=max(mx[1],mx[0]+y);
		}
	}
	cout<<dp[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}