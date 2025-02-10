#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int val,tag=-1,mx,mi;
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
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>res(2*n+1),vis(n+1);
	for(int i=n+1;i<=2*n;i++)a[i]=a[i-n],res[i]=-1;
	int now=0;
	for(int i=1;i<=n;i++){
		vis[a[i]]=1;
		while(vis[now])now++;
		res[i]=now;
	}
	vector<node>tr(n*8);
	auto cg = [&](int p,int l,int r,int k)->void{
		tr[p].val=(r-l+1)*k;
		tr[p].mi=k;
		tr[p].mx=k;
		tr[p].tag=k;
	};
	auto down = [&](int p,int l,int r)->void{
		if(tr[p].tag==-1)return ;
		int mid=(l+r)>>1;
		cg(p<<1,l,mid,tr[p].tag);
		cg(p<<1|1,mid+1,r,tr[p].tag);
		tr[p].tag=-1;
	};
	auto up = [&](int p)->void{
		tr[p].val=tr[p<<1].val+tr[p<<1|1].val;
		tr[p].mx=max(tr[p<<1].mx,tr[p<<1|1].mx);
		tr[p].mi=min(tr[p<<1].mi,tr[p<<1|1].mi);
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].val=res[l]>0?res[l]:0;
			tr[p].mx=res[l];
			tr[p].mi=res[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
	};

	auto updata1 = [&](auto self,int l,int r,int x,int k,int p)->void{
		if(l==r){
			tr[p].val=k;
			tr[p].mx=k;
			tr[p].mi=k;
			return ;
		}
		down(p,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,k,p<<1);
		else self(self,mid+1,r,x,k,p<<1|1);
		up(p);
	};
	auto updata2 = [&](auto self,int l,int r,int x,int y,int k,int p)->void{
		if(x<=l&&r<=y&&tr[p].mi>=k){
			cg(p,l,r,k);
			return ;
		}
		down(p,l,r);
		int mid=(l+r)>>1;
		if(x<=mid&&tr[p<<1].mx>=k)self(self,l,mid,x,y,k,p<<1);
		if(y>mid&&tr[p<<1|1].mx>=k)self(self,mid+1,r,x,y,k,p<<1|1);
		up(p);
	};
	bulid(bulid,1,2*n,1);
	int ans=tr[1].val;
	for(int i=n+1;i<=2*n;i++){
		updata2(updata2,1,2*n,i-n,i-1,a[i],1);
		updata1(updata1,1,2*n,i,n,1);
		ans=max(ans,tr[1].val);
	}
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