#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	int ans=INT_MAX;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		int d=(x+k-1)/k*k;
		ans=min(ans,d-x);
		if(x%2==1)cnt++;
	}
	if(k==4){
		if(cnt==n)ans=min(ans,2ll);
		else if(cnt==n-1)ans=min(ans,1ll);
		else ans=min(ans,0ll);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}