#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int ans=-1;
	int l=2,r=2648956421;
	while(l<=r){
		int mid=(l+r)>>1;
		int d=(mid-1)*mid/2;
		if(d<=n)ans=mid,l=mid+1;
		else r=mid-1;
	}
	ans+=n-ans*(ans-1)/2;
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
