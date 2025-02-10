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
constexpr int mod=1e9+7;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector dp(10,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=0;j<=9;j++)dp[j][i]=dp[j][i-1];
		int now=s[i]-'0';
		for(int j=0;j<=9;j++){
			dp[now][i]+=dp[j][i-1];
			dp[now][i]%=mod;
		}
		if(now)dp[now][i]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0')ans++;
	}
	for(int i=0;i<=9;i+=2){
		ans+=dp[i][n];
		ans%=mod;
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