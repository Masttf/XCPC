#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
	int l,r,cnt;
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
	int mx=1000000;
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>root(n+1);
	vector<node>tr(n*40);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].cnt++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};
	auto query = [&](auto self,int u,int v,int l,int r,int x,int y)->int{
		if(x<=l&&r<=y)return tr[u].cnt-tr[v].cnt;
		int res=0;
		int mid=(l+r)>>1;
		if(x<=mid)res+=self(self,tr[u].l,tr[v].l,l,mid,x,y);
		if(y>mid)res+=self(self,tr[u].r,tr[v].r,mid+1,r,x,y);
		return res;
	};
	for(int i=1;i<=n;i++)updata(updata,root[i],root[i-1],0,mx,a[i]);
	for(int j=1;j<=m;j++){
		int b,x,l,r;cin>>b>>x>>l>>r;
		int ans=0;
		for(int i=19;i>=0;i--){
			int now=ans+((1^((b>>i)&1))<<i);
			//dbg(j,now);
			if(query(query,root[r],root[l-1],0,mx,now-x,now+(1<<i)-1-x))ans=now;
			else ans+=((b>>i)&1)<<i;
		}
		ans^=b;
		cout<<ans<<'\n';
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