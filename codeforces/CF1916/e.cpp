#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
struct node{
	int l,r,sum;
};
void solve(){
	int n;cin>>n;
	vector g(n+1,vector<int>());
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		g[x].push_back(i);
	}
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	
	vector<int>st(n+1),ed(n+1);
	int dfn=0;
	vector color(n+1,vector<int>());
	auto dfs1 = [&](auto self,int now)->void{
		st[now]=++dfn;
		color[a[now]].push_back(dfn);
		for(auto v:g[now]){
			self(self,v);
		}
		ed[now]=dfn;
	};
	dfs1(dfs1,1);

	auto check = [&](int c,int l,int r)->int{
		int p=lower_bound(color[c].begin(),color[c].end(),l)-color[c].begin();
		if(p==color[c].size())return 1;
		if(color[c][p]<=r)return 0;
		else return 1;
	};
	vector<int>val(n+1);
	int ans=1;
	auto dfs = [&](auto self,int now)->void{
		int mx1=1,mx2=1;
		for(auto v:g[now]){
			self(self,v);
			int d=val[v];
			d+=check(a[now],st[v],ed[v]);
			if(mx1<d)mx2=mx1,mx1=d;
			else mx2=max(mx2,d);
		}
		ans=max(ans,mx1*mx2);
		val[now]=mx1;
		dbg(now,val[now]);
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