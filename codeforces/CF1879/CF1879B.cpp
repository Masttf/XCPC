#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a.begin()+1,a.end());
	sort(b.begin()+1,b.end());
	int ans=LONG_LONG_MAX;
	int res=0;
	for(int i=1;i<=n;i++)res+=a[i]+b[1];
	ans=min(ans,res);
	res=0;
	for(int i=1;i<=n;i++)res+=b[i]+a[1];
	ans=min(ans,res);
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
