#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
struct node{
	int l,r;
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
	int n;cin>>n;
	vector<int>x(n+1);
	vector<int>r(n+1);
	for(int i=1;i<=n;i++)cin>>x[i]>>r[i];
	vector<int>ps(n+1);
	vector g(4*n,vector<int>());//可以根据连点是否都是区间来判断要建几个树
	vector<node>tr(4*n);

	auto up = [&](int p)->void{
		tr[p].l=tr[p<<1].l;
		tr[p].r=tr[p<<1|1].r;
	};

	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			ps[l]=p;
			tr[p].l=l;
			tr[p].r=l;
			return ;
		}
		int mid=(l+r)>>1;
		g[p].push_back(p<<1);
		g[p].push_back(p<<1|1);
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
	};
	bulid(bulid,1,n,1);

	auto link = [&](auto self,int l,int r,int x,int y,int k,int p)->void{
		if(x<=l&&r<=y){
			if(k!=p)g[k].push_back(p);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,k,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,k,p<<1|1);
	};

	for(int i=1;i<=n;i++){
		int ll=x[i]-r[i];
		int rr=x[i]+r[i];
		ll=lower_bound(x.begin()+1,x.end(),ll)-x.begin();
		rr=upper_bound(x.begin()+1,x.end(),rr)-x.begin()-1;
		link(link,1,n,ll,rr,ps[i],1);
	}

	vector<int>bl(4*n),dfn(4*n),low(4*n);
	vector<int>lmx(4*n,INT_MAX),rmx(4*n);
	vector<int>stk;
	int tot=0;
	int cnt=0;
	auto tarjan = [&](auto self,int now)->void{
		dfn[now]=low[now]=++tot;
		stk.push_back(now);
		for(auto v:g[now]){
			if(!dfn[v])self(self,v),low[now]=min(low[now],low[v]);
			else if(!bl[v])low[now]=min(low[now],dfn[v]);
		}
		if(dfn[now]==low[now]){
			int y;
			cnt++;
			do{
				y=stk.back();
				stk.pop_back();
				lmx[cnt]=min(lmx[cnt],tr[y].l);
				rmx[cnt]=max(rmx[cnt],tr[y].r);
				bl[y]=cnt;
			}while(y!=now);
		}
	};
	tarjan(tarjan,1);

	vector e(cnt+1,vector<int>());
	vector<int>in(cnt+1);
	auto reb = [&]()->void{
		for(int i=1;i<4*n;i++){
			for(auto x:g[i]){
				int u=bl[i],v=bl[x];
				if(u==v)continue;
				e[v].push_back(u);
				in[u]++;
			}
		}
	};
	reb();

	auto topu = [&]()->void{
		queue<int>q;
		for(int i=1;i<=cnt;i++){
			if(!in[i])q.push(i);
		}
		while(!q.empty()){
			int u=q.front();
			q.pop();
			for(auto v:e[u]){
				in[v]--;
				lmx[v]=min(lmx[v],lmx[u]);
				rmx[v]=max(rmx[v],rmx[u]);
				if(in[v]==0)q.push(v);
			}
		}
	};
	topu();
	
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=i*(rmx[bl[ps[i]]]-lmx[bl[ps[i]]]+1)%mod;
		if(ans>=mod)ans-=mod;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}