#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>ans;
	ans.push_back(a[1]);
	for(int i=2;i<=n;i++){
		ans.push_back(a[i]);
		if(a[i]<a[i-1])ans.push_back(a[i]);
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
