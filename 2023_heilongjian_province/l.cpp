#include<bits/stdc++.h>
//#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
	int d=sqrt(n);
	while(d*d<n)d++;
	while(d*d>n)d--;
	vector<int>p(n+1);
	int tot=0;
	int now=1;
	for(int i=1;i<=n;i++){
		p[i]=now;
		tot++;
		if(tot==d){
			now++;
			tot=0;
		}
	}
	vector tr(2,vector<int>(35*n));
	vector<int>cnt(n*35);
	vector<int>root(n*35);
	tot=0;
	auto insert = [&](int u,int v,int x)->void{
		for(int i=31;i>=0;i--){
			tr[0][u]=tr[0][v];
			tr[1][u]=tr[1][v];
			int d=x>>i&1;
			tr[d][u]=++tot;
			u=tr[d][u];
			v=tr[d][v];
			cnt[u]=cnt[v]+1;
		}
	};
	int q;cin>>q;

	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}