#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a,b,c;cin>>a>>b>>c;
	double d=(a+b)*1.0/2;
	double ca=max(a,b)-d;
	int ans=ca/c;
	if(c*ans<ca)ans++;
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
