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
const int mod=998244353;
struct node{
	int val,tag1=1,tag2; 
};
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>tr(n*4);
	auto down = [&](int p)->void{
		tr[p<<1].val=(tr[p<<1].val*tr[p].tag1%mod+tr[p].tag2)%mod;
		tr[p<<1].tag1=tr[p<<1].tag1*tr[p].tag1%mod;
		tr[p<<1].tag2=(tr[p<<1].tag2+tr[p].tag2)%mod;
		tr[p<<1|1].val=(tr[p<<1|1].val*tr[p].tag1%mod+tr[p].tag2)%mod;
		tr[p<<1|1].tag1=tr[p<<1|1].tag1*tr[p].tag1%mod;
		tr[p<<1|1].tag2=(tr[p<<1|1].tag2+tr[p].tag2)%mod;
		tr[p].tag1=1;
		tr[p].tag2=0;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].val=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};

	auto updata = [&](auto self,int l,int r,int x,int y,int val1,int val2,int p)->void{
		if(x<=l&&r<=y){
			tr[p].val=(tr[p].val*val1%mod+val2)%mod;
			tr[p].tag1=tr[p].tag1*val1%mod;
			tr[p].tag2=(tr[p].tag2+val2)%mod;
			return ;
		}
		down(p);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,val1,val2,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val1,val2,p<<1|1);
	};

	auto get= [&](auto self,int l,int r,int p)->void{
		if(l==r){
			a[l]=tr[p].val;
			return ;
		}
		int mid=(l+r)>>1;
		down(p);
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};

	bulid(bulid,1,n,1);
	for(int i=1;i<=m;i++){
		int l,r,x;cin>>l>>r>>x;
		int d=qmi(r-l+1,mod-2);
		int res1=(r-l)*d%mod;
		int res2=x*d%mod;
		updata(updata,1,n,l,r,res1,res2,1);
	}
	get(get,1,n,1);
	for(int i=1;i<=n;i++)cout<<a[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}
/*
821382814 987210378 819486592 249506617 555228842 524120715 209847604 859251969 689582206 117876126 902853002 190254803 639535281 93008961 364588825 210608115 255885120 957400985 685902422 330908158
821382814 987210378 819486592 142238362 447960587 678128197 687469071 405316549 318941070 457450677 426617745 712263899 939619994 228431878 307695685 196179692 241456697 12668393 685902422 330908158

*/