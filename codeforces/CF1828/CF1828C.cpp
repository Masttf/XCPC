#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
int a[maxn],b[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int ans=1;
	int flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]<b[i])flag=0;
	}
	if(!flag)cout<<0<<'\n';
	else{
		for(int i=1;i<=n;i++){
			int p=lower_bound(b+1,b+1+n,a[i])-b-1;
			ans=ans*(p-(i-1))%mod;
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
