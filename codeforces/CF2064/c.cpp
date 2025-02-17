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
    int n; cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(n + 1);
	for(int i = 1; i <= n; i++){
		if(a[i] < 0)b[i] = 0;
		else b[i] = 1;
	}
	vector pre(2, vector<int>(n + 1));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 1; j++){
			pre[j][i] += pre[j][i - 1];
		}
		pre[b[i]][i] += abs(a[i]);
	}
	int ans = 0;
	// dbg(ans);
	ans = pre[0][n];
    for(int i = 1; i <= n; i++){
    	int res = pre[1][i] + pre[0][n] - pre[0][i];
    	ans = max(ans, res);
    }
    cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
正保留右边

负保留左边

正正....负负
*/