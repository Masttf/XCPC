#include<bits/stdc++.h>
#define int long long
using namespace std;
int mi(int a,int b,int c,int d){
	return min(a,min(b,min(c,d)));
}
void solve(){
	int n,m;cin>>n>>m;
	int t=log2(min(n,m));
	vector<vector<int>>g(n+1,vector<int>(m+1));
	vector<vector<vector<int> > >st(n+1,vector<vector<int> >(m+1,vector<int>(t+1)));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			st[i][j][0]=g[i][j];
		}
	}
	for(int k=1;k<=t;k++){
		for(int i=1;i+(1<<k)<=n+1;i++){
			for(int j=1;j+(1<<k)<=m+1;j++){
				st[i][j][k]=mi(st[i][j][k-1],st[i+(1LL<<(k-1))][j][k-1],st[i][j+(1LL<<(k-1))][k-1],st[i+(1LL<<(k-1))][j+(1LL<<(k-1))][k-1]);
			}
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int l=0,r=min(n-i+1,m-j+1);
			while(l<=r){
				int mid=(l+r)>>1;
				int ll=log2(mid);
				bool flag=mid<=mi(st[i][j][ll],st[i+mid-(1LL<<ll)][j][ll],st[i][j+mid-(1LL<<ll)][ll],st[i+mid-(1LL<<ll)][j+mid-(1LL<<ll)][ll]);
				if(flag)ans=max(ans,mid),l=mid+1;
				else r=mid-1;
			}
		}
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
