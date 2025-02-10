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
constexpr int Max=1e18;
struct node{
	int l1,r1,l2,r2;
};
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>tr(n*4);
	auto cg = [&](int p,int x)->void{
		tr[p]={Max,-Max,Max,-Max};
		if(x==1){
			if(a[x]<=a[x+1]){
				tr[p].l1=-Max;
				tr[p].r1=a[x+1];
			}else{
				tr[p].l1=a[x+1]+1;
				tr[p].r1=Max;
			}
		}else if(x==n){
			if(a[x-1]<=a[x]){
				tr[p].l1=a[x-1];
				tr[p].r1=Max;
			}else{
				tr[p].l1=-Max;
				tr[p].r1=a[x-1]-1;
			}
		}else{
			if(a[x-1]<=a[x]&&a[x]<=a[x+1]){
				tr[p].l1=a[x-1];
				tr[p].r1=a[x+1];
			}else if(a[x-1]<=a[x]&&a[x]>a[x+1]){
				tr[p].l1=max(a[x-1],a[x+1]+1);
				tr[p].r1=Max;
			}else if(a[x-1]>a[x]&&a[x]<=a[x+1]){
				tr[p].l1=-Max;
				tr[p].r1=min(a[x+1],a[x-1]-1);
			}else{
				tr[p].l1=a[x+1]+1;
				tr[p].r1=a[x-1]-1;
			}
		}
	};
	auto up = [&](node x,node y)->node{
		node res={Max,-Max,Max,-Max};
		res.l1=min(x.l1,y.l1);
		res.r1=max(x.r1,y.r1);
		res.l2=min(x.l2,y.l2);
		res.r2=max(x.r2,y.r2);
		return res;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			cg(p,l);
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto updata = [&](auto self,int l,int r,int x,int p)->void{
		if(l==r){
			assert(l==x);
			cg(p,l);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,p<<1);
		else self(self,mid+1,r,x,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int val,int p)->int{
		if(x<=l&&r<=y){
			if(tr[p].l1<=val&&val<=tr[p].r1){
				if(l==r)return l;
			}else if(tr[p].l2<=val&&val<=tr[p].r2){
				if(l==r)return l;
			}else return -1;
		}
		int mid=(l+r)>>1;
		if(x<=mid){
			int res=self(self,l,mid,x,y,val,p<<1);
			if(res!=-1)return res;
		}
		if(y>mid)return self(self,mid+1,r,x,y,val,p<<1|1);
		return -1;
	};
	bulid(bulid,1,n,1);
	//dbg("yes");
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int x,val;cin>>x>>val;
			a[x]=val;
			updata(updata,1,n,x,1);
			if(x>1)updata(updata,1,n,x-1,1);
			if(x<n)updata(updata,1,n,x+1,1);
		}else{
			int l,r,val;cin>>l>>r>>val;
			cout<<query(query,1,n,l,r,val,1)<<'\n';
		}
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