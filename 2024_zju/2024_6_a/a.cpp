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
constexpr int maxn=105;
bool dp[maxn][maxn];
bool f[maxn][maxn][maxn][maxn];
void solve(){
	int n,m;cin>>n>>m;
	vector a(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			a[i][j]=(a[i][j]+m)%m;
		}
	}
	f[1][1][1][0]=1;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]|=dp[i-1][(j-a[i][i]+m)%m];
			f[i][i][i][j]=dp[i-1][j];
		}
		for(int j=1;j<n;j++){
			for(int k=1;k<n;k++){
				for(int p=0;p<m;p++){
					dp[i][p]|=f[i-1][j][k][(p-a[i][k]-a[j][i]+m+m)%m];
					f[i][j][i][p]|=f[i-1][j][k][(p-a[i][k]+m)%m];
					f[i][i][k][p]|=f[i-1][j][k][(p-a[j][i]+m)%m];
				}
			}
		}

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