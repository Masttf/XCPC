#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int pre[maxn],suf[maxn];
void solve(){
	int n,k;cin>>n>>k;
	int s=0;
	for(int i=1;i<=n;i++)cin>>a[i],s+=a[i];
	sort(a+1,a+1+n);
	suf[n+1]=0;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
	int ans=0;
	for(int i=0;i<=k;i++){
		ans=max(ans,s-suf[n-i+1]-pre[(k-i)*2]);
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
