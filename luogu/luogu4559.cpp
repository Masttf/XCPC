#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
	int l,r,cnt;
	long long sum;
};
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
//首先按排序好的顺序去占位一定是最优的解法之一
//那么这时候对于这个排序的序列一定有的人往左跑有的人往右跑，且跑的这群人的贡献是可以
//算出来的根据这群人排的贡献，因为他们一定是按顺序一个一个占下去，那么是个等差数列求和
void solve(){
	int n,m;cin>>n>>m;
	int mx=0;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	vector<int>root(n+1);
	vector<node>tr(n*40);
	int tot=0;
	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].cnt++;
		tr[u].sum+=x;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};
	auto query = [&](auto self,int u,int v,int l,int r,int k)->long long{
		int d=tr[u].cnt-tr[v].cnt;
		//if(!d)return 0;
		if(l>=k+d-1){
			return tr[u].sum-tr[v].sum-(1ll*d*(k+k+d-1)/2);
		}
		if(r<=k){
			return 1ll*d*(k+k+d-1)/2-(tr[u].sum-tr[v].sum);
		}
		int mid=(l+r)>>1;
		long long res=0;
		int dd=tr[tr[u].l].cnt-tr[tr[v].l].cnt;
		res+=self(self,tr[u].l,tr[v].l,l,mid,k);
		res+=self(self,tr[u].r,tr[v].r,mid+1,r,k+dd);
		return res;
	};
	for(int i=1;i<=n;i++){
		updata(updata,root[i],root[i-1],1,mx,a[i]);
	}
	for(int i=1;i<=m;i++){
		int l,r,k;cin>>l>>r>>k;
		long long ans=query(query,root[r],root[l-1],1,mx,k);
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