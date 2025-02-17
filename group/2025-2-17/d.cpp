#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout << endl << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int n, k; cin >> n >> k;
    vector<int> vis(n + 1);
    for(int i = 1; i <= k; i++){
    	int x; cin >> x;
    	vis[x] = 1;
    }
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
    	if(vis[i]){
    		dp[i] = 2 * (dp[i - 1] + 1);
    	}else{
    		dp[i] = dp[i - 1] + 1;
    	}
    }
    cout << dp[n] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}