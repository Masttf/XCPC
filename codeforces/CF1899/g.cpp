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
	int n,m;cin>>n>>m;
	vector g(n+1,vector<int>());
	for(int i=1;i<=n-1;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>p(n+1);
	for(int i=1;i<=n;i++)cin>>p[i];
	int dfn=0;
	vector<int>st(n+1);
	vector<int>ed(n+1);
	auto dfs=[&](auto self,int u,int father)->void{
		st[u]=++dfn;
		for(auto v:g[u]){
			if(v==father)continue;
			self(self,v,u);
		}
		ed[u]=dfn;
	};
	dfs(dfs,1,0);

	vector<int>res(n+1);
	for(int i=1;i<=n;i++){
		res[st[i]]=i;
	}

	vector<node>tr(n<<5);
	vector<int>root(n+1);
	int tot=0;
	auto bulid = [&](auto self,int &u,int l,int r)->void{
		u=++tot;
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,tr[u].l,l,mid);
		self(self,tr[u].r,mid+1,r);
		return ;
	};

	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].sum++; 
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};

	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		//dbg(l,r);
		if(l==r)return l;
		int mid=(l+r)>>1;
		int d=tr[tr[u].l].sum-tr[tr[v].l].sum;
		if(d>=k)return self(self,tr[u].l,tr[v].l,l,mid,k);
		else return self(self,tr[u].r,tr[v].r,mid+1,r,k-d);
	};

	bulid(bulid,root[0],1,n);
	for(int i=1;i<=n;i++){
		updata(updata,root[i],root[i-1],1,n,st[p[i]]);
	}
	for(int i=1;i<=m;i++){
		int l,r,x;cin>>l>>r>>x;
		//dbg(i,l,r,x);
		int ll=1,rr=r-l+1;
		int ok=0;
		//dbg(i,ll,rr);
		while(ll<=rr){
			int mid=(ll+rr)>>1;
			//dbg(mid);
			int temp=query(query,root[r],root[l-1],1,n,mid);
			int d=res[temp];
			if(st[d]>=st[x]){
				if(ed[d]<=ed[x]){
					ok=1;
					break;
				}else rr=mid-1;
			}else{
				ll=mid+1;
			}
		}
		//dbg(ll,rr);
		if(ok)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}