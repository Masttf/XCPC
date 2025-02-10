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
	int l,r,val;
};
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>tr(n<<5);
	vector<int>root(m+1);
	int tot=0;
	auto bulid = [&](auto self,int &u,int l,int r)->void{
		u=++tot;
		if(l==r){
			tr[u].val=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,tr[u].l,l,mid);
		self(self,tr[u].r,mid+1,r);
		return ;
	};

	auto updata = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
		u=++tot;
		tr[u]=tr[v];
		if(l==r){
			tr[u].val=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
		return ;
	};

	auto query = [&](auto self,int u,int l,int r,int x)->int{
		if(l==r)return  tr[u].val;
		int mid=(l+r)>>1;
		if(x<=mid)return self(self,tr[u].l,l,mid,x);
		else return self(self,tr[u].r,mid+1,r,x);
	};

	bulid(bulid,root[0],1,n);

	for(int i=1;i<=m;i++){
		int v,t,x;cin>>v>>t>>x;
		if(t==1){
			int val;cin>>val;
			updata(updata,root[i],root[v],1,n,x,val);
		}else{
			cout<<query(query,root[v],1,n,x)<<'\n';
			root[i]=root[v];
		}
		//dbg(i,"yes");
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