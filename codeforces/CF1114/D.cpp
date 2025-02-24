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
    vector<int> p;
	for(int i = 1; i <= n; i++){
		p.push_back(a[i]);
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());
	auto get = [&](int x) -> int{
		return lower_bound(p.begin(), p.end(), x) - p.begin() + 1;
	};
	for(int i = 1; i <=n ; i++){
		a[i] = get(a[i]);
	}
    vector dp(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
    	if(a[i] == a[i - 1]){
    		for(int j = 1; j <= n; j++){
    			dp[i][j] = dp[i - 1][j];
    		}
    	}else{
    		for(int j = 1; j <= n; j++){
    			dp[i][j] = dp[i - 1][j] + (a[i] != j);
    		}
    	}
    }
    int ans = n;
    for(int i = 1; i <= n; i++){
    	ans = min(ans, dp[n][i]);
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