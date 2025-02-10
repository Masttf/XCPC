#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>g(n+1);
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>l(n+1),r(n+1),dep(n+1);
	int idx=0;
	auto dfs =[&](auto dfs,int now,int father)->void{
		l[now]=++idx;
		dep[now]=dep[father]+1;
		//cout<<now<<' ';
		for(auto v:g[now]){
			if(v==father)continue;
			dfs(dfs,v,now);
		}
		r[now]=idx;
		//cout<<now<<' ';
	};
	dfs(dfs,1,0);

	//cout<<endl;
	vector<vector<int>>t(2,vector<int>(idx+1));
	auto updata = [&](int x,int w,int k)->void{
		while(x<=idx){
			t[k][x]+=w;
			x+=lowbit(x);
		}
		return ;
	};
	auto ask = [&](int x,int k)->int{
		int res=0;
		while(x){
			res+=t[k][x];
			x-=lowbit(x);
		}
		return res;
	};

	for(int i=1;i<=m;i++){
		int t;cin>>t;
		if(t==1){
			int x,w;cin>>x>>w;
			if(dep[x]%2==1){
				updata(l[x],w,0);
				updata(l[x],-w,1);
				updata(r[x]+1,-w,0);
				updata(r[x]+1,w,1);
			}else{
				updata(l[x],-w,0);
				updata(l[x],w,1);
				updata(r[x]+1,w,0);
				updata(r[x]+1,-w,1);
			}
		}else{
			int x;cin>>x;
			if(dep[x]%2==1){
				cout<<ask(l[x],0)+a[x]<<'\n';
			}else{
				cout<<ask(l[x],1)+a[x]<<'\n';
			}
		}
		//cout<<i<<' '<<"YES"<<endl;
	}
	return 0;
}