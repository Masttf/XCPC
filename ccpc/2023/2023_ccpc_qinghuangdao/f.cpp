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
constexpr int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	mx*=2;
	vector<int>prim;
	vector<int>vis(mx+1);
	//vis[1]=1;
	for(int i=2;i<=mx;i++){
		if(!vis[i])prim.push_back(i);
		for(int j=0;i*prim[j]<=mx;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0)break;
		}
	}
	vector dp(2,vector<int>(n+1,Max));
	dp[0][1]=0;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		dp[1][i]=min(dp[0][i-1],dp[1][i-1])+1;
		dp[0][i]=min(dp[0][i],i-1);
		int sum=a[i]+a[i-1];
		if(!vis[sum])dp[0][i]=min(dp[0][i-1],dp[0][i]);
		for(int j=1;j<=i-2;j++){
			if(a[j]%2==1&&a[i]%2==1){
				dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			}
			if(!vis[a[j]+1]&&!vis[a[i]+1])dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			if(((i-j)%2==1)&&(a[j]%2!=a[i]%2)){
				dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			}
			if(((i-j)%2==0)&&(a[j]%2==a[i]%2)){
				dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			}
			if(i-j-1>=5)dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			if(!vis[a[j]+1]&&i-j-1>=3)dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			if(!vis[a[i]+1]&&i-j-1>=3)dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			if(a[j]==1&&i-j-1>=2)dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
			if(a[i]==1&&i-j-1>=2)dp[0][i]=min(dp[0][j]+i-j-1,dp[0][i]);
		}
		//dbg(i,dp[0][i],dp[1][i]);
	}
	int ans=n-1;
	ans=min({ans,dp[0][n],dp[1][n]});
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