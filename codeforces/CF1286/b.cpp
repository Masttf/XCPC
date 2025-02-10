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
void solve(){//子树区间内的第ci+1大
	int n;cin>>n;
	vector<vector<int>>g(n+1);
	vector<int>c(n+1);
	int root=0;
	for(int i=1;i<=n;i++){
		int v;cin>>v>>c[i];
		if(v==0)root=i;
		else g[v].push_back(i);
		
	}
	vector<int>in(n+1);
	vector<int>out(n+1);
	vector<int>ans(n+1),sz(n+1);
	int dfn=0;
	//我们考虑一下,把每个子树里面点的值都构造成0到sz-1, 
	//假设儿子已经构建好,考虑如何构造当前的结点
	//首先因为儿子都0到sz-1,且不同子树是互不影响的
	//所以我们对它们做一个偏移
	//然后插入当前根结点就行,把>=它的都加1就是符合答案了
	auto dfs = [&](auto self,int now)->void{
		in[now]=++dfn;
		for(auto v:g[now]){
			self(self,v);
			for(int i=in[v];i<=out[v];i++){
				ans[i]+=sz[now];
			}
			sz[now]+=sz[v];
		}
		sz[now]++;
		if(c[now]>=sz[now]){
			cout<<"NO\n";
			exit(0);
		}
		ans[in[now]]=c[now];
		out[now]=dfn;
		for(int i=in[now]+1;i<=out[now];i++){
			if(ans[i]>=c[now])ans[i]++;
		}
		return ;
	};
	dfs(dfs,root);
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<ans[in[i]]+1<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}