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
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	vector<int>b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int _=1;_<=q;_++){
		int x,y;cin>>x>>y;
		vector<int>dp(n+1);
		vector<int>mx(n+1,-1e18);
		int mx1=0,mx2=0;
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1];
			int d1=mx[b[i]]+x*a[i];
			int d2=(mx1==mx[b[i]]?mx2:mx1)+y*a[i];
			dp[i]=max(dp[i],d1);
			dp[i]=max(dp[i],d2);
			mx[b[i]]=max({mx[b[i]],d1,d2});
			if(mx[b[i]]>mx1){
				mx2=mx1;
				mx1=mx[b[i]];
			}else if(mx[b[i]]>mx2)mx2=mx[b[i]];
		}
		cout<<dp[n]<<'\n';
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