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
	int mi,val,tag;
};
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	vector<int>pp;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		pp.push_back(a[i].first);
		pp.push_back(a[i].second);
	}
	pp.push_back(-1);
	pp.push_back(Max);
	sort(a.begin()+1,a.end());
	int ans=0;
	int l=-1,r=-1;
	for(int i=1;i<=n;i++){
		auto [ll,rr]=a[i];
		if(ll<=r){
			r=max(r,rr);
		}else{
			ans+=r-l;
			l=ll;
			r=rr;
		}
	}
	ans+=r-l;
	sort(pp.begin(),pp.end());
	pp.erase(unique(pp.begin(),pp.end()),pp.end());
	auto get = [&](int x)->int{
		return lower_bound(pp.begin(),pp.end(),x)-pp.begin();
	};
	int N=pp.size()-1;
	vector<node>tr(N*4);
	auto up = [&](node x,node y)->node{
		node res={0,0,0};
		res.mi=min(x.mi,y.mi);
		if(x.mi==res.mi)res.val+=x.val;
		if(y.mi==res.mi)res.val+=y.val;
		return res;
	};
	auto cg = [&](node &x,int val)->void{
		x.mi+=val;
		x.tag+=val;
	};
	auto down = [&](int p)->void{
		if(tr[p].tag){
			cg(tr[p<<1],tr[p].tag);
			cg(tr[p<<1|1],tr[p].tag);
			tr[p].tag=0;
		}
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].mi=0;
			tr[p].val=pp[l]-pp[l-1];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int p)->void{
		if(x<=l&&r<=y){
			cg(tr[p],1);
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		if(x<=l&&r<=y)return tr[p];
		down(p);
		node res={Max,Max,0};
		int mid=(l+r)>>1;
		if(x<=mid)res=up(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=up(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	bulid(bulid,1,N,1);
	for(int i=1;i<=n;i++){
		auto [ll,rr]=a[i];
		ll=get(ll)+1;
		rr=get(rr);
		updata(updata,1,N,ll,rr,1);
	}
	int res=0;
	for(int i=1;i<=n;i++){
		auto [ll,rr]=a[i];
		ll=get(ll)+1;
		rr=get(rr);
		node rs = query(query,1,N,ll,rr,1);
		//dbg(ll,rr,rs.mi,rs.val);
		if(rs.mi==1)res=max(res,ans-rs.val);
		else res=max(res,ans);
	}
	cout<<res<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}