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
    int n, q; cin >> n >> q;
    vector a(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		cin >> a[i][j];
    	}
    }
    vector pre1(n + 1, vector<int>(n + 1));
    vector pre2(n + 1, vector<int>(n + 1));
    vector pre3(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		pre1[i][j] = pre1[i - 1][j] + pre1[i][j - 1] - pre1[i - 1][j - 1] + a[i][j];
    		pre2[i][j] = pre2[i - 1][j] + pre2[i][j - 1] - pre2[i - 1][j - 1] + a[i][j] * j;
    		pre3[i][j] = pre3[i - 1][j] + pre3[i][j - 1] - pre3[i - 1][j - 1] + a[i][j] * i;
    	}
    }
    auto get = [&](vector<vector<int>> &pre, int x1, int y1, int x2, int y2) -> int{
		return pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
	};
	// dbg(get(pre2, 1, 1, 1, 4));
	// dbg(get(pre2, 2, 1, 2, 4));
	// dbg(get(pre2, 3, 1, 3, 4));
	// dbg(get(pre2, 4, 1, 4, 4));
    for(int i = 1; i <= q; i++){
    	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    	int len = (y2 - y1 + 1);
    	int s = get(pre1, x1, y1, x2, y2);
    	int ans = get(pre2, x1, y1, x2, y2) - s * (y1 - 1) + len * (get(pre3, x1, y1, x2, y2) - s * x1);
    	cout << ans << ' ';
    }
    cout << '\n';
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