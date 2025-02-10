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
void solve(){
	int n,d;cin>>n>>d;
	const int maxn=5e5+5;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>tr(maxn*4);
	auto updata = [&](auto self,int l,int r,int x,int k,int p)->void{
		if(l==r){
			tr[p]=k;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,k,p<<1);
		else self(self,mid+1,r,x,k,p<<1|1);
		tr[p]=max(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(l>=x&&r<=y)return tr[p];
		int mid=(l+r)>>1;
		int res=0;
		if(x<=mid)res=max(res,self(self,l,mid,x,y,p<<1));
		if(y>mid) res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	for(int i=1;i<=n;i++){
		int ll=a[i]-d;
		int rr=a[i]+d;
		ll=max(1ll,ll);
		rr=min(rr,maxn-5);
		int mx=query(query,1,maxn-5,ll,rr,1);
		updata(updata,1,maxn-5,a[i],mx+1,1);
	}
	cout<<tr[1]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}