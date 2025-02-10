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
constexpr int maxn=105;
int dp[maxn][maxn][maxn];
void solve(){
	int n,m,q;cin>>n>>m>>q;
	vector<int>a(n+1),b(m+1),c(q+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	for(int i=1;i<=q;i++)cin>>c[i];
	reverse(a.begin()+1,a.end());
	reverse(b.begin()+1,b.end());
	reverse(c.begin()+1,c.end());
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=q;k++){
				if(i==0&&j==0&&k==0)dp[i][j][k]=0;
				else{
					int num=i+j+k;
					if(i>0)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+num*a[i]);
					if(j>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+num*b[j]);
					if(k>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+num*c[k]);
				}
			}
		}
	}

	cout<<dp[n][m][q]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}