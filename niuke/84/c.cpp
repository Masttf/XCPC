#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int ok=1;
	int l=a[1]-k;
	for(int i=2;i<=n;i++){
		int ll=a[i]-k;
		int rr=a[i]+k;
		if(rr>=l)l=max(l,ll);
		else ok=0;
	}
	if(ok)cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}