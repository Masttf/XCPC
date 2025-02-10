#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	vector<int>ans(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		ans[a[i].second]=n-i+1;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
