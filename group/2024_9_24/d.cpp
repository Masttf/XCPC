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
constexpr int Max = 1e18;
void solve(){
    int n; cin >> n;
    vector g(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cin >> g[i][j];
    	}
    }
    vector<int>a(1);
    int x;
    while(cin >> x){
    	a.push_back(x);
    }
    int m = a.size() - 1;
    vector dp(5, vector(n + 1, vector<int>(n + 1, Max)));
    vector ndp(5, vector(n + 1, vector<int>(n + 1)));
    dp[1][2][3] = g[1][a[1]];
    dp[2][1][3] = g[2][a[1]];
    dp[3][1][2] = g[3][a[1]];
    for(int i = 2; i <= m; i++){
    	swap(dp, ndp);
    	for(int j = 1; j <=3; j++){
    		for(int k = 1; k <= n; k++){
    			for(int p = 1; p <= n; p++){
    				dp[j][k][p] = Max;
    			}
    		}
    	}
    	for(int j = 1; j <= 3; j++){
    		for(int k = 1; k <= 3; k++){
    			for(int p = 1; p <= n; p++){
    				for(int q = 1; q <= n; q++){
    					if(j == k){
    						dp[j][p][q] = min(dp[j][p][q], ndp[k][p][q] + g[a[i - 1]][a[i]]);
    					}else if(k == 1){ // 2 3
    						if(j == 2) dp[j][a[i - 1]][q] = min(dp[j][a[i - 1]][q], ndp[k][p][q] + g[p][a[i]]);
    						else dp[j][a[i - 1]][p] = min(dp[j][a[i - 1]][p], ndp[k][p][q] + g[q][a[i]]);
    					}else if(k == 2){// 1 3
    						if(j == 1) dp[j][a[i - 1]][q] = min(dp[j][a[i - 1]][q], ndp[k][p][q] + g[p][a[i]]);
    						else dp[j][p][a[i - 1]] = min(dp[j][p][a[i - 1]], ndp[k][p][q] + g[q][a[i]]);
    					}else{// 1 2
    						if(j == 1)dp[j][
    							.3q][a[i - 1]] = min(dp[j][q][a[i - 1]], ndp[k][p][q] + g[p][a[i]]);
    						else dp[j][p][a[i - 1]] = min(dp[j][p][a[i - 1]], ndp[k][p][q] + g[q][a[i]]);
    					}
    				}
    			}
    		}
    	}
    }
    int ans = Max;
    for(int i = 1; i <= 3; i++){
    	for(int j = 1; j <= n; j++){
    		for(int k = 1; k <= n; k ++){
    			ans = min(ans, dp[i][j][k]);
    		}
    	}
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;// cin >> t;
    while(t--)solve();
    return 0;
}