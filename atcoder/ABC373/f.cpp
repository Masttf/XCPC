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
    int n, m; cin >> n >> m;
    vector<vector<int>> a(m + 1);
    for(int i = 1; i <= n; i++){
    	int w, v; cin >> w >> v;
    	if(w <= m)a[w].push_back(v);
    }
    vector f(m + 1, vector<int>(m + 1));
    for(int i = 1; i <= m; i++){
    	if(a[i].empty())continue;
    	priority_queue<array<int, 3>>q;
    	for(auto x : a[i]){
    		q.push({x - 1, 2, x});
    	}
    	for(int j = 1; i * j <= m; j++){
    		auto [val, cnt, x] = q.top();
    		q.pop();
    		f[i][j] = f[i][j - 1] + val;
    		q.push({x - 2 * cnt + 1, cnt + 1, x});
    	}
    }
    vector dp(m + 1, vector<int>(m + 1));
    for(int i = 1; i <= m; i++){
    	for(int j = 0; j <= m; j++){
    		dp[i][j] = dp[i - 1][j];
    	}
    	for(int j = i; j <= m; j++){
    		for(int k = 1; i * k <= j; k++){
    			dp[i][j] = max(dp[i][j], dp[i - 1][j - i * k] + f[i][k]);
    		}
    	}
    }
    cout << dp[m][m] << '\n';
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