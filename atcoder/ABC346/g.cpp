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
struct node{
	int cnt,tag,mi;
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>tr(n*4);
	auto cg = [&](node &x,int val)->void{
		x.mi+=val;
		x.tag+=val;
	};
	auto up = [&](node x,node y)->node{
		node res={0,0,0};
		if(x.mi>y.mi)swap(x,y);
		res.mi=x.mi;
		res.cnt=x.cnt;
		if(x.mi==y.mi)res.cnt+=y.cnt;
		return res;
	};
	auto down = [&](int p)->void{
		if(!tr[p].tag)return ;
		cg(tr[p<<1],tr[p].tag);
		cg(tr[p<<1|1],tr[p].tag);
		tr[p].tag=0;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].mi=0;
			tr[p].cnt=1;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int val,int p)->void{
		if(x<=l&&r<=y){
			cg(tr[p],val);
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,val,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
		return ;
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		if(x<=l&&r<=y)return tr[p];
		int mid=(l+r)>>1;
		down(p);
		node res={0,0,0};
		if(x<=mid)res=self(self,l,mid,x,y,p<<1);
		if(y>mid){
			node temp=self(self,mid+1,r,x,y,p<<1|1);
			if(res.cnt==0)res=temp;
			else res=up(res,temp);
		}
		return res;
	};
	bulid(bulid,1,n,1);
	vector<int>last1(n+1,n+1),last2(n+1,n+1);
	long long ans=0;
	for(int i=n;i>=1;i--){
		updata(updata,1,n,i,last1[a[i]]-1,1,1);
		if(last1[a[i]]!=n+1)updata(updata,1,n,last1[a[i]],last2[a[i]]-1,-1,1);
		node res=query(query,1,n,i,n,1);
		if(res.mi==0)ans+=n-i+1-res.cnt;
		else ans+=n-i+1;
		last2[a[i]]=last1[a[i]];
		last1[a[i]]=i;
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