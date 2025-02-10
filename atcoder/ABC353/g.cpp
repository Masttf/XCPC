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
constexpr int Max=1e18;
struct node{
	int mx1,mx2;
};
void solve(){
	int n,c;cin>>n>>c;
	int m;cin>>m;
	vector<pair<int,int>>a(m+1);
	a[0].first=1;
	for(int i=1;i<=m;i++)cin>>a[i].first>>a[i].second;
	vector<node>tr(4*n);
	auto up = [&](node x,node y)->node{
		node res={-Max,-Max};
		res.mx1=max(x.mx1,y.mx1);
		res.mx2=max(x.mx2,y.mx2);
		return res;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].mx1=tr[p].mx2=-Max;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto updata = [&](auto self,int l,int r,int x,int val,int p)->void{
		if(l==r){
			tr[p].mx1=val-c*l;
			tr[p].mx2=val+c*l;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,val,p<<1);
		else self(self,mid+1,r,x,val,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		if(x<=l&&r<=y)return tr[p];
		node res={-Max,-Max};
		int mid=(l+r)>>1;
		if(x<=mid)res=up(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=up(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	bulid(bulid,1,n,1);
	updata(updata,1,n,1,0,1);
	vector dp(2,vector<int>(m+1));
	for(int i=1;i<=m;i++){
		dp[0][i]=max(dp[1][i-1],dp[0][i-1]);
		dp[1][i]=a[i].second-abs(a[i].first-1)*c;
		int mx1=query(query,1,n,1,a[i].first,1).mx2-c*a[i].first;
		int mx2=query(query,1,n,a[i].first,n,1).mx1+c*a[i].first;
		dp[1][i]=max(dp[1][i],max(mx1,mx2)+a[i].second);
		updata(updata,1,n,a[i].first,dp[1][i],1);
	}
	cout<<max(dp[0][m],dp[1][m])<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}