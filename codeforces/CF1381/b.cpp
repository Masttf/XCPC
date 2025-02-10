#include<bits/stdc++.h>
#define int int long long
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
	int n;cin>>n;
	vector<int>a(2*n+1);
	for(int i=1;i<=2*n;i++)cin>>a[i];
	vector<int>res(1);
	for(int i=1;i<=2*n;i++){
		int j=i;
		while(j<=2*n&&a[i]>=a[j])j++;
		res.push_back(j-i);
		i=j-1;
	}
	// for(auto x :res)cout<<x<<' ';
	// cout<<endl;
	int len=res.size()-1;
	vector dp(len+1,vector<int>(n+1));
	dp[0][0]=1;
	for(int i=1;i<=len;i++){
		for(int j=0;j<=n;j++)dp[i][j]=dp[i-1][j];
		for(int j=res[i];j<=n;j++){
			dp[i][j]|=dp[i-1][j-res[i]];
		}
	}
	if(dp[len][n])cout<<"Yes\n";
	else cout<<"No\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}