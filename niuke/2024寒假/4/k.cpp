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
const int Max=1e18;
const int mod=1e9+7;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
struct node{
	int val,cnt,tag,rval;
};
void solve(){
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s=' '+s;
	vector<node>tr(n*4);
	auto up = [&](int p)->void{
		tr[p].val=(tr[p<<1].val+tr[p<<1].rval*(qmi(2,tr[p<<1|1].cnt)+mod-1)%mod+tr[p<<1|1].val)%mod;
		if(tr[p<<1].tag&&tr[p<<1|1].tag){
			tr[p].tag=1;
			tr[p].cnt=tr[p<<1].cnt;
			tr[p].rval=tr[p<<1|1].rval;
		}else if(tr[p<<1].tag){
			tr[p].tag=1;
			tr[p].cnt=tr[p<<1].cnt;
			tr[p].rval=(tr[p].val-tr[p<<1].val+tr[p<<1].rval+mod)%mod;
		}else if(tr[p<<1|1].tag){
			tr[p].tag=1;
			tr[p].cnt=tr[p<<1].cnt+tr[p<<1|1].cnt;
			tr[p].rval=tr[p<<1|1].rval;
		}else{
			tr[p].tag=0;
			tr[p].cnt=tr[p<<1].cnt+tr[p<<1|1].cnt;
			tr[p].rval=tr[p].val;
		}
	};
	auto mg = [&](node x,node y)->node{
		node res;
		res.val=(x.val+x.rval*(qmi(2,y.cnt)+mod-1)%mod+y.val)%mod;
		if(x.tag&&y.tag){
			res.tag=1;
			res.cnt=x.cnt;
			res.rval=y.rval;
		}else if(x.tag){
			res.tag=1;
			res.cnt=x.cnt;
			res.rval=(res.val-x.val+x.rval+mod)%mod;
		}else if(y.tag){
			res.tag=1;
			res.cnt=x.cnt+y.cnt;
			res.rval=y.rval;
		}else{
			res.tag=0;
			res.cnt=x.cnt+y.cnt;
			res.rval=res.val;
		}
		return res;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			if(s[l]=='Y'){
				tr[p].val=1;
				tr[p].rval=1;
				tr[p].cnt=0;
				tr[p].tag=0;
			}else if(s[l]=='B'){
				tr[p].val=1;
				tr[p].rval=1;
				tr[p].cnt=0;
				tr[p].tag=1;
			}else{
				tr[p].val=1;
				tr[p].rval=1;
				tr[p].cnt=1;
				tr[p].tag=0;
			}
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
	};
	auto updata = [&](auto self,int l,int r,int x,char k,int p)->void{
		if(l==r){
			s[l]=k;
			if(s[l]=='Y'){
				tr[p].val=1;
				tr[p].rval=1;
				tr[p].cnt=0;
				tr[p].tag=0;
			}else if(s[l]=='B'){
				tr[p].val=1;
				tr[p].rval=1;
				tr[p].cnt=0;
				tr[p].tag=1;
			}else{
				tr[p].val=1;
				tr[p].rval=1;
				tr[p].cnt=1;
				tr[p].tag=0;
			}
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,k,p<<1);
		else self(self,mid+1,r,x,k,p<<1|1);
		up(p);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		if(x<=l&&r<=y){
			return tr[p];
		}
		int mid=(l+r)>>1;
		node res={-1,0,0,0};
		if(x<=mid){
			res=self(self,l,mid,x,y,p<<1);
		}
		if(y>mid){
			node temp=self(self,mid+1,r,x,y,p<<1|1);
			if(res.val==-1)res=temp;
			else{
				res=mg(res,temp);
			}
		}
		return res;
	};
	bulid(bulid,1,n,1);
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int p;char k;cin>>p>>k;
			updata(updata,1,n,p,k,1);
		}else{
			int x,y;cin>>x>>y;
			node res=query(query,1,n,x,y,1);
			cout<<res.val<<'\n';
		}
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
