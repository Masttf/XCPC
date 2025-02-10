#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
	int l,r,cnt;
};
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
void solve(){
	int n,m,t;cin>>n>>m>>t;
	vector<int>a(n+1);
	vector<int>p(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i-1]=a[i];
	}

	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	for(int i=1;i<=n;i++)a[i]=get(a[i]);

	vector<vector<int>>g(n+1);
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	vector<int>root(n+1);
	vector<node>tr(n*200);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].cnt++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};
	auto query = [&](auto self,int u1,int v1,int u2,int v2,int l,int r,int k)->int{
		if(l==r)return l;
		int d=tr[tr[u1].l].cnt-tr[tr[v1].l].cnt+tr[tr[u2].l].cnt-tr[tr[v2].l].cnt;
		int mid=(l+r)>>1;
		if(k<=d)return self(self,tr[u1].l,tr[v1].l,tr[u2].l,tr[v2].l,l,mid,k);
		else return self(self,tr[u1].r,tr[v1].r,tr[u2].r,tr[v2].r,mid+1,r,k-d);
	};

	vector<int>pt(n+1);
	vector<int>sz(n+1);
	vector<int>dep(n+1);
	vector<vector<int>>f(25,vector<int>(n+1));
	auto dfs = [&](auto self,int now,int father)->void{
		//dbg(now,father);
		if(father==0)pt[now]=now;
		else pt[now]=pt[father];
		dep[now]=dep[father]+1;
		f[0][now]=father;
		sz[now]=1;
		updata(updata,root[now],root[father],1,n,a[now]);
		for(int i=1;i<=20;i++){
			f[i][now]=f[i-1][f[i-1][now]];
		}
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			sz[now]+=sz[v];
		}
		return ;
	};
	
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

	for(int i=1;i<=n;i++){
		if(!dep[i])dfs(dfs,i,0);
	}
	
	int ans=0;
	for(int _=1;_<=t;_++){
		char ty;cin>>ty;
		if(ty=='Q'){
			int x,y,k;cin>>x>>y>>k;
			x^=ans;
			y^=ans;
			k^=ans;
			if(dep[x]<dep[y])swap(x,y);
			int f1=lca(x,y);
			if(f1==y){
				ans=p[query(query,root[x],root[f[0][y]],0,0,1,n,k)-1];
			}else{
				ans=p[query(query,root[x],root[f1],root[y],root[f[0][f1]],1,n,k)-1];
			}
			cout<<ans<<'\n';
		}else{
			int x,y;cin>>x>>y;
			x^=ans;
			y^=ans;
			g[x].push_back(y);
			g[y].push_back(x);
			if(sz[pt[x]]>sz[pt[y]])swap(x,y);
			sz[pt[y]]+=sz[pt[x]];
			dfs(dfs,x,y);

		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	int k;cin>>k;
	while(t--)solve();
	return 0;
}