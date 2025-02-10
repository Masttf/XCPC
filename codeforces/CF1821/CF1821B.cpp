#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int l=1,r=n;
	int mi=INT_MAX,mx=0;
	while(l<=n&&a[l]==b[l])l++;
	while(r>=1&&a[r]==b[r])r--;
	for(int i=l;i<=r;i++)mi=min(a[i],mi),mx=max(a[i],mx);
	while(l>=2&&a[l-1]<=mi){
		l--;
		mi=a[l];
	}
	while(r<=n-1&&a[r+1]>=mx){
		r++;
		mx=a[r];
	}
	cout<<l<<' '<<r<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
