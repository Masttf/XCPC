#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=n+1;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		if(y<x)swap(x,y);
		a[x]=min(a[x],y);
	}
	int ans=0;
	int last=n+1;
	for(int i=n;i>=1;i--){
		ans+=min(a[i],last)-i;
		last=min(last,a[i]);
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
