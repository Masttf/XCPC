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
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	vector dp(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		if(a[i][i])dp[i][i]=1;
	}
	for(int i=-1;i>=1-n;i--){
		for(int j=1;j<=n;j++){
			int x=j;
			int y=i+x;
			if(y>=1){
				if(a[x][y]==a[x-1][y]&&a[x][y]==a[x][y+1]&&)
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