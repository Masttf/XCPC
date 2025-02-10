#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
//#define int long long
using namespace std;
struct node{
	int l,r,sum;
};
struct node2{
	int t,l,r,x;
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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++)cin>>a[i],p.push_back(a[i]);
	vector<node2>q(m+1);
	for(int i=1;i<=m;i++){
		char t;cin>>t;
		if(t=='Q'){
			int l,r,x;cin>>l>>r>>x;
			p.push_back(x);
			q[i]={0,l,r,x};
		}else{
			int l,x;cin>>l>>x;
			q[i]={1,l,l,x};
			p.push_back(x);
		}
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};

	int nn=p.size();
	int tot=0;
	vector<node>tr(n*200);
	vector<int>root(n+1);
	auto modify = [&](auto self,int &u,int l,int r,int x,int val)->void{
		if(!u)u=++tot;
		tr[u].sum+=val;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,l,mid,x,val);
		else self(self,tr[u].r,mid+1,r,x,val);
	};

	auto updata = [&](int x,int p,int val)->void{
		while(x<=n){
			modify(modify,root[x],1,nn,p,val);
			x+=lowbit(x);
		}
	};
	auto query = [&](auto self,vector<int>&u,vector<int>&v,int l,int r,int k)->int{
		if(l==r)return l;
		int mid=(l+r)>>1;
		int res=0;
		for(auto x:u)res+=tr[tr[x].l].sum;
		for(auto x:v)res-=tr[tr[x].l].sum;
		if(k<=res){
			for(auto &x:u)x=tr[x].l;
			for(auto &x:v)x=tr[x].l;
			return self(self,u,v,l,mid,k);
		}else{
			k-=res;
			for(auto &x:u)x=tr[x].r;
			for(auto &x:v)x=tr[x].r;
			return self(self,u,v,mid+1,r,k);
		}
	};
	auto ask = [&](int l,int r,int p)->int{
		vector<int>u;
		vector<int>v;
		while(r){
			u.push_back(root[r]);
			r-=lowbit(r);
		}
		l--;
		while(l){
			v.push_back(root[l]);
			l-=lowbit(l);
		}
		return query(query,u,v,1,nn,p);
	};

	for(int i=1;i<=n;i++){
		int x=get(a[i]);
		updata(i,x,1);
	}
	
	for(int i=1;i<=m;i++){
		int t=q[i].t;
		if(!t){
			int l=q[i].l;
			int r=q[i].r;
			int x=q[i].x;
			cout<<p[ask(l,r,x)-1]<<'\n';
		}else{
			int l=q[i].l;
			int x=q[i].x;
			int p=get(a[l]);
			updata(l,p,-1);
			a[l]=x;
			x=get(x);
			updata(l,x,1);
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}