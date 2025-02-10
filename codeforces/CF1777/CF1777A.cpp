#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1005];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0;
	for(int i=1;i<n;i++){
		int t=a[i]%2;
		int len=0;
		while(i<n&&a[i+1]%2==t)len++,i++;
		ans+=len;
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
