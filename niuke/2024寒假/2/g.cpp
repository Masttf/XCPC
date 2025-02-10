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
const int Max=1e18;
struct node{
	int val,tag;
	int lval,rval;
};
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];

	vector<node>tr(n*4);
	auto cg = [&](int p,int k)->void{
		tr[p].lval+=k;
		tr[p].rval+=k;
		tr[p].val+=k;
		tr[p].tag+=k;
	};
	auto down = [&](int p)->void{
		if(tr[p].tag){
			cg(p<<1,tr[p].tag);
			cg(p<<1|1,tr[p].tag);
			tr[p].tag=0;
		}
	};
	auto up = [&](int p)->void{
		tr[p].val=max({tr[p<<1].val,tr[p<<1|1].val,2*tr[p<<1].rval-tr[p<<1|1].lval});
		tr[p].lval=tr[p<<1].lval;
		tr[p].rval=tr[p<<1|1].rval;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].lval=tr[p].rval=pre[l];
			tr[p].val=-Max;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
		return ;
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int k,int p)->void{
		if(l>=x&&r<=y){
			cg(p,k);
			if(l==r)tr[p].val=-Max;
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,k,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,k,p<<1|1);
		up(p);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		//dbg(l,r);
		if(l>=x&&r<=y){
			return tr[p];
		}
		int mid=(l+r)>>1;
		down(p);
		node res={0,0,-1,-1};
		if(x<=mid){
			res=self(self,l,mid,x,y,p<<1);
		}
		if(y>mid){
			node temp=self(self,mid+1,r,x,y,p<<1|1);
			if(res.lval==-1)res=temp;
			else{
				res.val=max({res.val,temp.val,2*res.rval-temp.lval});
				res.rval=temp.rval;
			}
		}
		up(p);
		return res;
	};
	auto query2 = [&](auto self,int l,int r,int x,int p)->int{
		if(l==r){
			return tr[p].lval;
		}
		down(p);
		int mid=(l+r)>>1;
		int res;
		if(x<=mid)res=self(self,l,mid,x,p<<1);
		else res=self(self,mid+1,r,x,p<<1|1);
		up(p);
		return res;
	};
	bulid(bulid,1,n,1);
	for(int i=1;i<=q;i++){
		int t,x,y;cin>>t>>x>>y;
		if(t==1){
			updata(updata,1,n,x,n,y-a[x],1);
			a[x]=y;
		}else{
			node ans=query(query,1,n,x,y,1);
			int res=ans.val;
			if(x!=1)res-=query2(query2,1,n,x-1,1);
			cout<<res<<'\n';
		}
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