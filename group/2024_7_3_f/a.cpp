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
constexpr int mod=10301;
void solve(){
	int n,a,b;cin>>n>>a>>b;
	vector f(n+1,vector<int>(n+1));
	for(int i=0;i<=n;i++){
		f[i][i]=1;
	}
	for(int i=0;i<=n;i++){
		for(int j=i-1;j>=0;j--){
			f[i][j]=((f[i][j+1]+f[i-j][j])%mod+mod)%mod;
		}
	}
	int ans=0;
	for(int i=a;i<=n-b;i++){
		ans+=(f[i][a]-f[i-1][a])*f[n-i][b]%mod;
		ans=((ans%mod)+mod)%mod;
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