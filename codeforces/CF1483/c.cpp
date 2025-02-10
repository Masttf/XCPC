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
    vector<int> h(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    multiset<int, greater<int>> s;
	vector<int> dp(n + 1);
	vector<pair<int, int>> stk;
	for(int i = 1; i <= n; i++){
		int val = dp[i - 1];
		// dbg(val);
		while(!stk.empty() && h[i] < h[stk.back().first]){
			auto[j, v] = stk.back();
			val = max(val, v);
			auto it = s.find(v + b[j]);
			s.erase(it);
			stk.pop_back();
		}
		stk.push_back({i, val});
		// dbg(val, i);
		s.insert(b[i] + val);
		dp[i] = *s.begin();
		// dbg(i, dp[i]);
	}
	cout << dp[n] << '\n';
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