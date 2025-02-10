#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	unsigned long long ans=0;
	unsigned long long base=1;
	for(int i=0;i<64;i++){
		int x;cin>>x;
		ans+=x*base;
		base*=2;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}