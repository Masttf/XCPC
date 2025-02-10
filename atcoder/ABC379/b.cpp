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
    int n, k; cin >> n >> k;
    string s; cin >> s;
   	vector<int> pre(n + 1);
   	for(int i = 0; i < n; i++){
   		pre[i + 1] = pre[i];
   		if(s[i] == 'O')pre[i + 1]++;
   	}
   	vector<int> dp(n + 1);
   	for(int i = k; i <= n; i++){
   		dp[i] = dp[i - 1];
   		if(pre[i] - pre[i - k] == k){
   			dp[i] = max(dp[i], dp[i - k] + 1);
   		}
   	}
   	int ans = *max_element(dp.begin() + 1, dp.end());
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