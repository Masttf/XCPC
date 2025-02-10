#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int val,tag;
};
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>tr(n*4);
	auto up = [&](node x,node y)->node{
		node res={0,0};
		res.val=x.val+y.val;
		return res;
	};
	auto cg = [&](node &x,int l,int r,int val)->void{
		x.val+=val*(r-l+1);
		x.tag+=val;
	};
	auto down = [&](int p,int l,int r)->void{
		if(tr[p].tag){
			int mid=(l+r)>>1;
			cg(tr[p<<1],l,mid,tr[p].tag);
			cg(tr[p<<1|1],mid+1,r,tr[p].tag);
			tr[p].tag=0;
		}
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].val=a[l];
			tr[p].tag=0;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int val,int p)->void{
		if(x<=l&&r<=y){
			cg(tr[p],l,r,val);
			return ;
		}
		int mid=(l+r)>>1;
		down(p,l,r);
		if(x<=mid)self(self,l,mid,x,y,val,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y)return tr[p].val;
		down(p,l,r);
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid)res+=self(self,l,mid,x,y,p<<1);
		if(y>mid)res+=self(self,mid+1,r,x,y,p<<1|1);
		return res;
	};
	bulid(bulid,1,n,1);
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int x,y,k;cin>>x>>y>>k;
			updata(updata,1,n,x,y,k,1);
		}else if(t==2){
			int k;cin>>k;
			updata(updata,1,n,1,1,k,1);
		}else if(t==3){
			int k;cin>>k;
			updata(updata,1,n,1,1,-k,1);
		}else if(t==4){
			int x,y;cin>>x>>y;
			cout<<query(query,1,n,x,y,1)<<'\n';
		}else{
			cout<<query(query,1,n,1,1,1)<<'\n';
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