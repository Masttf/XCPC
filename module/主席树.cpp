#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l,r,sum;
};
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++)cin>>a[i],p.push_back(a[i]);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};

	vector<node>tr(n<<5);
	vector<int>root(n+1);
	int tot=0;
	
	auto bulid = [&](auto self,int &u,int l,int r)->void{
		u=++tot;
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,tr[u].l,l,mid);
		self(self,tr[u].r,mid+1,r);
		return ;
	};

	auto updata = [&](auto self,int &u,int v,int l,int r,int x)->void{
		u=++tot;
		tr[u]=tr[v];
		tr[u].sum++;
		if(l==r)return ;
		int mid=(l+r)>>1;
		if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x);
		else self(self,tr[u].r,tr[v].r,mid+1,r,x);
	};

	auto query = [&](auto self,int u,int v,int l,int r,int k)->int{
		if(l==r)return l;
		int mid=(l+r)>>1;
		int d=tr[tr[u].l].sum-tr[tr[v].l].sum;
		if(d>=k)return self(self,tr[u].l,tr[v].l,l,mid,k);
		else return self(self,tr[u].r,tr[v].r,mid+1,r,k-d);
	};

	bulid(bulid,root[0],1,n);
	for(int i=1;i<=n;i++){
		int d=get(a[i]);
		updata(updata,root[i],root[i-1],1,n,d);
	}
	for(int i=1;i<=m;i++){
		int l,r,k;cin>>l>>r>>k;
		int d=query(query,root[r],root[l-1],1,n,k);
		cout<<p[d-1]<<'\n';
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