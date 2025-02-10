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
	int mi,mx,val,id;
};
bool cmp(node &x,node&y){
	return x.mx<y.mx;
}
bool cmp2(node &x,node &y){
	return x.id<y.id;
}
bool cmp3(node &x,node &y){
	return x.val<y.val;
}
const int maxn=100000;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>mx(n+1),mi(n+1);
	for(int i=1;i<=n;i++){
		mx[i]=mi[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		mx[x]=max(mx[x],y);
		mi[x]=min(mi[x],y);
	}
	vector<int>dp(n+1);
	vector<node>res(n+1);
	for(int i=1;i<=n;i++){
		res[i]={mi[i],mx[i],a[i],i};
		//dbg(i,mx[i],mi[i],a[i]);
	}
	vector<int>tr(maxn*4+10);
	auto updata = [&](auto self,int l,int r,int x,int k,int t,int p)->void{
		//dbg(l,r);
		if(l==r){
			if(t==2)tr[p]=0;
			else tr[p]=max(tr[p],k);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,k,t,p<<1);
		else self(self,mid+1,r,x,k,t,p<<1|1);
		tr[p]=max(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y)return tr[p];
		int res=0;
		int mid=(l+r)>>1;
		if(x<=mid)res=max(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	auto cdq = [&](auto self,int l,int r)->void{
		//dbg("s",l,r);
		if(l==r){
			dp[l]++;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid);
		sort(res.begin()+mid+1,res.begin()+r+1,cmp3);
		//dbg(l,r);
		int i=l,j=mid+1;
		for(;j<=r;j++){
			while(i<=mid&&res[i].mx<=res[j].val){
				//dbg(i,res[i].id);
				updata(updata,1,maxn,res[i].val,dp[res[i].id],1,1);
				i++;
			}
			//dbg(j,res[j].id);
			dp[res[j].id]=max(dp[res[j].id],query(query,1,maxn,1,res[j].mi,1));
		}
		//dbg("YES");
		for(i--;i>=l;i--){
			updata(updata,1,maxn,res[i].val,0,2,1);
		}
		sort(res.begin()+mid+1,res.begin()+r+1,cmp2);
		self(self,mid+1,r);
		sort(res.begin()+l,res.begin()+r+1,cmp);
	};
	cdq(cdq,1,n);
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}