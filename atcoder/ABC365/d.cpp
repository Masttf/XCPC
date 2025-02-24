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
constexpr int Max = 1e18;
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    vector<int> res(n + 1);
    for(int i = 1; i <= n; i++){
    	if(s[i] == 'R')res[i] = 0;
    	else if(s[i] == 'S')res[i] = 1;
    	else res[i] = 2; 
    }
    vector dp(n + 1, vector<int>(3));
    for(int i = 1; i <= n; i++){
    	int now = res[i];
    	dp[i][(now + 1) % 3] = -Max;
    	dp[i][now] = max(dp[i - 1][(now + 2) % 3], dp[i - 1][(now + 1) % 3]);
    	dp[i][(now + 2) % 3] = max(dp[i - 1][now], dp[i - 1][(now + 1) % 3]) + 1;
    	//dbg(dp[i][0], dp[i][1], dp[i][2]);
    }
    int mx = *max_element(dp[n].begin(), dp[n].end());
    cout << mx << '\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; // cin >> t;
    while(t--)solve();
    return 0;
}