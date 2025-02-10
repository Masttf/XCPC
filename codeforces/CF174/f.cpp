#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n,d;cin>>n>>d;
	vector<int>a(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++)cin>>a[i],p.push_back(a[i]);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};

	vector<pair<int,int>>tr(n*4);
	auto updata = [&](auto self,int l,int r,int x,int val,int t,int p)->void{
		if(l==r){
			tr[p]=max(tr[p],{val,t});
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,val,t,p<<1);
		else self(self,mid+1,r,x,val,t,p<<1|1);
		tr[p]=max(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->pair<int,int>{
		//dbg(l,r,p,tr[p]);
		if(x<=l&&r<=y)return tr[p];
		int mid=(l+r)>>1;
		pair<int,int> res={0,0};
		if(x<=mid)res=max(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	vector<int>dp(n+1);
	vector<int>f(n+1,-1);
	for(int i=1;i<=n;i++){
		dp[i]=1,f[i]=i;
		int temp1=a[i]-d;
		temp1=get(temp1);
		if(p[temp1-1]>a[i]-d)temp1--;
		pair<int,int>res={0,0};
		if(temp1>=1)res=max(res,query(query,1,n,1,temp1,1));
		//dbg(res.first,res.second);
		int temp2=a[i]+d;
		temp2=get(temp2);
		if(temp2<=n)res=max(res,query(query,1,n,temp2,n,1));
		//dbg(res.first,res.second);
		if(res.first){
			dp[i]=res.first+1;
			f[i]=res.second;
		}
		//dbg(temp1,temp2);
		updata(updata,1,n,get(a[i]),dp[i],i,1);
		//dbg(temp1,temp2,dp[i],f[i]);
	}
	int now=-1;
	for(int i=1;i<=n;i++){
		if(now==-1||dp[i]>dp[now])now=i;
	}
	vector<int>ans;
	while(f[now]!=now){
		ans.push_back(now);
		now=f[now];
	}
	ans.push_back(now);
	reverse(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(auto x:ans)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}