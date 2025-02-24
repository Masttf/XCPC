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
    int ans = 0;
	vector<pair<int, int>> stk;
	for(int i = 1; i <= n; i++){
		int cnt = 1;
		while(!stk.empty() && stk.back().first <= a[i]){
			ans += stk.back().second;
			if(stk.back().first == a[i])cnt += stk.back().second;
			stk.pop_back();
		}
		stk.push_back({a[i], cnt});
	}
	stk.clear();
	for(int i = n; i >= 1; i--){
		while(!stk.empty() && stk.back().first < a[i]){
			ans += stk.back().second;
			// dbg(a[i], stk.back());
			stk.pop_back();
		}
		stk.push_back({a[i], 1});
	}
	cout << ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}