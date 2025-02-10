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
	int n,k;cin>>n>>k;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	auto get = [&]()->int{
		int mx=a[1];
		vector<int>dp(n+1);
		for(int i=1;i<=n;i++){
			dp[i]=dp[i-1]+a[i];
			dp[i]=max(dp[i],a[i]);
			mx=max(mx,dp[i]);
		}
		return mx;
	};
	if(k==1){
		int ans=a[1];
		for(int i=1;i<n;i++){
			swap(a[i],a[i+1]);
			ans=max(ans,get());
			swap(a[i],a[i+1]);
		}
		cout<<ans<<'\n';
	}else cout<<get()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}