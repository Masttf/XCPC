#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<pair<int,int>>res(m+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		res[i]={u,v};
	}
	int ans=n;
	auto dfs = [&](auto self,int x)->void{
		if(x==m+1){
			int res=1;
			for(int i=2;i<=n;i++){
				if(a[i]>a[1])res++;
			}
			ans=min(ans,res);
			return ;
		}
		for(int i=1;i<=3;i++){
			if(i==1){
				a[res[x].first]+=3;
			}else if(i==2){
				a[res[x].first]+=1;
				a[res[x].second]+=1;
			}else{
				a[res[x].second]+=3;
			}
			self(self,x+1);
			if(i==1){
				a[res[x].first]-=3;
			}else if(i==2){
				a[res[x].first]-=1;
				a[res[x].second]-=1;
			}else{
				a[res[x].second]-=3;
			}
		}
	};
	dfs(dfs,1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}