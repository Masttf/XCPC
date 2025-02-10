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
	int n,m,p;cin>>n>>m>>p;
	vector<int>ps(n+1);
	vector g(8*n+2*m+1,vector<pair<int,int>>());
	int pdx=4*n;
	auto bulid = [&](auto self,int l,int r,int p)->void{
		//dbg(l,r,p);
		if(p!=1)g[p+pdx].push_back({p/2+pdx,0});
		if(l==r){
			ps[l]=p;
			g[p+pdx].push_back({p,0});
			g[p].push_back({p+pdx,0});
			return ;
		}
		int mid=(l+r)>>1;
		g[p].push_back({p<<1,0});
		g[p].push_back({p<<1|1,0});
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};
	bulid(bulid,1,n,1);

	auto link = [&](auto self,int l,int r,int x,int y,int k,int t,int p)->void{
		if(x<=l&&r<=y){
			if(t==1){//双向边的建立,因为一定是出树连到入树,所以正反边就需要两个节点
				g[k].push_back({p,1});
				g[p+pdx].push_back({k+1,1});
			}else{
				g[k+1].push_back({p,1});
				g[p+pdx].push_back({k,1});
			}
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,k,t,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,k,t,p<<1|1);
	};
	for(int i=1;i<=m;i++){
		int a,b,c,d;cin>>a>>b>>c>>d;
		link(link,1,n,a,b,2*i-1+2*pdx,1,1);
		link(link,1,n,c,d,2*i-1+2*pdx,2,1);
	}
	vector<int>d(8*n+2*m+1,INT_MAX);
	auto dijkstra = [&]()->void{
		vector<int>vis(8*n+2*m+1);
		p=ps[p]+pdx;
		//dbg(p);
		d[p]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		q.push({0,p});
		while(!q.empty()){
			int u=q.top().second;
			//dbg(u,d[u]);
			q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(auto [v,w]:g[u]){
				if(d[v]>d[u]+w){
					d[v]=d[u]+w;
					q.push({d[v],v});
				}
			}
		}
	};
	dijkstra();
	for(int i=1;i<=n;i++){
		cout<<d[ps[i]+pdx]/2<<'\n';
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