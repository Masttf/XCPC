#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b,n;cin>>a>>b>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=b-1;
		int x;cin>>x;
		b=min(a,1+x);
	}
	ans+=b;
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
