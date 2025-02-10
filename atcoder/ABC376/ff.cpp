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
    int n, q; cin >> n >> q;
    vector<pair<int, int>> Q(q + 1);
    for(int i = 1; i <= q; i++){
    	char ty; cin >> ty;
    	int x; cin >> x;
    	x--;
    	if(ty == 'L')Q[i] = {0, x};
    	else Q[i] = {1, x};
    }
    Q[0] = {0, 0};
    vector dp(q + 1, vector<int>(n, Max));
    dp[0][1] = 0;
    for(int i = 2, j = 1; i < n; i++, j++){
    	dp[0][i] = j;
    }
    auto get = [&](int x1, int y1, int x2, int y2) -> int{
    	if(x1 == y1 || x2 == y2)return Max;
    	int res = Max;
    	if(x2 > y2){
    		swap(x2, y2);
    		swap(x1, y1);
    	}
    	if(x1 < y1)res = min(res, (x2 - x1 + n) % n + (y2 - y1 + n) % n);
    	if(x1 > y1)res = min(res, (x2 - x1 + n) % n + (y1 - y2 + n) % n);
    	if(x1 < y1)res = min(res, (x1 - x2 + n) % n + (y1 - y2 + n) % n);
    	// if(x1 > y1)res = min(res, ())

    	return res;
    };
    // dbg(get(0, 1, 0, 3));
    for(int i = 1; i <= q; i++){
    	auto [ty, x] = Q[i];
    	auto [tty, xx] = Q[i - 1];
    	int lx, ly, llx, lly;
    	if(ty == 0)lx = x;
    	else ly = x;
    	if(tty == 0)llx = xx;
    	else lly = xx;
    	// if(ty == tty){
    	// 	for(int j = 0; j < n; j++){
    	// 		if(ty == 0)ly = j;
    	// 		else lx = j;
    	// 		if(tty == 0)lly = j;
    	// 		else llx = j;
    	// 		dp[i][j] = min(dp[i][j], dp[i - 1][j] + get(lx, ly, llx, lly));
    	// 	}
    	// 	if(ty == 0){
    	// 		ly = (x + n - 1) % n;
    	// 		for(int j = 0; j < n; j++){
    	// 			if(tty == 0)lly = j;
    	// 			else llx = j;
    	// 			dp[i][ly] = min(dp[i][ly], dp[i - 1][j] + get(lx, ly, llx, lly));
    	// 		}
    	// 		ly = (x + 1) % n;
    	// 		for(int j = 0; j < n; j++){
    	// 			if(tty == 0)lly = j;
    	// 			else llx = j;
    	// 			dp[i][ly] = min(dp[i][ly], dp[i - 1][j] + get(lx, ly, llx, lly));
    	// 		}
    	// 	}else{
    	// 		lx = (x + n - 1) % n;
    	// 		for(int j = 0; j < n; j++){
    	// 			if(tty == 0)lly = j;
    	// 			else llx = j;
    	// 			dp[i][ly] = min(dp[i][ly], dp[i - 1][j] + get(lx, ly, llx, lly));
    	// 		}
    	// 		lx = (x + 1) % n;
    	// 		for(int j = 0; j < n; j++){
    	// 			if(tty == 0)lly = j;
    	// 			else llx = j;
    	// 			dp[i][lx] = min(dp[i][lx], dp[i - 1][j] + get(lx, ly, llx, lly));
    	// 		}
    	// 	}
    	// }else{
    	// 	dp[i][xx] = dp[i - 1][x];
    	// 	// dbg(i, dp[i][xx]);
    	// 	if(ty == 0)llx = x;
    	// 	else lly = x;
    	// 	for(int j = 0; j < n; j++){
    	// 		if(ty == 0)ly = j;
    	// 		else lx = j;
    	// 		dp[i][j] = min(dp[i][j], dp[i][xx] + get(lx, ly, llx, lly));
    	// 	}
    	// }
    	// dbg(i);
    	// for(int j = 0; j < n; j++){
    	// 	dbg(j, dp[i][j]);
    	// }
    	for(int j = 0; j < n; j++){
    		if(ty == 0)ly = j;
            else lx = j;
    		for(int k = 0; k < n; k++){
    			if(tty == 0)lly = k;
    			else llx = k;
    			// dbg(lx, ly, llx, lly);
    			dp[i][j] = min(dp[i][j], dp[i - 1][k] + get(lx, ly, llx, lly));
    		}
    		dbg(j, dp[i][j]);
    	}
    }
    int ans = Max;
    for(int i = 0; i < n; i++){
    	ans = min(ans, dp[q][i]);
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