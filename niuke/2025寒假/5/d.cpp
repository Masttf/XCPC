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
constexpr int inf = 1e18;
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector pre(2, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j <= 1; j++){
    		pre[j][i] += pre[j][i - 1];
    	}
    	pre[s[i] - '0'][i]++;
    }
    int ans = 0;
    vector dp(2, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = i; j <= n; j += i){
    		dp[0][j] = dp[1][j] = inf;
    	}
    	dp[0][n] = dp[1][n] = inf;
    	auto run = [&](int x, int y) -> void{
    		int cnt0 = pre[0][y] - pre[0][x];
    		int cnt1 = pre[1][y] - pre[1][x];
    		
    		// dbg(x, y, cnt0, cnt1);
			if(cnt0 == 0 || cnt1 == 0){
				if(x == 0){
					dp[0][y] = dp[1][y] = 1;
				}else{
					dp[0][y] = min({dp[0][y], dp[1][x] + 1, dp[0][x]});
					dp[1][y] = min({dp[1][y], dp[1][x], dp[0][x] + 1});
				}
			}else{
				if(x == 0){
					dp[0][y] = dp[1][y] = 2;
				}else{
					dp[0][y] = min({dp[0][y], dp[1][x] + 1, dp[0][x] + 2});
					dp[1][y] = min({dp[1][y], dp[1][x] + 2, dp[0][x] + 1});
				}
			}
    	};
    	
    	for(int j = i; j <= n; j += i){
    		int last = j - i;
    		run(last, j);
    		// dbg(last, j, dp[0][j], dp[1][j]);
    	}
    	if(n % i != 0){
    		int last = n / i * i;
    		run(last, n);
    	}
    	// dbg(min(dp[0][n], dp[1][n]));
    	ans ^= min(dp[0][n], dp[1][n]);
    }
    cout << ans << '\n';
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
/*
nlog 调和级数
这里的 01长度一定是min的个数
假设0是少的
如果上一段以1 / 0 结尾
101010101
01010101
直接dp是不是即可
000000000001111111
*/