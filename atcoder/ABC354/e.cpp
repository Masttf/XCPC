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
	vector<int>a(n),b(n);
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	vector<int>dp(1<<n,-1);
	auto dfs = [&](auto self,int x)->int{
		if(dp[x]!=-1)return dp[x];
		int ok=0;
		for(int i=0;i<n;i++){
			if(!(x>>i&1))continue;
			for(int j=i+1;j<n;j++){
				if(!(x>>j&1))continue;
				if(a[i]==a[j]||b[i]==b[j]){
					if(self(self,x^(1<<i)^(1<<j))==0)ok=1;
				}
			}
		}
		return dp[x]=ok;
	};
	dfs(dfs,(1<<n)-1);
	if(dp[(1<<n)-1]==1)cout<<"Takahashi\n";
	else cout<<"Aoki\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}