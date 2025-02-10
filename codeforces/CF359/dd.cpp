#include<bits/stdc++.h>
//#define int long long
#define lowbit(x) ((x)&-(x))
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
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<vector<int>>st(21,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		st[0][i]=a[i];
	}
	for(int s=1;(1ll<<s)<=n;s++){
		for(int i=1;i+(1ll<<s)<=n+1;i++){
			st[s][i]=__gcd(st[s-1][i],st[s-1][i+(1ll<<(s-1))]);
		}
	}
	vector<set<int>>ans(n);
	
	auto get = [&](int l,int r)->int{
		int len=r-l+1;
		int res=0;
		while(len){
			int d=__lg(lowbit(len));
			res=__gcd(res,st[d][l]);
			l+=lowbit(len);
			len-=lowbit(len);
		}
		return res;
	};
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int res1=i;
		while(l<=r){
			int mid=(l+r)>>1;
			int d=get(mid,i);
			if(d==a[i]){
				r=mid-1;
				res1=mid;
			}else l=mid+1;
		}
		l=i,r=n;
		int res2=i;
		while(l<=r){
			int mid=(l+r)>>1;
			int d=get(i,mid);
			if(d==a[i]){
				l=mid+1;
				res2=mid;
			}else r=mid-1;
		}
		//dbg(i,res1,res2);
		ans[res2-res1].insert(res1);
	}
	for(int i=n-1;i>=0;i--){
		if(ans[i].empty())continue;
		cout<<ans[i].size()<<' '<<i<<'\n';
		for(auto it=ans[i].begin();it!=ans[i].end();it++)cout<<(*it)<<' ';
		return ;
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