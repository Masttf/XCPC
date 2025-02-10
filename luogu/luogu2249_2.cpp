#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		int l=1,r=n;
		int ans=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[mid]>=x)ans=mid,r=mid-1;
			else l=mid+1;
		}
		if(a[ans]==x)cout<<ans<<' ';
		else cout<<-1<<' ';
	}
	
	return ;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}