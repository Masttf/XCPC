#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do{ \
	cout << #x << " -> "; \
	err(x); \
}while(0)
void err(){
	cout << endl;
}
template<class T, class ...Ts>
void err(T arg, Ts ...args){
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
constexpr int maxn = 16, mx = (1 << 17), inf = 1e9;
int g[maxn][maxn];
int val[5];
int dp[mx][maxn];
void init(){
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			g[i][j] = inf;
		}
	}
	for(int i = 0; i < 16; i++){
		//a0
		for(int j = 0; j < 4; j++){
			int v = i ^ (1 << j);
			g[i][v] = val[0];
		}
		// a1
		int v = i ^ 3;
		g[i][v] = val[1];
		v = i ^ (12);
		g[i][v] = val[1];
		// a2
		v = i ^ 5;
		g[i][v] = val[2];
		v = i ^ (10);
		g[i][v] = val[2];
		v = i ^ (15);
		g[i][v] = val[3];
	}
	// for(int i = 0; i < maxn; i++){
	// 	for(int j = 0; j < maxn; j++){
	// 		cout << g[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << endl;
	for(int k = 0; k < 16; k++){
		for(int i = 0; i < 16; i++){
			for(int j = 0; j < 16; j++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	// for(int i = 0; i < maxn; i++){
	// 	for(int j = 0; j < maxn; j++){
	// 		cout << g[i][j] << ' ';
	// 	}
	// 	cout << '\n';
	// }
	// cout << endl;
	for(int i = 0; i < mx; i++){
		for(int j = 0; j < maxn; j++){
			dp[i][j] = inf;
		}
	}
	for(int i = 0; i < maxn; i++){
		dp[1 << i][i] = g[15][i];
	}
	for(int i = 0; i < mx; i++){
		for(int j = 0; j < maxn; j++){
			if(i >> j & 1){
				for(int k = 0; k < maxn; k++){
					if((i ^ (1 << j)) >> k & 1){
						dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + g[k][j]);
					}
				}
			}
			// dbg(i, dp[i])
		}
	}
	return ;
}
void solve(){
	int n; cin >> n;
	vector<int> a(n + 1);
	int tot = 0;
	for(int i = 1; i <= n; i++){
		string x, y; cin >> x >> y;
		int res = 0;
		if(x[0] == '1')res += 1 << 0;
		if(x[1] == '1')res += 1 << 1;
		if(y[0] == '1')res += 1 << 2;
		if(y[1] == '1')res += 1 << 3;
		a[i] = res;
		tot |= 1 << a[i];
	}
	int ans = inf;
	for(int i = 1; i <= n; i++){
		ans = min(ans, dp[tot][a[i]]);
	}
	cout << ans << '\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for(int i = 0; i < 4; i++) cin >> val[i];
	init();
	while(t--)solve();
	return 0;
}