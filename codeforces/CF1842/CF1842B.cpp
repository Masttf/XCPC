#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],c[maxn];
void solve(){
	int n,x;cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	int res=0;
	for(int i=1;i<=n;i++){
		if(((res|a[i])|x)==x)res|=a[i];
		else break;
	}
	for(int i=1;i<=n;i++){
		if(((res|b[i])|x)==x)res|=b[i];
		else break;
	}
	for(int i=1;i<=n;i++){
		if(((res|c[i])|x)==x)res|=c[i];
		else break;
	}
	if(res==x)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
