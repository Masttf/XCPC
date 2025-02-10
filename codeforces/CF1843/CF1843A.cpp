#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=55;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n==1){
		cout<<0<<'\n';
		return ;
	}
	int ans=0;
	for(int i=1;i<=n/2;i++)ans+=a[n-i+1]-a[i];
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
