#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int x,y;cin>>x>>y;
	int ans=0;
	for(int i=30;i>=0;i--){
		if(y>=x){
			ans+=y-x;
			break;
		}
		int d1=(y>>i)&1;
		int d2=(x>>i)&1;
		ans+=(d1^d2)<<i;
		x-=(d1^d2)<<i;
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