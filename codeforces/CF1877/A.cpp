#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int sum=0;
	for(int i=1;i<=n-1;i++)cin>>a[i],sum+=a[i];
	sum=-sum;
	cout<<sum<<'\n';

	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}