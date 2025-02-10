#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
void solve(){
	int n,k,x;cin>>n>>k>>x;
	int mx=k*(n+n-k+1)/2;
	int mi=k*(1+k)/2;
	if(mx>=x&&x>=mi)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
