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
	int n,m1,m2;cin>>n>>m1>>m2;
	vector<int>a(n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	sort(a.begin()+1,a.end());
	vector<int>cost(n+1);
	vector<int>dp(m1+1);
	auto dfs = [&](auto self,int now,int sum,int last)->void{
		if(now==n+1){
			if(sum!=0);
			dp.assign(m1+1,0);
			for(int i=1;i<=n;i++){
				for(int j=m1;j>=cost[i];j--){
					dp[j]=max(dp[j],dp[j-cost[i]]+a[i]);
				}
			}
			int mx=*max_element(dp.begin(),dp.end());
			ans=min(ans,mx);
			return ;
		}
		if((n-now+1)*last>sum)return ;
		for(int i=last;i<=sum;i++){
			cost[now]=i;
			self(self,now+1,sum-i,i);
		}
	};
	dfs(dfs,1,m2,0);
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}