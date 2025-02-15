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
	vector a(2 * n + 1, vector<int>(2 * n + 1));
	for(int i = 1; i <= 2 * n; i++){
		for(int j = 1; j <= 2 * n; j++) {
			cin >> a[i][j];
		}
	}
	int sum = 0;
	for(int i = n + 1; i <= 2 * n; i++){
		for(int j = n + 1; j <= 2 * n; j++){
			sum += a[i][j];
		}
	}
	sum += min({a[1][n + 1], a[1][2 * n], a[2 * n][1], a[2 * n][n], a[n + 1][1], a[n][2 * n], a[n + 1][n], a[n][n + 1]});
	cout << sum << '\n';
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