#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector g(n+1,vector<int>());
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		g[i].push_back(i);
		int now=a[i];
		for(auto x:g[i-1]){
			int temp=now;
			now=__gcd(now,a[x]);
			if(now!=temp)g[i].push_back(x);
			if(now==1)break;
		}
	}
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		int ans=0;
		for(auto x:g[r]){
			if(x>=l)ans++;
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}