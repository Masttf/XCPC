#include<bits/stdc++.h>
//#define int long long
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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	string a,b;cin>>a>>b;
	a=' '+a;
	b=' '+b;
	vector dp(n+1,vector<int>(m+1));
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+2;
			else{
				for(int p=0;p<=4;p++){
					for(int q=0;p+q<=4;q++){
						if(i-p<0||j-q<0)continue;
						dp[i][j]=max(dp[i][j],dp[i-p][j-q]-p-q);
					}
				}
			}
			ans=max(ans,dp[i][j]);
		}
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