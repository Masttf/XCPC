#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
struct node{
	int l,r,cnt,sum;
};
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		cin>>a[i].second>>a[i].first;
		p.push_back(a[i].second);
	}
	sort(a.begin()+1,a.end());
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return  lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	vector<node>tr(n*32);
	vector<int>root(n+1);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].sum+=val;
		tr[u].cnt++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
	};
	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		if(l==r)return k*p[l-1];
		int mid=(l+r)>>1;
		int d=tr[tr[u].r].cnt-tr[tr[v].r].cnt;
		if(k<=d)return self(self,tr[u].r,tr[v].r,mid+1,r,k);
		else return self(self,tr[u].l,tr[v].l,l,mid,k-d)+tr[tr[u].r].sum-tr[tr[v].r].sum;
	};
	for(int i=1;i<=n;i++)updata(updata,root[i],root[i-1],1,n,get(a[i].second),a[i].second);
	vector<int>f(n+1,-Max);
	auto cdq = [&](auto self,int l,int r,int k_l,int k_r)->void{
		int mid=(l+r)>>1;
		int p=k_l;
		for(int i=max(k_l,mid);i<=k_r;i++){
			int d=query(query,root[i-1],root[0],1,n,mid-1)+a[i].second-a[i].first;
			if(d>f[mid]){
				f[mid]=d;
				p=i;
			}
		}
		if(l<mid)self(self,l,mid-1,k_l,p);
		if(r>mid)self(self,mid+1,r,p,k_r);
	};
	cdq(cdq,1,n,1,n);
	for(int i=1;i<=n;i++){
		cout<<f[i]<<'\n';
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