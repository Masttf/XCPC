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
	vector a(n+1,vector<int>(4));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++)cin>>a[i][j];
	}
	int ans=0;
	for(int s=1;s<=3;s++){
		vector dp(n+1,vector<int>(4,-1));
		dp[1][s]=a[1][s];
		for(int i=2;i<=n;i++){
			if(i%2==0){
				for(int j=1;j<=3;j++){
					for(int k=1;k<j;k++){
						if(dp[i-1][k]!=-1)
						dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
					}
				}
			}else{
				for(int j=1;j<=3;j++){
					for(int k=j+1;k<=3;k++){
						if(dp[i-1][k]!=-1)
						dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
					}
				}
			}
		}
		for(int j=s+1;j<=3;j++)ans=max(ans,dp[n][j]);
		dp=vector(n+1,vector<int>(4,-1));
		dp[1][s]=a[1][s];
		for(int i=2;i<=n;i++){
			if(i%2==0){
				for(int j=1;j<=3;j++){
					for(int k=j+1;k<=3;k++){
						if(dp[i-1][k]!=-1)
						dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
					}
				}
			}else{
				for(int j=1;j<=3;j++){
					for(int k=1;k<j;k++){
						if(dp[i-1][k]!=-1)
						dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
					}
				}
			}
		}
		for(int j=1;j<s;j++)ans=max(ans,dp[n][j]);
	}
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