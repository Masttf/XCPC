#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
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
	vector<int>a(2*n+1);
	for(int i=1;i<=2*n;i++)cin>>a[i];
	vector<int>ll(n+1),rr(n+1);
	for(int i=1;i<=2*n;i++){
		if(!ll[a[i]])ll[a[i]]=i;
		rr[a[i]]=i;
	}
	vector<int>ps(n+1);
	vector g(8*n,vector<int>());

	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			ps[a[l]]=p;
			return ;
		}
		int mid=(l+r)>>1;
		g[p].push_back(p<<1);
		g[p].push_back(p<<1|1);
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};
	bulid(bulid,1,2*n,1);

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
		int l=ll[i]+1,r=rr[i]-1;
		if(l>r)continue;
		link(link,1,2*n,l,r,ps[i],1);
	}

	vector<int>bl(8*n),dfn(8*n),low(8*n);
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
				bl[y]=cnt;
			}while(y!=now);
		}
	};
	tarjan(tarjan,1);

	vector<int>in(cnt+1);
	auto reb = [&]()->void{
		for(int i=1;i<4*n;i++){
			for(auto x:g[i]){
				int u=bl[i],v=bl[x];
				if(u==v)continue;
				in[v]++;
			}
		}
	};
	reb();
	vector<int>sz(cnt+1);
	for(int i=1;i<=n;i++){
		sz[bl[ps[i]]]++;
	}
	int ans=0;
	int res=1;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			ans++;
			res=res*sz[i]*2%mod;
		}
	}
	cout<<ans<<' '<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}