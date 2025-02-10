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
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
	int ans=-1;
	auto get = [&](int pp)->void{
		vector<int>dp(n+1,-1);
		vector tr(2,vector<int>(n*35));
		vector<int>mx(n*35,-1);
		int tot=1;
		auto insert = [&](int x,int y)->void{
			int p=1;
			for(int i=30;i>=0;i--){
				int d=x>>i&1;
				int d2=m>>i&1;
				if(i>pp&&d2==1)d=1;
				if(!tr[d][p])tr[d][p]=++tot;
				p=tr[d][p];
				mx[p]=max(mx[p],y);
			}
		};
		auto ask = [&](int x)->int{
			int p=1;
			for(int i=30;i>pp;i--){
				int d1=x>>i&1;
				int d2=m>>i&1;
				if(d2==1)p=tr[1][p];
				else p=tr[d1][p];
			}
			if(pp==-1)return mx[p];
			int d1=x>>pp&1;
			p=tr[d1][p];
			return mx[p];
		};
		insert(0,0);
		dp[0]=1;
		for(int i=1;i<=n;i++){
			int p=ask(pre[i]);
			if(p==-1){
				if(i==1)dp[1]=-1;
				else dp[i]=dp[i-1];
			}else{
				if(dp[p]==-1){
					dp[i]=dp[i-1];
					continue;
				}else dp[i]=max(dp[i-1],dp[p]+1);
			}
			if(i!=n)insert(pre[i],i);
		}
		int p=ask(pre[n]);
		if(p==-1)return ;
		else ans=max(ans,dp[p]);
	};
	for(int i=30;i>=0;i--){
		if(m>>i&1){
			get(i);
		}
	}
	get(-1);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}