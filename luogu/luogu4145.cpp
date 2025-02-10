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
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
struct node{
	int l,r,val;
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>t((n<<2)+1);
	auto up =[&](int p)->void{
		t[p].val=t[p<<1].val+t[p<<1|1].val;
	};

	auto bulid =[&](auto self,int l,int r,int p)->void{
		t[p].l=l;
		t[p].r=r;
		if(l==r){
			t[p].val=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
	};
	bulid(bulid,1,n,1);

	auto updata = [&](auto self,int l,int r,int p)->void{
		if(t[p].l==t[p].r){
			t[p].val=sqrt(t[p].val);
			return ;
		}
		int mid=(t[p].l+t[p].r)>>1;
		if(l<=mid&&t[p<<1].val!=t[p<<1].r-t[p<<1].l+1)self(self,l,r,p<<1);
		if(r>mid&&t[p<<1|1].val!=t[p<<1|1].r-t[p<<1|1].l+1)self(self,l,r,p<<1|1);
		up(p);
	};

	auto query = [&](auto self,int l,int r,int p)->int{
		if(l<=t[p].l&&t[p].r<=r){
			return t[p].val;
		}
		int mid=(t[p].l+t[p].r)>>1;
		int res=0;
		if(l<=mid)res+=self(self,l,r,p<<1);
		if(r>mid)res+=self(self,l,r,p<<1|1);
		return res;
	};
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int t,l,r;cin>>t>>l>>r;
		if(l>r)swap(l,r);
		if(t==0)updata(updata,l,r,1);
		else cout<<query(query,l,r,1)<<'\n';
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