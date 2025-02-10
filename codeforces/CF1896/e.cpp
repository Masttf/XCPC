#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
//#define int long long
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
struct node{
	int l,r,f,id;
};
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>ans(n+1);
	vector<vector<node>>q(2*n+1);
	vector<vector<int>>p(2*n+1);
	for(int i=1;i<=n;i++){
		ans[a[i]]=(a[i]-i+n)%n+1;
		int l=i;
		int r=a[i];
		if(r<l)r+=n;
		p[l].push_back(r);
		q[l-1].push_back({l,r,-1,a[i]});
		q[r].push_back({l,r,1,a[i]});
		if(r+n<=2*n){
			q[l+n-1].push_back({l+n,r+n,-1,a[i]});
			q[r+n].push_back({l+n,r+n,1,a[i]});
			p[l+n].push_back(r+n);
		}
	}
	vector<int>t(2*n+1);
	auto updata = [&](int x)->void{
		while(x<=2*n){
			t[x]++;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	vector<int>vis(n+1);
	for(int i=1;i<=2*n;i++){
		//cout<<i<<endl;
		for(auto x:p[i]){
			updata(x);
			//dbg(x);
		}
		for(auto [l,r,f,id]:q[i]){
			if(vis[id])continue;
			//dbg(i,l,r,f,id);
			ans[id]-=f*(ask(r)-ask(l-1));
			if(f==1)vis[id]=1;
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
