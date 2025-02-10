#include<bits/stdc++.h>
//#define int long long
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
	int l,r,mi;
};
void solve(){
	int n;cin>>n;
	//dbg(n);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>root(n+1);
	vector<node>tr(n*40);
	int tot=0;
	auto bulid = [&](auto self,int &u,int l,int r)->void{
		u=++tot;
		if(l==r){
			tr[u].mi=INT_MAX;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,tr[u].l,l,mid);
		self(self,tr[u].r,mid+1,r);
		tr[u].mi=min(tr[tr[u].l].mi,tr[tr[u].r].mi);
	};
	bulid(bulid,root[0],1,n);
	auto updata = [&](auto self,int &u,int v,int l,int r,int x,int k)->void{
		u=++tot;
		tr[u]=tr[v];
		//dbg(l,r);
		if(l==r){
			tr[u].mi=k;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,k);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x,k);
		tr[u].mi=min(tr[tr[u].l].mi,tr[tr[u].r].mi);
	};
	for(int i=1;i<=n;i++){
		//dbg(i);
		updata(updata,root[i],root[i-1],1,n,a[i],i);
	}
	int ans=0;
	int nw=n;
	while(nw){
		nw=tr[root[nw]].mi-1;
		//dbg(nw);
		ans++;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}