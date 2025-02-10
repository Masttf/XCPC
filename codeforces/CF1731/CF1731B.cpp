#include<bits/stdc++.h>
#define int long long
#define ll __int128
using namespace std;
const int eps=1e9+7;
void solve(){
	int n;cin>>n;
	ll temp=n;
	ll sum=temp*(temp+1)*(2*temp+1)/6+(temp-1)*(temp)*(temp+1)/3;
	sum*=2022;sum%=eps;
	int ans=sum;
	cout<<ans<<'\n';
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
