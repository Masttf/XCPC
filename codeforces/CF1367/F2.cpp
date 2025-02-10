#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p.push_back(a[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(p.begin(),p.end(),a[i])-p.begin()+1;
	}
	int ans=0;

	vector<int>l(n+1),r(n+1),tot(n+1);
	for(int i=1;i<=n;i++){
		if(!l[a[i]])l[a[i]]=i;
		r[a[i]]=i;
		tot[a[i]]++;
	}

	vector<int>pos(n+1);
	vector<vector<int>>dp(3,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		dp[0][i]=dp[0][pos[a[i]]]+1;
		dp[1][i]=max(dp[1][pos[a[i]]]+1,max(dp[0][pos[a[i]-1]]+1,dp[2][pos[a[i]-1]]+1));
		if(i==r[a[i]]){
			dp[2][i]=dp[1][l[a[i]]]+tot[a[i]]-1;
		}
		ans=max({ans,dp[0][i],dp[1][i],dp[2][i]});
		pos[a[i]]=i;
	}
	cout<<n-ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
/*
1
20
16 15 1 10 0 14 0 10 3 9 2 5 4 5 17 9 10 20 0 9
*/