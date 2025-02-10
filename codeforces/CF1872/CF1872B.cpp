#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second;
	sort(a.begin()+1,a.end());
	int l=INT_MAX;
	for(int i=1;i<=n;i++){
		if(l<a[i].first)break;
		l=min(l,a[i].first+(a[i].second-1)/2);
	}
	cout<<l<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
