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
constexpr int maxn = 65;
int dp[maxn][maxn][maxn];
void init(){
	int inf = (1ll << 61);
	for(int i = 0; i <= 60; i++){
		for(int j = 0; j <= 60; j++){
			for(int k = 0; k <= 60; k++){
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = 0;
    for(int i = 1; i <= 60; i++){
    	for(int j = 0; j <= 60; j++){
    		for(int k = 0; k <= 60; k++){
    			dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
    			if(j >= i)dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - i][k] + (1ll << i));
    			if(k >= i)dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - i] + (1ll << i));
    		}
    	}
    }
}
void solve(){
    int x, y; cin >> x >> y;
    if(x == y){
    	cout << 0 << '\n';
    	return ;
    }
    int ans = (1ll << 60);
    auto run = [&](int xx, int yy) -> void{
    	int res1 = x / (1ll << xx);
    	int res2 = y / (1ll << yy);
    	if(res1 != res2)return ;
    	ans = min(ans, dp[60][xx][yy]);
    };
    for(int i = 0; i <= 60; i++){
    	for(int j = 0; j <= 60; j++){
    		run(i, j);
    	}
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    init();
    cin >> t;
    while(t--)solve();
    return 0;
}
/*

*/