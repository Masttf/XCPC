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
const int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	a[0]=Max;
	vector<int>dp(n+1);
	map<int,int>m;
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]^a[i];
	m[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(a[i]!=0);
		int d=a[i]^pre[i-1];
		if(m.count(d)){
			int p=m[d];
			dp[i]=min(dp[i],dp[p]+i-p-1);
		}
		m[pre[i]]=i;
	}
	cout<<dp[n]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}