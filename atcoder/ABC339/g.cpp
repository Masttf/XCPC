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
	int l,r,val;
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++)cin>>a[i],p.push_back(a[i]);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	for(int i=1;i<=n;i++){
		a[i]=get(a[i]);
		//dbg(a[i]);
	}
	vector<int>root(n+1);
	vector<node>tr(n*40);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].val+=p[x-1];
		//dbg(l,r,tr[u].val,tr[v].val,u,v);
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};
	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		//dbg(l,r);
		if(l==r)return tr[u].val-tr[v].val;
		int mid=(l+r)>>1;
		if(k<=mid)return self(self,tr[u].l,tr[v].l,l,mid,k);
		else return tr[tr[u].l].val-tr[tr[v].l].val+self(self,tr[u].r,tr[v].r,mid+1,r,k);
	};
	for(int i=1;i<=n;i++){
		updata(updata,root[i],root[i-1],1,n,a[i]);
	}
	int ans=0;
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int l,r,x;cin>>l>>r>>x;
		l^=ans;
		r^=ans;
		x^=ans;
		x=upper_bound(p.begin(),p.end(),x)-p.begin();
		//dbg(l,r,x);
		if(x==0)ans=0;
		else ans=query(query,root[r],root[l-1],1,n,x);
		cout<<ans<<'\n';
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