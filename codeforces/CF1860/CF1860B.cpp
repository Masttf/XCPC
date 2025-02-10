#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k,a1,ak;cin>>n>>k>>a1>>ak;
	int d=n%k;
	int ans=0;
	if(a1>=d)ak+=(a1-d)/k;
	else ans+=d-a1;
	d=n/k;
	ans+=max(0LL,d-ak);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
