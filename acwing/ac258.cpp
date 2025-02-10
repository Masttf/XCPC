#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(2*n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)a[i]^=a[i-1];
	vector tr(2,vector<int>(n*62));
	vector<int>root(2*n+1);
	vector<int>cnt(n*62);
	int tot=0;
	auto insert = [&](int u,int v,int x)->void{
		for(int i=30;i>=0;i--){
			int d=x>>i&1;
			tr[0][u]=tr[0][v];
			tr[1][u]=tr[1][v];
			tr[d][u]=++tot;
			u=tr[d][u];
			v=tr[d][v];
			cnt[u]=cnt[v]+1;
		}
	};
	auto query = [&](int u,int v,int x)->int{
		int res=0;
		for(int i=30;i>=0;i--){
			int d=x>>i&1;
			d^=1;
			if(cnt[tr[d][u]]-cnt[tr[d][v]]){
				res+=1<<i;
			}else d^=1;
			u=tr[d][u];
			v=tr[d][v];
		}
		return res;
	};
	for(int i=1;i<=n;i++){
		root[i]=++tot;
		insert(root[i],root[i-1],a[i]);
	}
	for(int i=1;i<=m;i++){
		char t;cin>>t;
		if(t=='A'){
			int x;cin>>x;
			n++;
			a[n]=a[n-1]^x;
			root[n]=++tot;
			insert(root[n],root[n-1],a[n]);
		}else{
			int l,r,x;cin>>l>>r>>x;
			int ans=query(root[r-1],root[max(0ll,l-2)],x^a[n]);
			if(l==1)ans=max(ans,a[n]^x);
			cout<<ans<<'\n';
		}

	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}