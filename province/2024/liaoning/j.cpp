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
    int a, b, c; cin >> a >> b >> c;
    vector<pair<int, int>> A(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> A[i].first >> A[i].second;
    }
    int d; cin >> d;
    int ans = 0;
    for(int i = 1; i <= n; i++){
    	auto [x, y] = A[i];
    	int k = 0;
    	if(x + y < c)k++;
    	x = min(a, x + d);
    	if(x + y >= c)ans += k;
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