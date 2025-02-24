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
constexpr int inf = 1e18, maxn = 3000;
void solve(){
	string _a, _b; cin >> _a >> _b;
	int n = _a.size(), m = _b.size();
	vector<int> a(n + 1), b(m + 1);
	for(int i = 1; i <= n; i++){
		if(_a[i - 1] == 'A')a[i] = 1;
		else if(_a[i - 1] == 'T')a[i] = 2;
		else if(_a[i - 1] == 'G')a[i] = 3;
		else a[i] = 4;
		// cout << a[i] << " \n"[i == n];
	}
	for(int i = 1; i <= m; i++){
		if(_b[i - 1] == 'A')b[i] = 1;
		else if(_b[i - 1] == 'T')b[i] = 2;
		else if(_b[i - 1] == 'G')b[i] = 3;
		else b[i] = 4;
		// cout << b[i] << " \n"[i == m];
	}
	vector<array<int, 5>>val(5);
	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 4; j++){
			cin >> val[i][j];
		}
	}
	int A, B; cin >> B >> A;
	vector dp(n + 1, vector(m + 1, vector<int>(3, -inf)));
	auto ndp = dp;
	ndp[0][0][0] = 0;
	int ans = -inf;
	int cnt = 0;
	for(int len = 0; len < n + m; len++){
		swap(dp, ndp);
		for(int i = max(0ll, len - m); i <= min(n, len); i++){
			for(int j = max(0ll, len - n); j <= min(m, len); j++){
				cnt++;
				ndp[i][j][0] = -inf;
				ndp[i][j][1] = -inf;
				ndp[i][j][2] = -inf;
			}
		}
		for(int i = max(0ll, len - m); i <= min(n, len); i++){
			for(int j = max(0ll, len - n); j <= min(m, len); j++){
				// dbg(len, i, j);
				//00
				if(i + 1 <= n && j + 1 <= m)ndp[i + 1][j + 1][0] = max(ndp[i + 1][j + 1][0], dp[i][j][0] + val[a[i + 1]][b[j + 1]]);
				if(i + 1 <= n)ndp[i + 1][j][1] = max(ndp[i + 1][j][1], dp[i][j][0] - B);
				if(j + 1 <= m)ndp[i][j + 1][2] = max(ndp[i][j + 1][2], dp[i][j][0] - B);
				// 01
				if(i + 1 <= n && j + 1 <= m)ndp[i + 1][j + 1][0] = max(ndp[i + 1][j + 1][0], dp[i][j][1] + val[a[i + 1]][b[j + 1]]);
				if(i + 1 <= n)ndp[i + 1][j][1] = max(ndp[i + 1][j][1], dp[i][j][1] - A);
				if(j + 1 <= m)ndp[i][j + 1][2] = max(ndp[i][j + 1][2], dp[i][j][1] - B);
				// 10
				if(i + 1 <= n && j + 1 <= m)ndp[i + 1][j + 1][0] = max(ndp[i + 1][j + 1][0], dp[i][j][2] + val[a[i + 1]][b[j + 1]]);
				if(i + 1 <= n)ndp[i + 1][j][1] = max(ndp[i + 1][j][1], dp[i][j][2] - B);
				if(j + 1 <= m)ndp[i][j + 1][2] = max(ndp[i][j + 1][2], dp[i][j][2] - A);
				// dbg(len, i, j);
				// for(int s = 0; s <= 2; s++){
				// 	cout << dp[len][i][j][s] << endl;
				// }
			}
		}
		if(len >= max(n, m)){
			for(int s = 0; s <= 2; s++){
				ans = max(ans, ndp[n][m][s]);
				ans = max(ans, dp[n][m][s]);
			}
		}
	}
	
	cout << ans << '\n';
	cout << cnt << '\n';
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