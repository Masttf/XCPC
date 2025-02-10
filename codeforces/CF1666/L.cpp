#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,m,s;cin>>n>>m>>s;
	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
	}
	vector<int>pre(n+1);
	vector<int>vis(n+1);
	auto get = [&](int r1,int r2)->void{
		cout<<"Possible\n";
		vector<int>ans1,ans2;
		ans1.push_back(r2);
		while(r1!=s){
			ans1.push_back(r1);
			r1=pre[r1];
		}
		ans1.push_back(s);
		reverse(ans1.begin(),ans1.end());
		while(r2!=s){
			ans2.push_back(r2);
			r2=pre[r2];
		}
		ans2.push_back(s);
		reverse(ans2.begin(),ans2.end());
		cout<<ans1.size()<<'\n';
		for(auto x:ans1)cout<<x<<' ';
		cout<<'\n';
		cout<<ans2.size()<<'\n';
		for(auto x:ans2)cout<<x<<' ';
		exit(0);
	};
	auto dfs= [&](auto self,int now,int begin)->void{
		for(auto v:g[now]){
			if(v==s)continue;
			if(vis[v]&&vis[v]!=begin){
				get(now,v);
			}else if(!vis[v]){
				pre[v]=now;
				vis[v]=begin;
				self(self,v,begin);
			}
		}
	};
	for(auto v:g[s]){
		if(vis[v]){
			get(s,v);
		}
		pre[v]=s;
		vis[v]=v;
		dfs(dfs,v,v);
	}
	cout<<"Impossible\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;//cin>>t;
	while(t--)solve();
	return 0;
}