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
	int sum,mx,tag;
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
	vector<int>t(n+1);
	vector<int>vis(n+1);
	int cnt=0;
	vector lk(n+1,vector<int>());
	int ans=0;
	auto dfs1 = [&](auto self,int now)->void{
		st[now]=++dfn;
		int temp=vis[a[now]];
		if(!vis[a[now]])cnt++;
		vis[a[now]]=now;
		if(temp)lk[temp].push_back(now);
		t[dfn]=cnt;
		ans=max(ans,cnt);
		for(auto v:g[now]){
			self(self,v);
		}
		ed[now]=dfn;
		if(!temp)cnt--;
		vis[a[now]]=temp;
	};
	dfs1(dfs1,1);

	vector<node>tr(n*4);
	auto cg = [&](int p,int val)->void{
		tr[p].sum+=val;
		tr[p].mx+=val;
		tr[p].tag+=val;
	};
	auto up = [&](int p)->void{
		tr[p].sum=tr[p<<1].sum+tr[p<<1|1].sum;
		tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
	};
	auto down = [&](int p)->void{
		cg(p<<1,tr[p].tag);
		cg(p<<1|1,tr[p].tag);
		tr[p].tag=0;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].sum=t[l];
			tr[p].mx=t[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
	};
	bulid(bulid,1,n,1);

	auto updata = [&](auto self,int l,int r,int x,int y,int val,int p)->void{
		if(x<=l&&r<=y){
			cg(p,val);
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,val,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val,p<<1|1);
		up(p);
	};

	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y)return tr[p].mx;
		down(p);
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid)res=max(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		up(p);
		return res;
	};

	auto dfs2 = [&](auto self,int now)->void{
		int mx1=1,mx2=1;
		for(auto v:g[now]){
			int res=query(query,1,n,st[v],ed[v],1);
			if(mx1<res)mx2=mx1,mx1=res;
			else if(mx2<res)mx2=res;
		}
		ans=max(ans,mx1*mx2);
		updata(updata,1,n,st[now],ed[now],-1,1);
		for(auto v:lk[now]){
			updata(updata,1,n,st[v],ed[v],1,1);
		}
		for(auto v:g[now]){
			self(self,v);
		}
		updata(updata,1,n,st[now],ed[now],1,1);
		for(auto v:lk[now]){
			updata(updata,1,n,st[v],ed[v],-1,1);
		}
	};
	dfs2(dfs2,1);
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