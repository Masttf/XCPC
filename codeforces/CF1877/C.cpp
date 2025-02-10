#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	if(k>3){
		cout<<0<<'\n';
		return ;
	}
	if(k==1){
		cout<<1<<'\n';
		return ;
	}
	if(k==2){
		int ans=min(n,m);
		if(m>=n)ans+=m/n-1;
		cout<<ans<<'\n';
		return ;
	}
	if(m<=n){
		cout<<0<<'\n';
		return ;
	}
	int ans=m/n-1;
	cout<<m-n-ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}