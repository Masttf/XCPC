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
void solve(){
	int n,q,s;cin>>n>>q>>s;
	int pdx=4*n;
	vector g(8*n,vector<pair<int,int>>());
	vector<int>ps(n+1);
	auto bulid = [&](auto self,int l,int r,int p)->void{
		dbg(l,r,p);
		if(p!=1){
			g[p+pdx].push_back({p/2+pdx,0});
		}
		if(l==r){
			ps[l]=p;
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

	auto updata = [&](auto self,int l,int r,int x,int y,int k,int w,int ty,int p)->void{
		if(x<=l&&r<=y){
			if(ty==2)g[p].push_back({k,w});
			else g[p+pdx].push_back({k,w});
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,k,w,ty,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,k,w,ty,p<<1|1);
	};

	vector<int>d(8*n,INT_MAX);
	auto dijkstra = [&]()->void{
		d[s]=0;
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		vector<int>vis(8*n);
		q.push({0,s});
		while(!q.empty()){
			int u=q.top().second;
			q.pop();
			dbg(u);
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

	s=ps[s];
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int u,v,w;cin>>u>>v>>w;
			updata(updata,1,n,v,v,ps[u],w,2,1);
		}else if(t==2){
			int v,l,r,w;cin>>v>>l>>r>>w;
			updata(updata,1,n,l,r,ps[v],w,t,1);
		}else{
			int v,l,r,w;cin>>v>>l>>r>>w;
			updata(updata,1,n,l,r,ps[v]+pdx,w,t,1);
		}
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		if(d[ps[i]]==INT_MAX)d[ps[i]]=-1;
		cout<<d[ps[i]]<<" \n"[i==n];
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}
/*
u -> 4  1
u -> 16 1
u -> 14 
u -> 13 
u -> 15 
*/