#include<bits/stdc++.h>
#define int long long
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
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>dp1(n+1),dp2(n+1);
	auto get1 = [&]()->void{
		vector<int>res;
		for(int i=1;i<=n;i++){
			int p=lower_bound(res.begin(),res.end(),a[i])-res.begin();
			if(p==res.size()){
				res.push_back(a[i]);
				dp1[i]=res.size();
			}else{
				res[p]=a[i];
				dp1[i]=p+1;
			}
		}
	};
	auto get2 = [&]()->void{
		vector<int>p;
		for(int i=1;i<=n;i++)p.push_back(a[i]);
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		auto get = [&](int x)->int{
			return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
		};
		for(int i=1;i<=n;i++){
			a[i]=get(a[i]);
		}
		vector<int>tr(n*4);
		auto updata = [&](auto self,int l,int r,int x,int val,int p)->void{
			if(l==r){
				tr[p]=val;
				return ;
			}
			int mid=(l+r)>>1;
			if(x<=mid)self(self,l,mid,x,val,p<<1);
			else self(self,mid+1,r,x,val,p<<1|1);
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
		for(int i=n;i>=1;i--){
			int d=query(query,1,n+1,a[i]+1,n+1,1)+1;
			updata(updata,1,n+1,a[i],d,1);
			dp2[i]=d;
		}
	};
	get1();
	get2();
	vector<int>res;
	int mx=*max_element(dp1.begin()+1,dp1.end());
	for(int i=1;i<=n;i++){
		if(dp1[i]+dp2[i]-1==mx)res.push_back(i);
	}
	cout<<res.size()<<'\n';
	for(auto x:res)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}