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
    vector<pair<int, int>> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
    	auto [x, y] = a[i];
    	int l = 1, r = i - 1;
    	int pos = 0;
    	while(l <= r){
    		int mid = (l + r) >> 1;
    		if(x - a[mid].first > y){
    			pos = mid;
    			l = mid + 1;
    		}else r = mid - 1;
    	}
    	dp[i] = dp[pos] + 1;
    }
    int ans = *max_element(dp.begin(), dp.end());
    cout << n - ans << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}