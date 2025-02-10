#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int x;cin>>x;
	for(int i=1;i*i*i<x;i++){
		int d=i*i*i;
		int l=1,r=sqrt(x-d);
		int ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(mid*mid*mid>=x-d)r=mid-1,ans=mid;
			else l=mid+1;
		}
		//cout<<i<<' '<<ans<<'\n';
		if(ans*ans*ans==x-d){
			cout<<"YES\n";
			return ;
		}
	}
	cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}