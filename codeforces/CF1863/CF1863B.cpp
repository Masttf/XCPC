#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first,a[i].second=i;
	sort(a.begin()+1,a.end());
	int ans=0;
	for(int i=2;i<=n;i++){
		if(a[i-1].second>a[i].second)ans++;
	}
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
