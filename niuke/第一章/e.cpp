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
int day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve(){
	int n, m; cin >> n >> m;
	int ans = 0;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= day[i]; j++) {
			int x = j % 10 * 1000 + j / 10 * 100 + i % 10 * 10 + i / 10;
			int y = x * 10000 + i * 100 + j;
			if (y >= n && y <= m) ans++;
		}
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