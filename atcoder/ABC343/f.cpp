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
struct node{
	int mx1,mx2,cnt1,cnt2;
};
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<node>tr(n*4);
	auto up = [&](int p)->void{
		tr[p]={0,0,0,0};
		int mx=max(tr[p<<1].mx1,tr[p<<1|1].mx1);
		tr[p].mx1=mx;
		if(tr[p<<1].mx1==mx)tr[p].cnt1+=tr[p<<1].cnt1;
		if(tr[p<<1|1].mx1==mx)tr[p].cnt1+=tr[p<<1|1].cnt1;
		vector<pair<int,int>>temp(4);
		temp[0]={tr[p<<1].mx1,tr[p<<1].cnt1};
		temp[1]={tr[p<<1].mx2,tr[p<<1].cnt2};
		temp[2]={tr[p<<1|1].mx1,tr[p<<1|1].cnt1};
		temp[3]={tr[p<<1|1].mx2,tr[p<<1|1].cnt2};
		int mmx2=0;
		for(int i=0;i<4;i++){
			if(temp[i].first==mx)continue;
			mmx2=max(mmx2,temp[i].first);
		}
		tr[p].mx2=mmx2;
		for(int i=0;i<4;i++){
			if(temp[i].first==mmx2)tr[p].cnt2+=temp[i].second;
		}
	};
	auto mg = [&](node x,node y)->node{
		node res={0,0,0,0};
		int mx=max(x.mx1,y.mx1);
		res.mx1=mx;
		if(x.mx1==mx)res.cnt1+=x.cnt1;
		if(y.mx1==mx)res.cnt1+=y.cnt1;
		vector<pair<int,int>>temp(4);
		temp[0]={x.mx1,x.cnt1};
		temp[1]={x.mx2,x.cnt2};
		temp[2]={y.mx1,y.cnt1};
		temp[3]={y.mx2,y.cnt2};
		int mmx2=0;
		for(int i=0;i<4;i++){
			if(temp[i].first==mx)continue;
			mmx2=max(mmx2,temp[i].first);
		}
		res.mx2=mmx2;
		for(int i=0;i<4;i++){
			if(temp[i].first==mmx2)res.cnt2+=temp[i].second;
		}
		return res;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].mx1=a[l];
			tr[p].cnt1=1;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		up(p);
		// dbg(l,r);
		// dbg(tr[p].mx1,tr[p].cnt1,tr[p].mx2,tr[p].cnt2);
	};
	auto updata = [&](auto self,int l,int r,int x,int k,int p)->void{
		if(l==r){
			tr[p].mx1=k;
			tr[p].cnt1=1;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,k,p<<1);
		else self(self,mid+1,r,x,k,p<<1|1);
		up(p);
		return ;
	};
	bulid(bulid,1,n,1);
	//dbg(tr[1].mx1,tr[1].cnt1,tr[1].mx2,tr[1].cnt2);
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		//dbg(l,r);
		if(x<=l&&r<=y)return tr[p];
		int mid=(l+r)>>1;
		node res={0,0,0,0};
		if(x<=mid)res=mg(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=mg(res,self(self,mid+1,r,x,y,p<<1|1));
		
		// dbg(l,r);
		// dbg(res.mx1,res.cnt1,res.mx2,res.cnt2);
		return res;
	};
	for(int i=1;i<=q;i++){
		int t,x,y;cin>>t>>x>>y;
		if(t==1){
			updata(updata,1,n,x,y,1);
		}else{
			node ans=query(query,1,n,x,y,1);
			cout<<ans.cnt2<<'\n';
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