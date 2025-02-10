#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int d=1;
		for(int j=1;j<i;j++)d*=a[j];
		for(int j=i+1;j<=n;j++)d*=a[j];
		d*=(a[i]+1);
		ans=max(ans,d);
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
