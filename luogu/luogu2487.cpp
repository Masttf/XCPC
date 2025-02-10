#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int h,v,id;
};
bool cmp(node &x,node&y){
	if(x.h!=y.h)return x.h>y.h;
	if(x.v!=y.v)return x.v>y.v;
	return x.id<y.id;
}
bool cmp2(node &x,node&y){
	return x.id<y.id;
}
bool cmp3(node &x,node&y){
	if(x.h!=y.h)return x.h<y.h;
	if(x.v!=y.v)return x.v<y.v;
	return x.id<y.id;
}
void solve(){
	int n;cin>>n;
	vector<node>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		p.push_back(y);
		a[i]={x,y,i};
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	for(int i=1;i<=n;i++){
		a[i].v=get(a[i].v);
	}
	vector<node>b(n+1);
	for(int i=1;i<=n;i++)b[i]=a[i];
	vector<pair<int,double>>tr(n*40);
	auto updata = [&](auto self,int l,int r,int x,pair<int,double> val,int t,int p)->void{
		if(l==r){
			if(t==2)tr[p]={0,0};
			else{
				if(tr[p].first==val.first)tr[p].second+=val.second;
				else tr[p]=max(tr[p],val);
			}
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,val,t,p<<1);
		else self(self,mid+1,r,x,val,t,p<<1|1);
		if(tr[p<<1].first==tr[p<<1|1].first){
			tr[p].first=tr[p<<1].first;
			tr[p].second=tr[p<<1].second+tr[p<<1|1].second;
		}else tr[p]=max(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->pair<int,double>{
		if(x<=l&&r<=y)return tr[p];
		int mid=(l+r)>>1;
		pair<int,double> res={0,0};
		if(x<=mid){
			pair<int,double>temp=self(self,l,mid,x,y,p<<1);
			if(res.first==temp.first)res.second+=temp.second;
			else res=max(res,temp);
		}
		if(y>mid){
			pair<int,double>temp=self(self,mid+1,r,x,y,p<<1|1);
			if(res.first==temp.first)res.second+=temp.second;
			else res=max(res,temp);
		}
		return res;
	};
	vector<int>dp(n+1);
	vector<double>g(n+1);
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r){
			dp[l]++;
			if(dp[l]==1)g[l]=1;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid);
		sort(a.begin()+mid+1,a.begin()+r+1,cmp);
		int i=l,j=mid+1;
		//dbg(l,r);
		for(;j<=r;j++){
			while(i<=mid&&a[i].h>=a[j].h){
				updata(updata,1,n,a[i].v,{dp[a[i].id],g[a[i].id]},1,1);
				i++;
			}
			pair<int,double>res=query(query,1,n,a[j].v,n,1);
			if(res.first>dp[a[j].id]){
				dp[a[j].id]=res.first;
				g[a[j].id]=res.second;
			}else if(res.first==dp[a[j].id]){
				g[a[j].id]+=res.second;
			}
			//dbg(a[j].id,dp[a[j].id]);
		}
		for(i--;i>=l;i--){
			updata(updata,1,n,a[i].v,{0,0},2,1);
		}
		sort(a.begin()+mid+1,a.begin()+r+1,cmp2);
		self(self,mid+1,r);
		sort(a.begin()+l,a.begin()+r+1,cmp);
	};
	cdq(cdq,1,n);

	vector<int>dp2(n+1);
	vector<double>g2(n+1);
	auto cdq2 = [&](auto self,int l,int r)->void{
		if(l==r){
			dp2[l]++;
			if(dp2[l]==1)g2[l]=1;
			//dbg(l,r,dp2[l]);
			return ;
		}
		int mid=(l+r)>>1;
		self(self,mid+1,r);
		sort(b.begin()+l,b.begin()+mid+1,cmp3);
		int i=l,j=mid+1;
		//dbg(l,r);
		for(;i<=mid;i++){
			while(j<=r&&b[i].h>=b[j].h){
				updata(updata,1,n,b[j].v,{dp2[b[j].id],g2[b[j].id]},1,1);
				//dbg(j,b[j].v);
				j++;
			}
			pair<int,double>res=query(query,1,n,1,b[i].v,1);
			//dbg(i,j,res.first);
			if(res.first>dp2[b[i].id]){
				dp2[b[i].id]=res.first;
				g2[b[i].id]=res.second;
			}else if(res.first==dp2[b[i].id]){
				g2[b[i].id]+=res.second;
			}
			//dbg(b[i].id,dp2[b[i].id]);
		}
		for(j--;j>=mid+1;j--){
			updata(updata,1,n,b[j].v,{0,0},2,1);
		}
		sort(b.begin()+l,b.begin()+mid+1,cmp2);
		self(self,l,mid);
		sort(b.begin()+l,b.begin()+r+1,cmp3);
	};
	cdq2(cdq2,1,n);
	int ans=0;
	double sum=0;
	for(int i=1;i<=n;i++){
		if(dp[i]>ans){
			ans=dp[i];
			sum=g[i];
		}else if(dp[i]==ans)sum+=g[i];
		//dbg(i,dp[i],g[i]);
		//dbg(dp2[i],g2[i]);
	}
	cout<<ans<<'\n';
	for(int i=1;i<=n;i++){
		int len=dp[i]+dp2[i]-1;
		double res=0;
		if(len==ans){
			res=1.0*g[i]*g2[i]/sum;
		}
		cout<<fixed<<setprecision(10)<<res<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}