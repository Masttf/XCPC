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
    vector a (n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		cin >> a[i][j];
    	}
    }
    map<int, int> mx;
    map<int, int> my;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		mx[i + j] += a[i][j];
    		my[i - j] += a[i][j];
    	}
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		ans = max(ans, mx[i + j] + my[i - j] - a[i][j]);
    	}
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