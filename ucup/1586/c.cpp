#include<bits/stdc++.h>
//#define int long long
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
constexpr int Max=1e9;
void solve(){
	int n;cin>>n;
	vector<int>c(n+1);
	{
		vector<int>a(5*n+1);
		for(int i=1;i<=2*n;i++)cin>>a[i];
		vector<int>tr(4*n);
		auto bulid = [&](auto self,int l,int r,int p)->void{
			if(l==r){
				tr[p]=1;
				return ;
			}
			int mid=(l+r)>>1;
			self(self,l,mid,p<<1);
			self(self,mid+1,r,p<<1|1);
			tr[p]=tr[p<<1]+tr[p<<1|1];
			return ;
		};
		auto updata = [&](auto self,int l,int r,int x,int val,int p)->void{
			if(l==r){
				tr[p]=0;
				return ;
			}
			int mid=(l+r)>>1;
			if(x<=mid)self(self,l,mid,x,val,p<<1);
			else self(self,mid+1,r,x,val,p<<1|1);
			tr[p]=tr[p<<1]+tr[p<<1|1];
		};
		auto query = [&](auto self,int l,int r,int k,int p)->int{
			if(l==r){
				return l;
			}
			int mid=(l+r)>>1;
			int num=tr[p<<1];
			if(num>=k)return self(self,l,mid,k,p<<1);
			else return self(self,mid+1,r,k-num,p<<1|1);
		};
		bulid(bulid,1,n,1);
		for(int i=2*n;i>=1;i-=2){
			int p=a[i-1];
			int h=a[i];
			int ps=query(query,1,n,p,1);
			c[ps]=h;
			updata(updata,1,n,ps,0,1);
		}
	}
	vector<pair<int,int>>tr(5*n);
	auto up = [&](pair<int,int> x,pair<int,int> y)->pair<int,int>{
		pair<int,int>res;
		if(x.first<y.first){
			res=x;
		}else if(y.first<x.first){
			res=y;
		}else{
			res.first=x.first;
			res.second=max(x.second,y.second);
		}
		return res;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p]={c[l],l};
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
		return ;
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->pair<int,int>{
		if(x<=l&&r<=y){
			return tr[p];
		}
		int mid=(l+r)>>1;
		pair<int,int> res={Max,Max};
		if(x<=mid)res=self(self,l,mid,x,y,p<<1);
		if(y>mid) res=up(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	bulid(bulid,1,n,1);
	vector<int>f(n+1);
	auto Set = [&](int x)->void{
		while(x<=n){
			f[x]++;
			x+=lowbit(x);
		}
		return ;
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=f[x];
			x-=lowbit(x);
		}
		return res;
	};
	auto dfs = [&](auto self, int l, int r)->void{
		if(l > r) return ;
		int p = query(query,1,n,l,r,1).second;
		//dbg(l,r,p);
		Set(p);
		std::cout << ask(p-1) + 1 << ' ' << c[p] << '\n';
		if(p != l) self(self, l, p - 1);
		if(p != r) self(self, p + 1, r);
	};
	dfs(dfs, 1, n);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}