#include<bits/stdc++.h>
//#define int long long
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
	int l,r,sum;
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>p(n);
	for(int i=1;i<=n;i++)cin>>a[i],p[i-1]=a[i];
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(p.begin(),p.end(),a[i])-p.begin()+1;
	}
	int tot=0;
	int last=0;
	vector<int>root(n+5);
	vector<node>tr(n*40);
	auto bulid = [&](auto self,int &u,int l,int r)->void{
		u=++tot;
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,tr[u].l,l,mid);
		self(self,tr[u].r,mid+1,r);
	};

	auto updata = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
		if(u<=last){
			u=++tot;
			tr[u]=tr[v];
		}
		tr[u].sum+=val;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
	};

	auto query = [&](auto self,int &u,int l,int r,int x)->int{
		if(x<=l)return tr[u].sum;
		int mid=(l+r)>>1;
		if(x<=mid)return self(self,tr[u].l,l,mid,x)+tr[tr[u].r].sum;
		else return self(self,tr[u].r,mid+1,r,x);
	};

	vector<int>mp(n+1);
	bulid(bulid,root[0],1,n);
	for(int i=1;i<=n;i++){
		last=tot;
		updata(updata,root[i],root[i-1],1,n,i,1);
		if(mp[a[i]]){
			updata(updata,root[i],root[i-1],1,n,mp[a[i]],-1);
		}
		mp[a[i]]=i;
	}
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		cout<<query(query,root[r],1,n,l)<<'\n';
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