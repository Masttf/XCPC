#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],ma[maxn];
void solve(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	ma[1]=a[1];
	for(int i=2;i<=n;i++){
		ma[i]=max(ma[i-1],a[i]);
	}
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=q;i++){
		int k;
		cin>>k;
		int pos=upper_bound(ma+1,ma+1+n,k)-ma;
		cout<<a[pos-1]<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
