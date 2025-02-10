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
void solve(){
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
   	vector dp(n + 1, vector<int>(2));
   	dp[0][0] = 0;
   	dp[0][1] = -1e18;
   	for(int i = 1; i <= n; i++){
   		for(int j = 0; j < 2; j++){
   			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j ^ 1] + a[i] * (j == 0 ? 2 : 1));
   			//dbg(i, j, dp[i][j]);
   		}
   	}
   	cout << max(dp[n][0], dp[n][1]) << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}