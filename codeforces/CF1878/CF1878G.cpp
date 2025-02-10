#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>ct(n+1);
	for(int i=1;i<=n;i++)cin>>ct[i];
	vector<vector<int>>g(n+1,vector<int>());
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<vector<int>>f(25,vector<int>(n+1));
	vector<vector<int>>dis(32,vector<int>(n+1));
	vector<vector<int>>val(25,vector<int>(n+1));
	vector<int>dep(n+1);
	auto dfs = [&](auto dfs,int u,int father)->void{
		f[0][u]=father;
		val[0][u]=ct[father];
		dep[u]=dep[father]+1;
		for(int i=1;(1ll<<i)<dep[u];i++){
			f[i][u]=f[i-1][f[i-1][u]];
			val[i][u]=val[i-1][u]|val[i-1][f[i-1][u]];
		}
		for(int i=0;i<=30;i++){
			dis[i][u]=dis[i][father];
			if((ct[u]>>i)&1)dis[i][u]=u;
		}
		for(auto v:g[u]){
			if(v==father)continue;
			dfs(dfs,v,u);
		}
		return ;
	};
	dfs(dfs,1,0);
	
	auto lca = [&](int a,int b)->int{
		if(dep[a]<dep[b])swap(a,b);
		for(int i=20;i>=0;i--){
			if(dep[a]-(1ll<<i)>=dep[b])a=f[i][a];
		}
		if(a==b)return a;
		for(int i=20;i>=0;i--){
			if(f[i][a]!=f[i][b]){
				a=f[i][a];
				b=f[i][b];
			}
		}
		return f[0][a];
	};
	
	auto get = [&](int a,int b)->int{
		int len=dep[a]-dep[b];
		int res=ct[a];
		while(len){
			int temp=lowbit(len);
			len-=lowbit(len);
			int d=__lg(temp);
			res|=val[d][a];
			a=f[d][a];
		}
		return res;
	};
	
	auto cnt = [&](int x)->int{
		int res=0;
		for(int i=0;i<=30;i++){
			if((x>>i)&1){
				res++;
			}
		}
		return res;
	};
	//cout<<"YES"<<endl;
	int q;cin>>q;
	vector<int>temp;
	while(q--){
		int a,b;cin>>a>>b;
		int ans=0;
		int p=lca(a,b);
		for(int i=0;i<=30;i++){
			int u=dis[i][a];
			if(dep[u]<dep[p])continue;
			int res1=get(a,u);
			int res2=get(u,p)|get(b,p);
			ans=max(ans,cnt(res1)+cnt(res2));
			//cout<<"a YES"<<endl;
		}
		
		for(int i=0;i<=30;i++){
			int u=dis[i][b];
			if(dep[u]<dep[p])continue;
			int res1=get(b,u);
			int res2=get(u,p)|get(a,p);
			ans=max(ans,cnt(res1)+cnt(res2));
			//cout<<"b YES"<<endl;
		}
		temp.push_back(ans);
		//cout<<q<<"YES"<<endl;
	}
	for(auto x:temp)cout<<x<<" ";
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
