#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
	int l,r,cnt,sum;
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
	int m,n;cin>>m>>n;
	vector<int>p(m);
	vector<pair<pair<int,int>,int>>a(m+1);
	for(int i=1;i<=m;i++){
		int l,r,x;cin>>l>>r>>x;
		a[i]={{l,r},x};
		p[i-1]=x;
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	
	vector g(n+2,vector<pair<int,int>>());
	for(int i=1;i<=m;i++){
		int l=a[i].first.first;
		int r=a[i].first.second;
		int x=a[i].second;
		g[l].push_back({x,1});
		g[r+1].push_back({x,-1});
	}
	m=p.size();

	vector<node>tr(n*40);
	vector<int>root(n+1);
	int tot=0;
	int last=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
		if(u<=last){
			u=++tot;
			tr[u]=tr[v];
		}
		tr[u].cnt+=val>=0?1:-1;
		tr[u].sum+=val;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
	};
	auto query = [&](auto self,int u,int l,int r,int k)->int{
		if(l==r)return k*(tr[u].sum/tr[u].cnt);
		int d=tr[tr[u].l].cnt;
		int mid=(l+r)>>1;
		if(k>d)return self(self,tr[u].r,mid+1,r,k-d)+tr[tr[u].l].sum;
		else return self(self,tr[u].l,l,mid,k);
	};
	for(int i=1;i<=n;i++){
		root[i]=root[i-1];
		last=tot;
		for(auto [x,y]:g[i]){
			updata(updata,root[i],root[i-1],1,m,get(x),y*x);
		}
	}
	int pre=1;
	for(int i=1;i<=n;i++){
		int p,x,y,z;cin>>p>>x>>y>>z;
		int k=1+(1ll*x*pre+y)%z;
		if(tr[root[p]].cnt<=k){
			pre=tr[root[p]].sum;
		}else pre=query(query,root[p],1,m,k);
		cout<<pre<<'\n';
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