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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	vector<node>tr(n*40);
	vector<int>root(n+1);
	int tot=0;
	auto bulid = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].sum++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};

	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		if(l==r){
			if((tr[u].sum-tr[v].sum)>k)return l;
			else return 0;
		}
		int mid=(l+r)>>1;
		int sum=tr[tr[u].l].sum-tr[tr[v].l].sum;
		if(sum>k)return self(self,tr[u].l,tr[v].l,l,mid,k);
		else return self(self,tr[u].r,tr[v].r,mid+1,r,k);
	};

	for(int i=1;i<=n;i++)bulid(bulid,root[i],root[i-1],1,n,a[i]);
	for(int i=1;i<=m;i++){
		int l,r;cin>>l>>r;
		cout<<query(query,root[r],root[l-1],1,n,(r-l+1)/2)<<'\n';
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