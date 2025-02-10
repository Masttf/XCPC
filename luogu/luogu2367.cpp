#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>b(n+5);
	vector<int>a(n+5);
	for(int i=1;i<=n;i++)cin>>b[i];

	for(int i=1;i<=n;i++)a[i]=b[i]-b[i-1];
	for(int i=1;i<=m;i++){
		int l,r,x;cin>>l>>r>>x;
		a[l]+=x;
		a[r+1]-=x;
	}
	int ans=INT_MAX;
	for(int i=1;i<=n;i++)a[i]+=a[i-1],ans=min(ans,a[i]);
	//for(int i=1;i<=n;i++)cout<<a[i]<<'\n';
	cout<<ans<<'\n';
	return ;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}