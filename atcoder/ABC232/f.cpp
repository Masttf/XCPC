#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x) & -(x))
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
    int X, Y; cin >> X >> Y;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> dp(1 << n, Max);
	dp[0] = 0;
	for(int i = 1; i < (1 << n); i++){
		int cnt = 0;
		int temp = i;
		while(temp){
			cnt++;
			temp -= lowbit(temp);
		}
		for(int j = 0; j < n; j++){
			if(i >> j & 1){
				int d = i ^ (1 << j);
				int num = 0;
				for(int k = j + 1; k < n; k++){
					if(d >> k & 1)num++;
				}
				//已经定好顺序
				dp[i] = min(dp[i], dp[d] + abs(a[j] - b[cnt - 1]) * X + abs(j + num - (cnt - 1)) * Y);
			}
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
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