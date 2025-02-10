#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	int ans=0;
	int dx=n/2+1;
	int dy=m/2+1;
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		int t=abs(x-dx)+abs(y-dy);
		if(t<=max(n/2,m/2))ans++;
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