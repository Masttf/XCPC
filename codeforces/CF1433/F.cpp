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
constexpr int maxn = 5000, inf = 1e18;
void solve(){
    int n, m, K; cin >> n >> m >> K;
    vector a(n + 1, vector<int>(m + 1));
    int mx = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    		mx = max(mx, a[i][j]);
    	}
    }
    mx = m * mx;
    int d = m / 2;
    vector dp(n + 1, vector<int>(K, -inf));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
    	vector<bitset<maxn>> ndp(d + 1);
    	ndp[0][0] = 1;
    	for(int j = 1; j <= m; j++){
    		for(int k = d; k >= 1; k--){
    			ndp[k] |= (ndp[k - 1] << a[i][j]);
    			// dbg(i, j, k, ndp[k][8], ndp[k - 1][4]);
    		}
    	}
    	bitset<maxn> res;
    	for(int j = 0; j <= d; j++){
    		res |= ndp[j];
    	}
    	for(int j = 0; j <= mx; j++){
    		if(res[j]){
    			// dbg(i, j);
    			for(int k = 0; k < K; k++){
    				dp[i][k] = max(dp[i - 1][k], dp[i][k]);
    				int v = (j + k) % K;
    				// dbg(v);
    				dp[i][v] = max(dp[i][v], dp[i - 1][k] + j);
    			}
    		}
    	}
    	// for(int j = 0; j < K; j++){
    	// 	cout << dp[i][j] << " \n"[j == K - 1];
    	// }
    }
    cout << dp[n][0] << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}
/*
ndp ?
%k 
*/