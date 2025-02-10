#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;//肯定是分为两个gcd最大
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	int ans=1;
	for(int i=1;i<=n-1;i++){
		int t=__gcd(a[i],a[n]-a[i]);
		ans=max(ans,t);
	}
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
